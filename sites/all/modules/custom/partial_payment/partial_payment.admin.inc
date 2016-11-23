<?php

/**
 * @file
 * Code for icici payment integration using Drupal Commerce.
 */
function partial_payment_scheduler_order_verification() {
    /* $query = db_select('commerce_payment_transaction', 'cpt');
      $query->fields('cpt', array('order_id', 'transaction_id'));
      $query->condition('cpt.payment_method', array('commerce_icici_payment', 'partial_payment_online'), 'IN');
      $query->condition('cpt.status', COMMERCE_PAYMENT_STATUS_PENDING, '=');
      $query->orderBy('cpt.created', 'DESC');
      $query->range(0, 5);
      $result = $query->execute()->fetchAll(); */
    $transaction = db_select('online_transaction', 't');
    $transaction->fields('t', array('transaction_id', 'pay_txn'));
    $transaction->condition('verification_status', '');
    $transaction->condition('created', (REQUEST_TIME - 300), '<');
    $transaction->range(0, 10);
    $result = $transaction->execute()->fetchAll();
    watchdog("online_payment_verify", '<pre>%array</pre>', array('%array' => print_r(array('TRUE', $result), true)));
    if (!empty($result)) {
        include("Sfa/Merchant.php");
        include("Sfa/PGResponse.php");
        include("Sfa/PGSearchResponse.php");
        include("Sfa/PostLibPHP.php");

        $oPostLibphp = new PostLibPHP();
        $oMerchant = new Merchant();
        $oPGResp = new PGResponse();
        $oPGSearchResp = new PGSearchResponse();

        foreach ($result as $key => $val) {
            $oMerchant->setMerchantOnlineInquiry(MERCHANT_TRANSACTION_ID, $val->order_id);
            $oPGSearchResp = $oPostLibphp->postStatusInq($oMerchant);
            $PGRespObj = $oPGSearchResp->getPGResponseObjects();
            if ($PGRespObj[0]->mstrRespCode == 0 && $PGRespObj[0]->mstrRespMessage == 'Transaction Successful') {
                partial_payment_update_online_transaction($PGRespObj[0]->mstrTxnId, COMMERCE_PAYMENT_STATUS_SUCCESS);
            } else {
                partial_payment_update_online_transaction($PGRespObj[0]->mstrTxnId, COMMERCE_PAYMENT_STATUS_FAILURE);
                $data['verification_response'] = serialize($PGRespObj);
                $data['status'] = 2;
                if ($PGRespObj[0]->mstrRespCode == 0 && $message == 'Transaction Successful') {
                    partial_payment_update_online_transaction($PGRespObj[0]->mstrTxnId, COMMERCE_PAYMENT_STATUS_SUCCESS);
                } else {
                    $data['verification_response'] = serialize($PGRespObj);
                    $data['status'] = 2;
                }
            }
        }
        $data['application_id'] = $PGRespObj;
        $data['verification_response'] = $PGRespObj;
        $insert = database_entry_for_icici_transaction('update', $data);
        if ($PGRespObj[0]->mstrRespCode == 0) {
            partial_payment_update_online_transaction($val->transaction_id, COMMERCE_PAYMENT_STATUS_SUCCESS);
        } else {
            partial_payment_update_online_transaction($val->transaction_id, COMMERCE_PAYMENT_STATUS_FAILURE);
        }
    }
    return 'Verification complete';
}

/**
 * Implements hook_transaction()
 */
function partial_payment_update_online_transaction($transaction_id, $status) {
    $transaction = commerce_payment_transaction_load($transaction_id);
    $transaction->remote_status = $status;
    $transaction->status = $status;
    commerce_payment_transaction_save($transaction);
}

/**
 * icici transaction
 */
function partial_payment_refund($txn_id, $refund_amount) {

    $result = partial_payment_refund_initiate($txn_id, $refund_amount);
    if ($result['status']) {
        drupal_set_message($result['message']);
    } else {
        drupal_set_message($result['message']);
    }
    drupal_goto($_GET['destination']);
}

function partial_payment_refund_initiate($txn_id, $refund_amount) {
    include("Sfa/Merchant.php");
    include("Sfa/PGResponse.php");
    include("Sfa/PostLibPHP.php");
    $oPostLibphp = new PostLibPHP();
    $oMerchant = new Merchant();
    $oPGResp = new PGResponse();
    $transaction = db_select('online_transaction', 'o')
                    ->fields('o', array('transaction_id', 'response'))
                    ->condition('transaction_id', $txn_id)
                    ->execute()->fetchAll();
    $pg_transaction = unserialize($transaction[0]->response);
    $pg_transaction_id = $pg_transaction['ePGTxnID'];
    $auth_code = $pg_transaction['AuthIdCode'];
    $rrn = $pg_transaction['RRN'];
    if (isset($refund_id)) {
        $v = substr(strrchr($txn_id, "_"), 2) + 1;
        $refund_id = $txn_id . '_R' . $v;
    } else {
        $refund_id = $txn_id . '_R';
    }
    $oMerchant->setMerchantRelatedTxnDetails(MERCHANT_TRANSACTION_ID, "", "", $refund_id, $pg_transaction_id, $rrn, $auth_code, "", "", "INR", "req.Refund", $refund_amount, "", "Ext1", "Ext2", "Ext3", "Ext4", "Ext5");
    $oPgResp = $oPostLibphp->postRelatedTxn($oMerchant);
    $data['application_id'] = $transaction[0]->application_id;
    $data['transaction_id'] = $refund_id;
    $data['amount'] = $refund_amount;
    $data['response'] = serialize($oPgResp);
    $data['status'] = 1;
    $data['created'] = REQUEST_TIME;
    $insert = database_entry_for_icici_transaction('insert', $data);
    if ($oPgResp->mstrRespMessage == 'Transaction Successful') {
        $value['status'] = TRUE;
        $value['message'] = $oPgResp->mstrRespMessage;
        return $value;
    } else {
        $value['status'] = FALSE;
        $value['message'] = $oPgResp->mstrRespMessage;
        return $value;
    }
}

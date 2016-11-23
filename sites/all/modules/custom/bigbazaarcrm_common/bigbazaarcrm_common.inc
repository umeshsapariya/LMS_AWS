<?php

function bigbazaar_oxigen_leads_form($form, &$form_state) {
  $form['type'] = array(
    '#title' => t('Type of upload : Please select an upload type'),
    '#type' => 'select',
    '#options' => array('' => 'NONE', 'leads' => 'leads', 'payment' => 'payment', 'franchisee' => 'franchisee'),
    //'#required' => TRUE,
    //'#attributes' => array('disabled'),
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'template_change',
      'wrapper' => 'template',
    ),
  );
  $temp = isset($form_state['values']['type']) ? $form_state['values']['type'] : '';
  if (!empty($form_state['values']['type'])) {
    $markup = l(t(' Click Here'), drupal_get_path('module', 'bigbazaarcrm_common') . '/' . $temp . '.csv') . ' To download Template<br />';
  }
  else {
    $markup = '';
  }
  $form['template'] = array(
    '#prefix' => '<div id="template">',
    '#suffix' => '</div>',
    '#markup' => $markup,
  );
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['instructions'] = array(
    '#title' => 'Note',
    '#markup' => 'Enter the details'
  );
  $form['file'] = array(
    '#type' => 'file',
    '#title' => t('Choose a CSV file'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Upload'),
    '#validate' => array('bigbazaar_oxigen_leads_validate'),
  );
  return $form;
}

function template_change($form, &$form_state) {
  return $form['template'];
}

/**
 * hook_form_validate
 */
function bigbazaar_oxigen_leads_validate($form, &$form_state) {

  if (empty($form_state['values']['type'])) {
    form_set_error('type', 'Please select a template type');
    return;
  }

  $validators = array(
    'file_validate_extensions' => array('csv CSV'),
  );
  if ($file = file_save_upload('file', $validators, 'public://')) {
    $csv_dir = 'public://csvfile';
    $directory_exists = file_prepare_directory($csv_dir, FILE_CREATE_DIRECTORY);
    if ($directory_exists) {
      $destination = $csv_dir . '/';
      if ($file_moved = file_move($file, $destination)) {
        $form_state['values']['csvupload'] = $file_moved;
      }
      else {
        form_set_error('file', t('Unable to copy upload file to !dest', array('!dest' => $destination)));
      }
    }
    if (isset($form_state['values']['csvupload'])) {
      if ($handle = fopen($form_state['values']['csvupload']->uri, 'r')) {
        $template = $form_state['values']['type'];
        if ($form_state['values']['type'] == 'leads') {
          $line = fgetcsv($handle);
          if ($line[0] != 'VENDOR NAME' || $line[1] != 'Oxygen Agent Code' || $line[2] != 'Alliance' || $line[3] != 'Address 1' || $line[4] != 'Address 2' || $line[5] != 'POSTAL' || $line[6] != 'CITY NAME' || $line[7] != 'COUNTRY' || $line[8] != 'REGION / State' || $line[9] != 'MOBILE NUMBER' || $line[10] != 'EMAIL ADDRESS' || $line[11] != 'PAN No' || $line[12] != 'Service Tax No' || $line[13] != 'Remark' || $line[14] != 'Application Status') {
            form_set_error('file', 'Template Mismatch');
          }
        }
        elseif ($form_state['values']['type'] == 'payment') {
          $line = fgetcsv($handle);
          if ($line[0] != 'Agent Id' || $line[1] != 'Payment Status flag') {
            form_set_error('file', 'Template Mismatch');
          }
        }
        elseif ($form_state['values']['type'] == 'franchisee') {
          $line = fgetcsv($handle);
          if ($line[0] != 'Agent Id' || $line[1] != 'Franchisee Code') {
            form_set_error('file', 'Template Mismatch');
          }
        }
        fclose($handle);
      }
      else {
        form_set_error('file', t('Unable to read uploaded file !filepath', array('!filepath' => $form_state['values']['csvupload']->uri)));
      }
    }
  }
  elseif($file === NULL){
    form_set_error('file', 'Please select a file to upload');
  }
}

/**
 * hook_form_submit
 */
function bigbazaar_oxigen_leads_form_submit($form, &$form_state) {
  $file = $form_state['values']['csvupload'];
  if ($form_state['values']['type'] == 'leads') {
    $batch = array(
      'title' => t('Leads Insert'),
      'operations' => array(
        array('lead_process_batch', array($file)),
      ),
      'finished' => 'lead_batch_finished',
      'title' => t('Processing Batch'),
      'init_message' => t('Batch is starting.'),
      'progress_message' => t('Processing...'),
      'error_message' => t('Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'bigbazaarcrm_common') . '/bigbazaarcrm_common.inc',
    );
  }
  elseif ($form_state['values']['type'] == 'payment') {
    $batch = array(
      'title' => t('Payment status update'),
      'operations' => array(
        array('payment_status_batch', array($file)),
      ),
      'finished' => 'lead_batch_finished',
      'title' => t('Processing Batch'),
      'init_message' => t('Batch is starting.'),
      'progress_message' => t('Processing...'),
      'error_message' => t('Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'bigbazaarcrm_common') . '/bigbazaarcrm_common.inc',
    );
  }
  elseif ($form_state['values']['type'] == 'franchisee') {
    $batch = array(
      'title' => t('Payment status update'),
      'operations' => array(
        array('franchisee_batch', array($file)),
      ),
      'finished' => 'lead_batch_finished',
      'title' => t('Processing Batch'),
      'init_message' => t('Batch is starting.'),
      'progress_message' => t('Processing...'),
      'error_message' => t('Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'bigbazaarcrm_common') . '/bigbazaarcrm_common.inc',
    );
  }
  batch_set($batch);
}

/**
 * Batch process function
 * @global type $base_url
 * @global type $user
 * @param type $url uri of the file
 * @param type $context default
 */
function lead_process_batch($file_ob, &$context) {
  global $base_url;
  global $user;
  $fp = file($file_ob->uri);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 1;
    $context['sandbox']['max'] = count($fp) - 1;
    $context['results']['success'] = 0;
    $context['results']['error'] = 0;
  }
  $file = new SplFileObject($file_ob->uri);
  $header = $file->current(); //Always gets the header.
  $progress = $context['sandbox']['progress'];
  $max = $context['sandbox']['max'];
  
  if($max == 0){
    drupal_set_message('Please enter data in sheet', 'error');
  }
  for ($i = 0; ($i < 100) && (($i + $progress) <= $max); $i++) { // condition to process 100 rows at a time.
    $file->seek($i + $progress);
    $data = str_getcsv($file->current());
    $head = explode(',', $header);
    
    $error = FALSE;
    foreach ($data as $key => $value) {
      $data[$key] = trim($value);
      if ((is_null($data[$key]) || $data[$key] === '') && $head[$key] != 'PAN No' && $head[$key] != 'Service Tax No' && trim($head[$key]) != 'Application Status') {

        //drupal_set_message($head[$key] . ' is empty at row ' . ($i + $progress), 'error');
        $context['results']['error'] ++;
        //continue 2;
        $error = TRUE;
        $context['results']['error_array'][$i + $progress] .= $head[$key] . ' is empty,';
      }
    }
    // to get first and second name from vendor name.
    $name = trim($data[0]);
    $name = explode(' ', $data[0]);
    //if (count($name) == 2) {
    $first_name = $name[0];
    $end_name = implode(' ', array_slice($name, 1));
    $last_name = $end_name;
    /* }
      elseif (count($name) == 3) {
      $first_name = $name[0] . " " . $name[1];
      $last_name = $name[2];
      }
      else{
      $first_name = $name[0];
      } */
    $oxigen_agent_code = $data[1];
    $alliance_name = $data[2];
    $address_1 = $data[3];
    $address_2 = $data[4];
    $pincode = $data[5];
    $city_name = $data[6];
    $country = $data[7];
    $region_state = $data[8];
    $mobile_no = $data[9];
    $email = $data[10];
    $pan_no = $data[11];
    $service_tax = $data[12];
    $remark = $data[13];
    if (!empty($data[14])) {
      $status = $data[14];
    }
    else {
      $status = 'Lead Generated';
    }
    $pincode_status = bigbazaarcrm_application_get_pincode_status($pincode);
    
    $mobile_check = preg_match('/^([0-9]{10})$/', $mobile_no);
    $pincode_check = preg_match('/^([0-9]{6})$/', $pincode);
    $email_check = preg_match("/^[_\.0-9a-zA-Z-]+@([0-9a-zA-Z]+\.)+[a-zA-Z]{2,6}$/i", $email);
    $mobile_status = bigbazaarcrm_application_check_mobile_exists($mobile_no);
    $agent_id_check = check_application_no_exists($oxigen_agent_code);
    $tid = get_tid_from_term_name($alliance_name);
    $sid = bigbazaarcrm_application_get_sid_from_state_name('(' . $status . ')');
    $error_string = "";
    if (empty($sid)) {
      $error_string .= 'Please enter valid Status name at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid status name,';
    }
    if (empty($tid)) {
      $error_string .= 'Please enter valid alliance name at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid alliance name,';
    }
    if (!$pincode_check) {
      $error_string .= 'Please enter a valid pincode at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid pincode,';
    }
    if (!$mobile_check) {
      $error_string .= 'Please enter a valid 10 digit mobile no at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid mobile number,';
    }
    if ($mobile_status) {
      $error_string .= 'The mobile number already exists at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Mobile number already exists,';
    }
    if (!$email_check) {
      $error_string .= 'Please enter a valid email address (eg:bbd@gmail.com) at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid Email address,';
    }
    if (!empty($agent_id_check)) {
      ##############################################################################
      //Check if agent id already exists 
      ##############################################################################
      $error_string .= 'Agent id already exist at row ' . ($i + $progress) . '<br />';
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Agent id already exists,';
    }
    if (!$error) {
      $fs['values']['field_first_name'][LANGUAGE_NONE][0]['value'] = $first_name;
      $fs['values']['field_last_name'][LANGUAGE_NONE][0]['value'] = $last_name;
      $fs['values']['field_application_number'][LANGUAGE_NONE][0]['value'] = $oxigen_agent_code;
      $fs['values']['alliance_name'][LANGUAGE_NONE][0]['value'] = $tid;
      $fs['values']['field_address_1'][LANGUAGE_NONE][0]['value'] = $address_1;
      $fs['values']['field_address_2'][LANGUAGE_NONE][0]['value'] = $address_2;
      $fs['values']['field_pin_code'][LANGUAGE_NONE][0]['value'] = $pincode;
      $fs['values']['field_state_list'][LANGUAGE_NONE][0]['value'] = $region_state;
      $fs['values']['field_city'][LANGUAGE_NONE][0]['value'] = $city_name;
      ###### State and city has to be taken from sheet for Oxigen: its done! ####################
      $fs['values']['field_mobile_1'][LANGUAGE_NONE][0]['value'] = $mobile_no;
      $fs['values']['field_email'][LANGUAGE_NONE][0]['value'] = $email;
      $fs['values']['field_pan_no'][LANGUAGE_NONE][0]['value'] = $pan_no;
      $fs['values']['field_service_tax'][LANGUAGE_NONE][0]['value'] = $service_tax;
      $fs['values']['field_remark'][LANGUAGE_NONE][0]['value'] = $remark;
      $oxi = TRUE; // to identify the oxigen leads in the following function.
      if ($pincode_status[0]) {
        $uid = bigbazaarcrm_application_register_login_user($fs, TRUE);
        $return = bigbazaarcrm_application_create_application_node($fs, $oxi, $uid);
        //$sid = bigbazaarcrm_application_get_sid_from_state_name('(Lead Generated)');
        workflow_execute_transition($return[0], $sid, NULL, TRUE);
      }
      else {
        $uid = bigbazaarcrm_application_register_login_user($fs, TRUE);
        $return = bigbazaarcrm_application_create_application_node($fs, $oxi, $uid);
        //$sid = bigbazaarcrm_application_get_sid_from_state_name('(Lead Generated)');
        workflow_execute_transition($return[0], $sid, NULL, TRUE);
      }
      $context['results']['success'] ++; //to count successfuly processed rows
    }
    else {
      //drupal_set_message($error_string, 'error');
      $context['results']['error'] ++; //to count rows that had errors
    }
    $context['sandbox']['progress'] = $i + $progress;
  }
  $rows_remain = $context['sandbox']['max'] - $context['sandbox']['progress'];
  $context['message'] = t($rows_remain . ' Remaining.');
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['finished'] = 1;
  }
  $context['results']['fid'] = $file_ob->fid;
}

/**
 * 
 * @param type $url
 * @param type $context
 * 
 * BATCH PROCESS TO PROCESS PAYMENT STATUS. CREATS ORDER.
 */
function payment_status_batch($file_ob, &$context) {
  $fp = file($file_ob->uri);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 1;
    $context['sandbox']['max'] = count($fp) - 1;
    $context['results']['success'] = 0;
    $context['results']['error'] = 0;
  }
  $file = new SplFileObject($file_ob->uri);
  $header = $file->current();
  $progress = $context['sandbox']['progress'];
  $max = $context['sandbox']['max'];
  
  if($max == 0){
    drupal_set_message('Please enter data in sheet', 'error');
  }
  $product_id = get_pid();
  $product = commerce_product_load($product_id);
  for ($i = 0; ( $i < 100 ) && ( ($i + $progress ) <= $max); $i++) {
    $file->seek($i + $progress);
    $data = str_getcsv($file->current());
    $head = explode(',', $header);
    $fc = $file->current();
    $error = FALSE;
    foreach ($data as $key => $value) {
      $data[$key] = trim($value);
      //var_dump($data[$key]);
      if (is_null($data[$key]) || $data[$key] === '') {
        //drupal_set_message($head[$key] . ' is empty at row ' . ($i + $progress), 'error');
        $context['results']['error_array'][$i + $progress] .= trim($head[$key]) . ' is empty,'; 
        $context['results']['error'] ++;
        $error = TRUE;
      }
      if (trim($head[$key]) == 'Amount' && $data[$key] === '0') {
        //drupal_set_message('Amount Cannot be zero at row' . ($i + $progress), 'error');
        $context['results']['error_array'][$i + $progress] .= 'Amount cannot be 0,'; 
        $context['results']['error'] ++;
        $error = TRUE;
      }
    }
    $agent_id = $data[0];
    $payment_status = $data[1];
    $amount = $data[2];
    if(!is_numeric($amount) && $amount < 0){
      $context['results']['error'] ++;
      $context['results']['error_array'][$i + $progress] .= 'Amount should be numeric,'; 
      $error = TRUE;
    }
    if (!($payment_status == 1 || $payment_status === 0 || $payment_status === '0')) {
      $context['results']['error_array'][$i + $progress] .= 'Payment status can only be 1 or 0,';
      $context['results']['error'] ++;
      $error = TRUE;
    }
    $nid = get_nid_from_application_no($agent_id);
    if (!$nid) {
      $context['results']['error_array'][$i + $progress] .= 'Incorrect Agent Id,';
      $context['results']['error'] ++;
      $error = TRUE;
    }
    $check_trans = bigbazaarcrm_common_check_transaction_for_nid_import($nid);
   if (!$error){
    if ($check_trans) { //IF STATUS IS SET TO PENDING WHILE CREATING THE PAYMENT ENTRY
      $transaction = commerce_payment_transaction_load($check_trans);
      if ($transaction->status == COMMERCE_PAYMENT_STATUS_PENDING) {
        if ($payment_status) {
          $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;
          $node = node_load($nid);
          $order = $transaction->order_id;
          commerce_checkout_complete($order);
          commerce_payment_transaction_save($transaction);
          $sid = bigbazaarcrm_application_get_sid_from_state_name('(Payment received)');
          //changes the workflow status
          workflow_execute_transition($node, $sid, NULL, TRUE);
          ###########CHANGE WORKFLOW STATUS HERE ALSO ########################

        }
        $context['results']['success'] ++;
        }
        elseif ($transaction->status == COMMERCE_PAYMENT_STATUS_SUCCESS) {
          if ($payment_status) {
            $context['results']['error_array'][$i + $progress] .= 'Status Already cleared,';
            $context['results']['error'] ++;
          }
          else {
            $context['results']['error_array'][$i + $progress] .= 'Cannot change status since status is already cleared,';
            $context['results']['error'] ++;
        }
      }
    }
    else {
      // foolowing function creats order and creats a payment entry for that order.
      $result = commerce_node_checkout_add_node_import($agent_id, $product, $amount);
     drupal_get_messages();
      $node = $result['node'];
      //creats a profile to be attached to the order
      $profile = customer_create_profile($result['node'], $result['user_id']);
      $order = $result['order'];
      $order->commerce_customer_billing['und'][0]['profile_id'] = $profile->profile_id;

      $order->status = 'checkout_complete';
      commerce_order_save($order);

      if ($payment_status) {
        //does the transaction entry. Puts status as success
        payment_transaction($result['order'], TRUE);
        $sid = bigbazaarcrm_application_get_sid_from_state_name('(Payment received)');
        //changes the workflow status
        workflow_execute_transition($result['node'], $sid, NULL, TRUE);
        //changes the order status to completed.
        commerce_checkout_complete($result['order']);
        ###########CHANGE WORKFLOW STATUS HERE ########################
      }
      else {
        ////does the transaction entry. Puts status as pending, since the payment status flag is set to 0.
        payment_transaction($result['order'], FALSE);
      }
      $context['results']['success'] ++;
    }
   }
  }
  $context['sandbox']['progress'] = $i + $progress;
  $rows_remain = $context['sandbox']['max'] - $context['sandbox']['progress'];
  $context['message'] = t($rows_remain . ' Remaining.');
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['finished'] = 1;
  }
   $context['results']['fid'] = $file_ob->fid;
}

function franchisee_batch($file_ob, &$context) {
  $fp = file($file_ob->uri);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 1;
    $context['sandbox']['max'] = count($fp) - 1;
    $context['results']['success'] = 0;
    $context['results']['error'] = 0;
  }
  $file = new SplFileObject($file_ob->uri);
  $header = $file->current();
  $progress = $context['sandbox']['progress'];
  $max = $context['sandbox']['max'];
  
  if($max == 0){
    drupal_set_message('Please enter data in sheet', 'error');
  }
  for ($i = 0; ( $i < 100 ) && ( ($i + $progress ) <= $max); $i++) {
    $file->seek($i + $progress);
    $data = str_getcsv($file->current());
    $head = explode(',', $header);
    foreach ($data as $key => $value) {
      
      $error = FALSE;
      $data[$key] = trim($value);
      if (is_null($data[$key]) || $data[$key] === '') {
        //drupal_set_message($head[$key] . ' is empty at row ' . ($i + $progress), 'error');
        $context['results']['error'] ++;
        $error = TRUE;
        $context['results']['error_array'][$i + $progress] .= trim($head[$key]) . ' is empty,';
      }
    }
    $agent_id = $data[0];
    $franchisee_code = $data[1];
    
    $franchisee_code_check = preg_match('/^([0-9]{8})$/', $franchisee_code);
    if (!$franchisee_code_check) {
      $context['results']['error'] ++;
      $error = TRUE;
      $context['results']['error_array'][$i + $progress] .= 'Invalid Franchisee code,';
    }
    else {
      $check_fr = check_franchisee_code_exists($franchisee_code);
      if (!empty($check_fr)) {
        $context['results']['error'] ++;
        $error = TRUE;
        $context['results']['error_array'][$i + $progress] .= 'Entered Franchisee code already exists,';
      }
    }

    $nid = get_nid_from_application_no($agent_id);
    if (empty($nid)) {
      //drupal_set_message('Agent id does not exist at row ' . ($i + $progress), 'error');
      $error = TRUE;
      $context['results']['error'] ++;
      $context['results']['error_array'][$i + $progress] .= 'Agent id does not exist,';
    }
    else {
      $fr_code_for_agent = check_fr_code_exists_for_agent($agent_id);
      if (!empty($fr_code_for_agent)) {
        //drupal_set_message('Franchisee code already exists for Agent at row ' . ($i + $progress), 'error');
        $error = TRUE;
        $context['results']['error'] ++;
        $context['results']['error_array'][$i + $progress] .= 'Franchisee code already uploaded for this Agent,';
      }
      
      $check_trans = bigbazaarcrm_common_check_transaction_for_nid_import($nid);
      $transaction = commerce_payment_transaction_load($check_trans);
      if (!($transaction && $transaction->status == COMMERCE_PAYMENT_STATUS_SUCCESS)) {
        $error = TRUE;
        $context['results']['error'] ++;
        $context['results']['error_array'][$i + $progress] .= 'Payment has not been completed for this agent,';
      }
    }

    if (!$error) {
      $node = node_load($nid);
      $node->field_franchisee_code['und'][0]['value'] = $franchisee_code;
      node_save($node);
      $context['results']['success'] ++;
      
      $sid = bigbazaarcrm_application_get_sid_from_state_name('(Signup Done)');
      //changes the workflow status
      workflow_execute_transition($node, $sid, NULL, TRUE);
    }
  }
  $context['sandbox']['progress'] = $i + $progress;
  $rows_remain = $context['sandbox']['max'] - $context['sandbox']['progress'];
  $context['message'] = t($rows_remain . ' Remaining.');
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['finished'] = 1;
  }
  $context['results']['fid'] = $file_ob->fid;
}

function lead_batch_finished($success, $results, $operations) {

  //Delete file after import has been completed.
  if ($file_delete = file_load($results['fid'])) {
    file_delete($file_delete);
  }

  if (!empty($results['error_array'])) {
    $dir = 'public://csvimport';
    if (file_prepare_directory($dir, FILE_CREATE_DIRECTORY)) {
      $csv_filename = 'failed_rows-' . $results['fid'] . '.csv'; // we validated extension on upload
      $csv_filepath = $dir . '/' . $csv_filename;
      $targs = array(
        '!csv_url' => l(check_plain($csv_filename), file_create_url($csv_filepath)),
        '%csv_filename' => $csv_filename,
        '%csv_filepath' => $csv_filepath,
      );
      if ($handle = fopen($csv_filepath, 'w+')) {
        fputcsv($handle, array("Row", "Reason"));
        foreach ($results['error_array'] as $row => $error) {
          fputcsv($handle, array($row, $error));
        }
        fclose($handle);
        drupal_set_message(t('Some rows failed to import. You may download a CSV of these rows: !csv_url', $targs), 'error');
      }
      else {
        drupal_set_message(t('Some rows failed to import, but unable to write error CSV to %csv_filepath', $targs), 'error');
      }
    }
    else {
      drupal_set_message(t('Some rows failed to import, but unable to create directory for error CSV at %csv_directory', $targs), 'error');
    }
  }

  if ($success) {
    if ($results['success']) {
      $message = $results['success'] . ' rows were successfully imported.';
      drupal_set_message(check_plain($message));
    }
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

<?php

/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */

/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_documents_upload extends views_handler_field {

  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
    
  }

  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    //$abc = 'abcd';
    $refrence_id = $values->nid;
//    $a = db_select('field_data_field_application_refrence', 'f');
//    $a->fields('f', array('field_application_refrence_target_id'));
//    $a->condition('field_application_refrence_target_id', $refrence_id);
//    $r = $a->execute()->fetchAssoc();
//    $kyc_nid = $r[entity_id];
    $kyc_nid = bigbazaarcrm_application_get_kyc_nid_from_app_nid($refrence_id);
    if (!empty($kyc_nid)) {
      return (l(t('View/Edit KYC'), 'node/'.$kyc_nid ));
    }
    else {
      //return (l(t('Edit content'), 'node/add/kyc-upload'));
      return l(t("Add KYC"),'node/add/kyc-upload', array('query' => array("nid" => $refrence_id)));
    }
  }

}

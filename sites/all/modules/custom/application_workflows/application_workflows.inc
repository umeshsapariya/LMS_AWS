<?php

/**
 * @file
 * 
 */

/**
 * Implements hook_form()
 */
function application_workflows_form($form, &$form_state, $application_node) {

  //$application_node = node_load($nid);
  
  $status = field_collection_item_load($application_node->field_application_workflows[LANGUAGE_NONE][0]['value']);
  
  $kyc_status = $status->field_kyc_state['und'][0]['value'];
  $field = field_info_field('field_kyc_state');
  $kyc_allowed_values = list_allowed_values($field);
  array_unshift(&$kyc_allowed_values,'None');

  /*$device_status = $status->field_device_state['und'][0]['value'];
  $field = field_info_field('field_device_state');
  $device_allowed_values = list_allowed_values($field);
  array_unshift(&$device_allowed_values,'None');
  
  $kit_status = $status->field_startup_kit_state['und'][0]['value'];
  $field = field_info_field('field_startup_kit_state');
  $kit_allowed_values = list_allowed_values($field);
  array_unshift(&$kit_allowed_values,'None');
  */
  $form['kyc_state'] = array(
    '#type' => 'select',
    '#title' => t('KYC Status'),
    '#options' => $kyc_allowed_values,
    '#default_value' => $kyc_status,
    '#access' => array('kyc upload'),
    '#description' => t('This is the current KYC status. The status can be changed here'),
  );
  
  
 /* $form['device_state'] = array(
    '#type' => 'select',
    '#title' => t('Device sent Status'),
    '#options' => $device_allowed_values,
    '#default_value' => $device_status,
    '#access' => array('device provision'),  
    '#description' => t('Change the Device sent status'),
  );
  
  $form['startup_kit_state'] = array(
    '#type' => 'select',
    '#title' => t('Startup kit sent Status'),
    '#options' => $kit_allowed_values,
    '#default_value' => $kit_status,
    '#access' => array('start up kit'),  
    '#description' => t('Change the Startup kit status'),
  );
  */
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  
  $form_state['application_workflow']['nid']=$application_node->nid;
      
  return $form;
}

function application_workflows_form_submit($form, &$form_state) {

  if ($form['kyc_state']['#default_value'] !== $form_state['values']['kyc_state']) {
  }

  if ($form['device_state']['#default_value'] !== $form_state['values']['device_state']) {
  }

  $array[] = array('type' => 'field_kyc_state', 'status' => $form_state['values']['kyc_state']);
  $array[] = array('type' => 'field_device_state', 'status' => $form_state['values']['device_state']);
  $array[] = array('type' => 'field_startup_kit_state', 'status' => $form_state['values']['startup_kit_state']);

  $nid = $form_state['application_workflow']['nid'];
  application_workflows_attach_status_as_per_type($nid, $array);
}

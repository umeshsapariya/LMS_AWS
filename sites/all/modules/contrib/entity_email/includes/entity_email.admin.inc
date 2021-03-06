<?php

/**
 * @file
 * Contains pages for creating, editing, and deleting Entity Mail/Entity Mail Type.
 */

/**
 * Generate the Entity Email Type editing form.
 */
function entity_email_type_form($form, &$form_state, $entity_email_type, $op = 'edit') {
  $field_language = NULL;

  if ($op == 'clone') {
    $entity_email_type->name .= '';
    $entity_email_type->label .= ' (cloned)';
  }

  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#default_value' => $entity_email_type->label,
    '#description' => t('A short, descriptive label for this email template.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Name'),
    '#default_value' => $entity_email_type->name,
    '#description' => t('The machine-name for this email template. It may only contain lowercase letters, underscores, and numbers. It will be used in URLs and in all API calls.'),
    '#maxlength' => 64,
    '#machine_name' => array(
      'exists' => 'entity_email_type_load',
      'source' => array('label'),
    ),
    '#required' => TRUE,
    '#disabled' => !(isset($entity_email_type->is_new) && $entity_email_type->is_new),
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $entity_email_type->subject,
    '#description' => t('The subject line of the email template. May include tokens of any token type specified below.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['mail'] = array(
    '#prefix' => '<div id="mail-type-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#parents' => array('mail'),
  );

  // Attach extra fields.
  field_attach_form('entity_email_type', $entity_email_type, $form['mail'], $form_state, $field_language);

  $form['send_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send a test email.'),
  );

  $form['test_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Test Email'),
    '#default_value' => variable_get('site_mail', ini_get('sendmail_from')),
    '#description' => t('The email address to send the test email.'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="send_email"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['tokens'] = entity_email_type_token_help();

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save template'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/structure/entity_email_type',
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function entity_email_type_form_submit(&$form, &$form_state) {
  $entity_email_type = entity_ui_form_submit_build_entity($form, $form_state);
  $entity_email_type->save();
  // Send a test email.
  if($form_state['values']['send_email'] === 1) {
    global $user;
    $params = array(
      'cuid' => $user,
      'fuid' => $user,
      'mail_to' => $form_state['values']['test_email'],
    );
    $email = entity_email_send($form_state['values']['name'], $params);
  }
  $form_state['redirect'] = 'admin/structure/entity_email_type';
}

/**
 * Helper function to provide token help to template construction.
 */
function entity_email_type_token_help() {
  if (module_exists('token')) {
    $tokens = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('Make sure that the tokens you choose are available.'),
    );
    $tokens['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('site', 'current-user', 'entity-email-from', 'entity-email-to', 'entity-email-dynamic', 'entity-email-node',),
      '#global_types' => FALSE,
    );
  }
  else {
    $tokens = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.', array('@drupal-token' => 'http://drupal.org/project/token')) . '</p>',
    );
  }
  return $tokens;
}

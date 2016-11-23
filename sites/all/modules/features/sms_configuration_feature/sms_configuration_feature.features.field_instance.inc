<?php
/**
 * @file
 * sms_configuration_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sms_configuration_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-sms_conf-field_enabled'
  $field_instances['taxonomy_term-sms_conf-field_enabled'] = array(
    'bundle' => 'sms_conf',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_enabled',
    'label' => 'Enabled',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-sms_conf-field_machine_name'
  $field_instances['taxonomy_term-sms_conf-field_machine_name'] = array(
    'bundle' => 'sms_conf',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_machine_name',
    'label' => 'Machine name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-sms_conf-field_message'
  $field_instances['taxonomy_term-sms_conf-field_message'] = array(
    'bundle' => 'sms_conf',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_message',
    'label' => 'Message',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-sms_conf-field_tokens'
  $field_instances['taxonomy_term-sms_conf-field_tokens'] = array(
    'bundle' => 'sms_conf',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_tokens',
    'label' => 'Tokens',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enabled');
  t('Machine name');
  t('Message');
  t('Tokens');

  return $field_instances;
}

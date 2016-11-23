<?php
/**
 * @file
 * sms_configuration_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sms_configuration_feature_taxonomy_default_vocabularies() {
  return array(
    'sms_conf' => array(
      'name' => 'Sms configuration',
      'machine_name' => 'sms_conf',
      'description' => 'Sms congiguration master template',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

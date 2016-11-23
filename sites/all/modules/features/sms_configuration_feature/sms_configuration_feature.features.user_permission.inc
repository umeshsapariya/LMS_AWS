<?php
/**
 * @file
 * sms_configuration_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sms_configuration_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access sms conf.
  $permissions['access sms conf'] = array(
    'name' => 'access sms conf',
    'roles' => array(),
    'module' => 'sms_configuration',
  );

  return $permissions;
}

<?php
/**
 * @file
 * features_avinash.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function features_avinash_user_default_roles() {
  $roles = array();

  // Exported role: Lead.
  $roles['Lead'] = array(
    'name' => 'Lead',
    'weight' => 16,
  );

  // Exported role: Satellite Office Agent.
  $roles['Satellite Office Agent'] = array(
    'name' => 'Satellite Office Agent',
    'weight' => 17,
  );

  return $roles;
}

<?php
/**
 * @file
 * features_avinash.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function features_avinash_taxonomy_default_vocabularies() {
  return array(
    'event_calendar_status' => array(
      'name' => 'Event Status',
      'machine_name' => 'event_calendar_status',
      'description' => 'Description',
      'hierarchy' => 0,
      'module' => 'event_calendar',
      'weight' => 1,
    ),
    'pincode' => array(
      'name' => 'PINCODE',
      'machine_name' => 'pincode',
      'description' => 'Pincode master for franchisee vacancy',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

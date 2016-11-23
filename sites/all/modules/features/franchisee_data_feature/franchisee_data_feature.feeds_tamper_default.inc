<?php
/**
 * @file
 * franchisee_data_feature.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function franchisee_data_feature_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-agreement_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Agreement date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-agreement_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-exit_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Exit date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-exit_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-glow_sign_board_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Glow sign board date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-glow_sign_board_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-inshop_branding_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Inshop branding date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-inshop_branding_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-launch_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Launch date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-launch_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-mobile_app_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'Mobile App date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-mobile_app_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'franchisee_database_importer-sap_code_creation_date-strtotime';
  $feeds_tamper->importer = 'franchisee_database_importer';
  $feeds_tamper->source = 'SAP Code creation date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['franchisee_database_importer-sap_code_creation_date-strtotime'] = $feeds_tamper;

  return $export;
}

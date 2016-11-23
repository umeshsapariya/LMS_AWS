<?php
/**
 * @file
 * franchisee_data_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function franchisee_data_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'franchisee_database_importer';
  $feeds_importer->config = array(
    'name' => 'Franchisee database importer',
    'description' => 'Importing franchisee database terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'franchisee_data',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Franchisee code',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Franchisee first name',
            'target' => 'field_franchisee_first_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Franchisee last name',
            'target' => 'field_franchisee_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Email',
            'target' => 'field_franchisee_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Phone no',
            'target' => 'field_franchisee_phone_no',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Agreement date',
            'target' => 'field_agreement_date:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'SAP Code creation date',
            'target' => 'field_sap_code_creation_date:start',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Mobile App',
            'target' => 'field_mobile_app',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Mobile App date',
            'target' => 'field_mobile_app_date:start',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Inshop branding',
            'target' => 'field_inshop_branding',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Inshop branding date',
            'target' => 'field_inshop_branding_date:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Glow sign board',
            'target' => 'field_glow_sign_board',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Glow sign board date',
            'target' => 'field_glow_sign_board_date:start',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Launch date',
            'target' => 'field_launch_date:start',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Exit date',
            'target' => 'field_exit_date:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['franchisee_database_importer'] = $feeds_importer;

  return $export;
}

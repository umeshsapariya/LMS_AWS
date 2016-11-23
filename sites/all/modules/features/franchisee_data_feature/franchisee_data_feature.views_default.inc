<?php
/**
 * @file
 * franchisee_data_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function franchisee_data_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'franchisee_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Franchisee Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Franchisee Data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Franchisee first name */
  $handler->display->display_options['fields']['field_franchisee_first_name']['id'] = 'field_franchisee_first_name';
  $handler->display->display_options['fields']['field_franchisee_first_name']['table'] = 'field_data_field_franchisee_first_name';
  $handler->display->display_options['fields']['field_franchisee_first_name']['field'] = 'field_franchisee_first_name';
  $handler->display->display_options['fields']['field_franchisee_first_name']['label'] = 'First Name';
  /* Field: Content: Franchisee last name */
  $handler->display->display_options['fields']['field_franchisee_last_name']['id'] = 'field_franchisee_last_name';
  $handler->display->display_options['fields']['field_franchisee_last_name']['table'] = 'field_data_field_franchisee_last_name';
  $handler->display->display_options['fields']['field_franchisee_last_name']['field'] = 'field_franchisee_last_name';
  $handler->display->display_options['fields']['field_franchisee_last_name']['label'] = 'Last name';
  /* Field: Content: Phone No */
  $handler->display->display_options['fields']['field_franchisee_phone_no']['id'] = 'field_franchisee_phone_no';
  $handler->display->display_options['fields']['field_franchisee_phone_no']['table'] = 'field_data_field_franchisee_phone_no';
  $handler->display->display_options['fields']['field_franchisee_phone_no']['field'] = 'field_franchisee_phone_no';
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_franchisee_state']['id'] = 'field_franchisee_state';
  $handler->display->display_options['fields']['field_franchisee_state']['table'] = 'field_data_field_franchisee_state';
  $handler->display->display_options['fields']['field_franchisee_state']['field'] = 'field_franchisee_state';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_franchisee_email']['id'] = 'field_franchisee_email';
  $handler->display->display_options['fields']['field_franchisee_email']['table'] = 'field_data_field_franchisee_email';
  $handler->display->display_options['fields']['field_franchisee_email']['field'] = 'field_franchisee_email';
  /* Field: Content: Agreement date */
  $handler->display->display_options['fields']['field_agreement_date']['id'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['field'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: SAP Code creation date */
  $handler->display->display_options['fields']['field_sap_code_creation_date']['id'] = 'field_sap_code_creation_date';
  $handler->display->display_options['fields']['field_sap_code_creation_date']['table'] = 'field_data_field_sap_code_creation_date';
  $handler->display->display_options['fields']['field_sap_code_creation_date']['field'] = 'field_sap_code_creation_date';
  $handler->display->display_options['fields']['field_sap_code_creation_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Mobile App */
  $handler->display->display_options['fields']['field_mobile_app']['id'] = 'field_mobile_app';
  $handler->display->display_options['fields']['field_mobile_app']['table'] = 'field_data_field_mobile_app';
  $handler->display->display_options['fields']['field_mobile_app']['field'] = 'field_mobile_app';
  $handler->display->display_options['fields']['field_mobile_app']['type'] = 'list_key';
  /* Field: Content: Mobile App date */
  $handler->display->display_options['fields']['field_mobile_app_date']['id'] = 'field_mobile_app_date';
  $handler->display->display_options['fields']['field_mobile_app_date']['table'] = 'field_data_field_mobile_app_date';
  $handler->display->display_options['fields']['field_mobile_app_date']['field'] = 'field_mobile_app_date';
  $handler->display->display_options['fields']['field_mobile_app_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Inshop branding */
  $handler->display->display_options['fields']['field_inshop_branding']['id'] = 'field_inshop_branding';
  $handler->display->display_options['fields']['field_inshop_branding']['table'] = 'field_data_field_inshop_branding';
  $handler->display->display_options['fields']['field_inshop_branding']['field'] = 'field_inshop_branding';
  $handler->display->display_options['fields']['field_inshop_branding']['type'] = 'list_key';
  /* Field: Content: Inshop branding date */
  $handler->display->display_options['fields']['field_inshop_branding_date']['id'] = 'field_inshop_branding_date';
  $handler->display->display_options['fields']['field_inshop_branding_date']['table'] = 'field_data_field_inshop_branding_date';
  $handler->display->display_options['fields']['field_inshop_branding_date']['field'] = 'field_inshop_branding_date';
  $handler->display->display_options['fields']['field_inshop_branding_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Launch date */
  $handler->display->display_options['fields']['field_launch_date']['id'] = 'field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['table'] = 'field_data_field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['field'] = 'field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Exit date */
  $handler->display->display_options['fields']['field_exit_date']['id'] = 'field_exit_date';
  $handler->display->display_options['fields']['field_exit_date']['table'] = 'field_data_field_exit_date';
  $handler->display->display_options['fields']['field_exit_date']['field'] = 'field_exit_date';
  $handler->display->display_options['fields']['field_exit_date']['settings'] = array(
    'format_type' => 'yyyy_mm_dd',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Device information */
  $handler->display->display_options['fields']['field_device_information']['id'] = 'field_device_information';
  $handler->display->display_options['fields']['field_device_information']['table'] = 'field_data_field_device_information';
  $handler->display->display_options['fields']['field_device_information']['field'] = 'field_device_information';
  $handler->display->display_options['fields']['field_device_information']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_device_information']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'franchisee_data' => 'franchisee_data',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Franchisee Code';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    25 => 0,
    28 => 0,
    19 => 0,
    22 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Phone No (field_franchisee_phone_no) */
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['id'] = 'field_franchisee_phone_no_value';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['table'] = 'field_data_field_franchisee_phone_no';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['field'] = 'field_franchisee_phone_no_value';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['operator_id'] = 'field_franchisee_phone_no_value_op';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['label'] = 'Phone No';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['operator'] = 'field_franchisee_phone_no_value_op';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['identifier'] = 'field_franchisee_phone_no_value';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    25 => 0,
    28 => 0,
    19 => 0,
    22 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['autocomplete_field'] = 'field_franchisee_phone_no';
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_franchisee_phone_no_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Franchisee first name (field_franchisee_first_name) */
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['id'] = 'field_franchisee_first_name_value';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['table'] = 'field_data_field_franchisee_first_name';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['field'] = 'field_franchisee_first_name_value';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['operator_id'] = 'field_franchisee_first_name_value_op';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['operator'] = 'field_franchisee_first_name_value_op';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['identifier'] = 'field_franchisee_first_name_value';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    51 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    25 => 0,
    28 => 0,
    19 => 0,
    22 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['autocomplete_field'] = 'field_franchisee_first_name';
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_franchisee_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Franchisee last name (field_franchisee_last_name) */
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['id'] = 'field_franchisee_last_name_value';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['table'] = 'field_data_field_franchisee_last_name';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['field'] = 'field_franchisee_last_name_value';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['operator_id'] = 'field_franchisee_last_name_value_op';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['operator'] = 'field_franchisee_last_name_value_op';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['identifier'] = 'field_franchisee_last_name_value';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    51 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    25 => 0,
    28 => 0,
    19 => 0,
    22 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['autocomplete_field'] = 'field_franchisee_last_name';
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_franchisee_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: State (field_franchisee_state) */
  $handler->display->display_options['filters']['field_franchisee_state_value']['id'] = 'field_franchisee_state_value';
  $handler->display->display_options['filters']['field_franchisee_state_value']['table'] = 'field_data_field_franchisee_state';
  $handler->display->display_options['filters']['field_franchisee_state_value']['field'] = 'field_franchisee_state_value';
  $handler->display->display_options['filters']['field_franchisee_state_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_franchisee_state_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['operator_id'] = 'field_franchisee_state_value_op';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['operator'] = 'field_franchisee_state_value_op';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['identifier'] = 'field_franchisee_state_value';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    51 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
    25 => 0,
    28 => 0,
    19 => 0,
    22 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['autocomplete_field'] = 'field_franchisee_state';
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_franchisee_state_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/franchisee-data';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Franchisee Data';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/franchisee-data-export';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['franchisee_data'] = $view;

  return $export;
}

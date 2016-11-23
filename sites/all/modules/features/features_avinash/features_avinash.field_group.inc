<?php
/**
 * @file
 * features_avinash.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_avinash_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_information|node|application|form';
  $field_group->group_name = 'group_additional_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '14',
    'children' => array(
      0 => 'field_do_you_operate_from',
      1 => 'field_leader_of_society_commity',
      2 => 'field_leader_specify',
      3 => 'field_current_occupation',
      4 => 'field_current_occupation_other',
      5 => 'field_business_sector',
      6 => 'field_business_sector_other',
      7 => 'field_doing_business_since',
      8 => 'field_education_qualification_ot',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_additional_information|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|node|application|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '11',
    'children' => array(
      0 => 'field_address_1',
      1 => 'field_address_2',
      2 => 'field_landline_no',
      3 => 'field_city',
      4 => 'field_state_list',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Address',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_address|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_details|node|application|form';
  $field_group->group_name = 'group_basic_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_middle_name',
      1 => 'field_last_name',
      2 => 'field_pin_code',
      3 => 'field_mobile_1',
      4 => 'field_mobile_2',
      5 => 'field_email',
      6 => 'field_date_of_birth',
      7 => 'field_first_name',
      8 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basic_details|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_establishment_details2|node|application|form';
  $field_group->group_name = 'group_establishment_details2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bank Information',
    'weight' => '21',
    'children' => array(
      0 => 'field_bank_name',
      1 => 'field_pan_no',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bank Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_establishment_details2|node|application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_establishment_details|node|application|form';
  $field_group->group_name = 'group_establishment_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shop / Business / Establishment Details',
    'weight' => '17',
    'children' => array(
      0 => 'field_name_of_establishment',
      1 => 'field_address_line_1',
      2 => 'field_address_line_2',
      3 => 'field_shop_in_city',
      4 => 'field_shop_pin_code',
      5 => 'field_shop_mobile_1',
      6 => 'field_shop_mobile_2',
      7 => 'field_shop_email',
      8 => 'field_shop_tel_no',
      9 => 'field_area',
      10 => 'field_select',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Shop / Business / Establishment Details',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'class-sbe',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_establishment_details|node|application|form'] = $field_group;

  return $export;
}

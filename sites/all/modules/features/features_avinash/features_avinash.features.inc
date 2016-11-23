<?php
/**
 * @file
 * features_avinash.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_avinash_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_avinash_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_calendar' => array(
      'name' => t('Event Calendar'),
      'base' => 'node_content',
      'description' => t('A content type to create events for calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Title'),
      'help' => '',
    ),
    'kyc_upload' => array(
      'name' => t('kyc_upload'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pincode_vacancy_ledger' => array(
      'name' => t('Pincode Vacancy Ledger'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function features_avinash_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Application Status
  $workflows['Application Status'] = array(
    'name' => 'Application Status',
    'tab_roles' => '4,5,6,7,8,9,10,11,13,36',
    'options' => 'a:3:{s:16:"comment_log_node";i:1;s:15:"comment_log_tab";i:1;s:13:"name_as_title";i:1;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Application Status',
      ),
      1 => array(
        'state' => '(Payment Received Online)',
        'weight' => -19,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      2 => array(
        'state' => '(Application Rejected)',
        'weight' => -18,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      3 => array(
        'state' => '(Franchisee)',
        'weight' => -17,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      4 => array(
        'state' => '(Application Approved)',
        'weight' => -16,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      5 => array(
        'state' => '(Application Incomplete)',
        'weight' => -15,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      6 => array(
        'state' => '(Application Submitted offline)',
        'weight' => -14,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      7 => array(
        'state' => '(Application Submitted Online)',
        'weight' => -13,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      8 => array(
        'state' => '(Application Submitted at BBD Center)',
        'weight' => -12,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      9 => array(
        'state' => '(Submitted Online)',
        'weight' => -11,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      10 => array(
        'state' => '(Lead Generated)',
        'weight' => -10,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      11 => array(
        'state' => '(Application Complete)',
        'weight' => -9,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      12 => array(
        'state' => '(Quiz incomplete)',
        'weight' => -8,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      13 => array(
        'state' => '(Quiz complete-Ineligible)',
        'weight' => -7,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      14 => array(
        'state' => '(Quiz complete-Eligible)',
        'weight' => -6,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      15 => array(
        'state' => '(Payment pending)',
        'weight' => -2,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      16 => array(
        'state' => '(Applied-KYC Pending)',
        'weight' => -1,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      17 => array(
        'state' => '(Applied-KYC Uploaded)',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      18 => array(
        'state' => '(Applied-KYC Received)',
        'weight' => 1,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      19 => array(
        'state' => '(Applied-KYC Discrepancy)',
        'weight' => 2,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      20 => array(
        'state' => '(Applied-KYC verified)',
        'weight' => 3,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      21 => array(
        'state' => '(Agreement Copy-Sent)',
        'weight' => 4,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      22 => array(
        'state' => '(Agreement Copy-Not Sent)',
        'weight' => 5,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      23 => array(
        'state' => '(Agreement Copy-Received)',
        'weight' => 6,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      24 => array(
        'state' => '(Agreement Copy-Not Received)',
        'weight' => 7,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      25 => array(
        'state' => '(Agreement Copy-Signed and received)',
        'weight' => 8,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      26 => array(
        'state' => '(Agreement Copy-Received at Head office)',
        'weight' => 9,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      27 => array(
        'state' => '(Meeting Done)',
        'weight' => 10,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      28 => array(
        'state' => '(Meeting Scheduled',
        'weight' => 11,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      29 => array(
        'state' => '(Follow Up)',
        'weight' => 12,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      30 => array(
        'state' => '(Needs time to think)',
        'weight' => 13,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      31 => array(
        'state' => '(Hot lead)',
        'weight' => 14,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      32 => array(
        'state' => '(Not interested.)',
        'weight' => 15,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      33 => array(
        'state' => '(Signup done)',
        'weight' => 16,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      34 => array(
        'state' => '(Call back)',
        'weight' => 17,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      35 => array(
        'state' => '(Pin- code itself not serviceable)',
        'weight' => 18,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
      36 => array(
        'state' => '(Not reacheable)',
        'weight' => 19,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Application Status',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => '(Lead Generated)',
      ),
      1 => array(
        'roles' => 'anonymous user',
        'state' => '(Application Submitted Online)',
        'target_state' => '(Submitted Online)',
      ),
      2 => array(
        'roles' => 'anonymous user',
        'state' => '(Application Submitted Online)',
        'target_state' => '(Application Submitted at BBD Center)',
      ),
      3 => array(
        'roles' => 'anonymous user',
        'state' => '(Application Submitted Online)',
        'target_state' => '(Application Submitted offline)',
      ),
      4 => array(
        'roles' => 'anonymous user',
        'state' => '(Submitted Online)',
        'target_state' => '(Application Submitted at BBD Center)',
      ),
      5 => array(
        'roles' => 'anonymous user',
        'state' => '(Submitted Online)',
        'target_state' => '(Application Submitted Online)',
      ),
      6 => array(
        'roles' => 'anonymous user',
        'state' => '(Submitted Online)',
        'target_state' => '(Application Submitted offline)',
      ),
      7 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Meeting Done)',
      ),
      8 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Meeting Scheduled',
      ),
      9 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Follow Up)',
      ),
      10 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Needs time to think)',
      ),
      11 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Hot lead)',
      ),
      12 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Not interested.)',
      ),
      13 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Signup done)',
      ),
      14 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Call back)',
      ),
      15 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Pin- code itself not serviceable)',
      ),
      16 => array(
        'roles' => 'Sales Manager,Sales Supervisior',
        'state' => '(Quiz complete-Eligible)',
        'target_state' => '(Not reacheable)',
      ),
      17 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC Pending)',
        'target_state' => '(Applied-KYC Received)',
      ),
      18 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC Pending)',
        'target_state' => '(Applied-KYC Discrepancy)',
      ),
      19 => array(
        'roles' => 'Finance Team',
        'state' => '(Applied-KYC Pending)',
        'target_state' => '(Applied-KYC verified)',
      ),
      20 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC Uploaded)',
        'target_state' => '(Applied-KYC Received)',
      ),
      21 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC Uploaded)',
        'target_state' => '(Applied-KYC Discrepancy)',
      ),
      22 => array(
        'roles' => 'Finance Team',
        'state' => '(Applied-KYC Uploaded)',
        'target_state' => '(Applied-KYC verified)',
      ),
      23 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC Received)',
        'target_state' => '(Applied-KYC Discrepancy)',
      ),
      24 => array(
        'roles' => 'Finance Team',
        'state' => '(Applied-KYC Received)',
        'target_state' => '(Applied-KYC verified)',
      ),
      25 => array(
        'roles' => 'Finance Team',
        'state' => '(Applied-KYC Discrepancy)',
        'target_state' => '(Applied-KYC verified)',
      ),
      26 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC verified)',
        'target_state' => '(Agreement Copy-Sent)',
      ),
      27 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC verified)',
        'target_state' => '(Agreement Copy-Not Sent)',
      ),
      28 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC verified)',
        'target_state' => '(Agreement Copy-Received)',
      ),
      29 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Applied-KYC verified)',
        'target_state' => '(Agreement Copy-Not Received)',
      ),
      30 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Agreement Copy-Sent)',
        'target_state' => '(Agreement Copy-Received)',
      ),
      31 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Agreement Copy-Sent)',
        'target_state' => '(Agreement Copy-Not Received)',
      ),
      32 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Agreement Copy-Received)',
        'target_state' => '(Agreement Copy-Signed and received)',
      ),
      33 => array(
        'roles' => 'Finance Team',
        'state' => '(Agreement Copy-Received)',
        'target_state' => '(Agreement Copy-Received at Head office)',
      ),
      34 => array(
        'roles' => 'Finance Team,Satellite Office Agent',
        'state' => '(Agreement Copy-Not Received)',
        'target_state' => '(Agreement Copy-Signed and received)',
      ),
      35 => array(
        'roles' => 'Finance Team',
        'state' => '(Agreement Copy-Signed and received)',
        'target_state' => '(Agreement Copy-Received at Head office)',
      ),
    ),
    'node_types' => array(
      0 => 'application',
    ),
  );

  return $workflows;
}

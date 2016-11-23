<?php

/**
 * @file
 * 
 * bigbazaarcrm_application Create Views for Custom table
 *
 */


/**
 * hook_views_data().
 * 
 * bigbazaarcrm_application Create Views for Custom table
 */

function bigbazaarcrm_application_views_data() {
  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['application_existing_lead_source']['table']['group'] = t('Application Duplicate leads');
  
  // Define this as a base table – a table that can be described in itself by
  // views
  $data['application_existing_lead_source']['table']['base'] = array(
    'field' => 'id', // This is the identifier field for the view.
    'title' => t('Application Duplicate leads'),
    'help' => t('Dublicate leads for application'),
    'weight' => -10,
  );
  
  // Name data used in views.
  $data['application_existing_lead_source']['name'] = array(
    'title' => t('Name'),
    'help' => t('Name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Mobile number data used in views.
  $data['application_existing_lead_source']['mobile'] = array(
    'title' => t('Mobile'),
    'help' => t('Mobile'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // pincode number data used in views.
  $data['application_existing_lead_source']['pincode'] = array(
    'title' => t('Pincode'),
    'help' => t('Pincode'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // source number data used in views.
  $data['application_existing_lead_source']['source'] = array(
    'title' => t('Source'),
    'help' => t('Source'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  return $data;
}
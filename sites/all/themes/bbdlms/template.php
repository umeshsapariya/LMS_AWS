<?php

/**
 * @file
 * template.php
 */

/**
 * 
 * @param string $vars
 * @param type $hook
 * 
 */
function bbdlms_preprocess_page(&$vars, $hook) {
  drupal_add_library('system', 'jquery.once', TRUE);
  $content_type = array('webform','quiz');
  if(in_array($vars['node']->type, $content_type)){
    drupal_set_title('');
  }
  //Remove the popup displayed on the home page
  /*
  if(drupal_is_front_page()){
    drupal_add_js(drupal_get_path('module', 'bigbazaarcrm_application') . '/bigbazaarcrm_application.js');
  }
  */
}
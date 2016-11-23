<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/*
 *Implementation of custum code to hide front page text
 */
function bigbazaarcrm_process_page(&$variables) {
	if(drupal_is_front_page()) {
    $variables['title'] = "";
    $variables['page']['content']['content']['content']['system_main']['default_message']['#markup'] = "";
  }
	if ($variables['title'] == 'Review order') {
			$variables['page']['content']['content']['content']['system_main']['help']['#markup'] = '<div class="checkout-help"> Review your information before continuing.</div>';
	  $variables['title'] = 'Review Application';
	}

}

/*
 *Add Js on homepage
 */
function bigbazaarcrm_preprocess_html(&$variables) {
  if(drupal_is_front_page()) {
		drupal_add_js(drupal_get_path('theme','bigbazaarcrm').'/js/jquery.cookie.js');
    drupal_add_js(drupal_get_path('theme', 'bigbazaarcrm') . '/js/jquery.cycle.all.js', array(
        'scope' => 'header',
        'weight' => '0'
    ));  
    drupal_add_js(drupal_get_path('theme', 'bigbazaarcrm') . '/js/custom.js', array(
        'scope' => 'header',
        'weight' => '1'
    ));
  }
	if($_SERVER['REQUEST_URI'] == '/apply-online') {
		drupal_add_js(drupal_get_path('theme','bigbazaarcrm').'/js/form_validate.js');
		drupal_add_js(drupal_get_path('theme','bigbazaarcrm').'/js/jquery.validate.min.js');
	}
}
    
    
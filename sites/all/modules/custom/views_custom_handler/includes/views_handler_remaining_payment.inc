<?php

/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */
 
/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_remaining_payment extends views_handler_field {
  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
 
  }
 
  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
 
  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
 
  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    $order_id = $values->commerce_order_commerce_line_item_order_id;
    if(!empty($order_id)){
      $order = commerce_order_load($order_id);
      $order_balance = commerce_payment_order_balance($order);
      if($order_balance['amount'] != 0){
        return $order_balance['amount'] / 100;
      }
      return 0;
    }
    return 0;
  }
}
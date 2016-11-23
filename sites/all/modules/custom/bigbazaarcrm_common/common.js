jQuery(document).ready(function() {


jQuery('.group_establishment_details').find('h3').hide();
  jQuery('#edit-field-do-you-operate-from-und').change(function(){
    var location = jQuery(this).val();
    if(location == 'shop')
    {
      jQuery('.group_establishment_details').find('h3').show();
  
    }
    else{
     jQuery('.group_establishment_details').find('h3').hide(); 
    }
  });
  
  jQuery("#edit-field-same-as-above-und").live("click", function(){ 
    if(jQuery(this).is(':checked')){
      var add1 = jQuery("#edit-field-address-1-und-0-value").val();
      var add2 = jQuery("#edit-field-address-2-und-0-value").val();
      var landmark = jQuery("#edit-field-landmark-und-0-value").val();
      var city = jQuery("#edit-field-city-und-0-value").val();
      var pincode = jQuery("#edit-field-pin-code-und-0-value").val();
      var mobile1 = jQuery("#edit-field-mobile-1-und-0-value").val();
      var mobile2 = jQuery("#edit-field-mobile-2-und-0-value").val();
      var email = jQuery("#edit-field-email-und-0-value").val();
      var tel_no = jQuery("#edit-field-tel-no-und-0-value").val();
      
      
      if(add1.length > 0){
        jQuery("#edit-field-address-line-1-und-0-value").val(add1);
      }
      
      if(add2.length > 0){
        jQuery("#edit-field-address-line-2-und-0-value").val(add2);
      }
      
      if(add2.length > 0){
        jQuery("#edit-field-address-line-2-und-0-value").val(add2);
      }
      
      if(landmark.length > 0){
        jQuery("#edit-field-shop-landmark-und-0-value").val(landmark);
      }
      
      if(city.length > 0){
        jQuery("#edit-field-shop-in-city-und-0-value").val(city);
      }
      
      if(pincode.length > 0){
        jQuery("#edit-field-shop-pin-code-und-0-value").val(pincode);
      }
      
      if(mobile1.length > 0){
        jQuery("#edit-field-shop-mobile-1-und-0-value").val(mobile1);
      }
      if(mobile2.length > 0){
        jQuery("#edit-field-shop-mobile-2-und-0-value").val(mobile2);
      }
      if(email.length > 0){
        jQuery("#edit-field-shop-email-und-0-value").val(email);
      }
      if(tel_no.length > 0){
        jQuery("#edit-field-shop-tel-no-und-0-value").val(tel_no);
      }
      
      
     } 
      
    else{
      
    }  });  
  
});
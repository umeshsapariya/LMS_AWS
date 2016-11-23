/**
 * Custom js
 */

(function($) {
  $(document).ready(function(){
    $('.diff_email').hide();
    
    // Swtich New email ID box
    $('.diff_email_id').change(function(){
      if ($(this).is(':checked')) {
        $('.diff_email').show();
      }else {
        $('.diff_email').hide();
      } 
    });
    
    // Swtich New email ID box
    $('.send-email-agian a').click(function(e){
      e.preventDefault();
      var hrf = $(this).attr('href');
      if ($('.diff_email_id').is(':checked')) {
        if ($('.diff_email').val().length == 0) {
          $('.diff_email').val('please enter something');
        }else {
          var new_id = $('.diff_email').val();
          var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;  
          if(new_id.match(mailformat)){
            window.location.href = hrf+'&new_id='+new_id;  
          }else {
            $('.diff_email').val('Its invalid email');
          }            
        }
      }else {
        window.location.href = hrf;  
      }
    });
    
  });
})(jQuery);

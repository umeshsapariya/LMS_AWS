/**
 * Implementation of Drupal behavior.
 */
(function($) {
Drupal.behaviors.rubik = {};
Drupal.behaviors.rubik.attach = function(context) {
  // If there are both main column and side column buttons, only show the main
  // column buttons if the user scrolls past the ones to the side.
  $('div.form:has(div.column-main div.form-actions):not(.rubik-processed)').each(function() {
    var form = $(this);
    var offset = $('div.column-side div.form-actions', form).height() + $('div.column-side div.form-actions', form).offset().top;
    $(window).scroll(function () {
      if ($(this).scrollTop() > offset) {
        $('div.column-main div.form-actions', form).show();
      }
      else {
        $('div.column-main div.form-actions', form).hide();
      }
    });
    form.addClass('rubik-processed');
  });

  $('a.toggler:not(.rubik-processed)', context).each(function() {
    var id = $(this).attr('href').split('#')[1];
    // Target exists, add click handler.
    if ($('#' + id).size() > 0) {
      $(this).click(function() {
        toggleable = $('#' + id);
        toggleable.toggle();
        $(this).toggleClass('toggler-active');
        return false;
      });
    }
    // Target does not exist, remove click handler.
    else {
      $(this).addClass('toggler-disabled');
      $(this).click(function() { return false; });
    }
    // Mark as processed.
    $(this).addClass('rubik-processed');
  });
  
  // view load image
  $('.custom-view-load-gif').each(function() {
    $('.custom-view-load-gif').ajaxStart(function(){
      var light = jQuery('.view_load_image');
    $('.view_load_image').show();$('.bgshadow').show();
		$('.bgshadow').css("height",$(document).height());
		$('.bgshadow').css("width",$(document).width());
		light.css("left", Math.max(0, (($(window).width() - light.outerWidth()) / 2) + $(window).scrollLeft()) + "px");
		light.css("top", "150px");                              
    });
    $('.custom-view-load-gif').ajaxSuccess(function(){ 
      $('.view_load_image').hide();$('.bgshadow').hide();
    });
  });
  
};
})(jQuery);

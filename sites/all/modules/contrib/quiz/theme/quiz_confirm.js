(function ($) {
  Drupal.behaviors.confirm = {
    attach : function(context, settings) {
      $('form.confirm').each(function() {
        var $form = $(this);
        $form.find('#edit-submit').each(function() {
          $(this).click(function() {
            if ($("[name=jump_to_question]").val() == 0) {
              return confirm($form.data('confirm-message'));
            }
          });
        });
        $form.find('#edit-op').each(function() {
          $(this).click(function() {
            return confirm($form.data('confirm-message'));
          });
        });
      });
    }
  };
})(jQuery);

(function($) {
    Drupal.behaviors.modal_popup_custom = {
        attach: function(context, settings) {
            $(document).ready(function() {
                jQuery('.modal-content a').click();
                var url = location.href + 'survey/session';
                jQuery.ajax(url).done(function(msg) {
                    if (msg.status) {
                        console.log('success');
                        var new_time = setTimeout(function() {
                            if (!$('#home-road-block').hasClass('processed')) {
                                $('#home-road-block').addClass('processed').click();
                                $(document).unbind("keydown", modalEventEscapeCloseHandler);
                            }
                        }, 1000);
                    }
                });
            });

        }
    };
})(jQuery);
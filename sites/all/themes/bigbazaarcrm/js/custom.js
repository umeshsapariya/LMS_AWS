/*!
 * jQuery Custum
 * Requires: jQuery v1.3.2 or later
 */

jQuery(document).ready(function() {
	jQuery('#home_slider').cycle({
		fx: 'fade',
		pause: 1,
		prev: '#prev',
		next: '#next',
		pager: '#slideshow-nav'
	});
	
	if (!jQuery.cookie('pop_up')) {
		var light = jQuery('.home_light_box');
		jQuery('.home_light_box').show();jQuery('.bgshadow').show();
		jQuery('.bgshadow').css("height",jQuery(document).height());
		jQuery('.bgshadow').css("width",jQuery(document).width());
		light.css("left", Math.max(0, ((jQuery(window).width() - light.outerWidth()) / 2) + jQuery(window).scrollLeft()) + "px");
		light.css("top", "150px");
		jQuery('.home_light_box span').click(function() {
			jQuery('.home_light_box').hide();		jQuery('.bgshadow').hide();
		});
		jQuery.cookie('pop_up','visited');
	}	
});  


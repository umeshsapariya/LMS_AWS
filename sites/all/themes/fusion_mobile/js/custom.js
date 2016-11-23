(function($) {
	$(document).ready(function() {
		
		$("#block-block-13 h2.mheading").next("div").hide();
		$("#block-block-13 h2.mheading").addClass('close');
		$("#block-block-13 h2.mheading").click(function(){
                  //$("#block-block-13 h2.mheading").removeClass('open').addClass('close');		;
                  //$("#block-block-13 h2.mheading").addClass('close');			
                  //$(this).removeClass('close').addClass("open");
                  $(this).parents("div.block").siblings().find("h2").removeClass('open').addClass('close');
                  $(this).toggleClass('open');
                 
                  $(this).next("div").slideToggle();
                  $(this).toggleClass('close');
                  //$(this).parents("div.block").siblings().find("h2").addClass('close');
                  $(this).parents("div.block").siblings().find("div").hide();		
		});	
	});
})( jQuery );
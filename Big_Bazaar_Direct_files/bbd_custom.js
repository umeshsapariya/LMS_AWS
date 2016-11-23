jQuery(document).ready(function(){	
	jQuery("ul.menu > li").hover(function(){
		jQuery("ul",jQuery(this)).stop(true,true).fadeToggle('fast');
	});
/* Product catalog filter js*/
jQuery('form#views-exposed-form-product-catalog-page input#edit-title, form#views-exposed-form-product-catalog-page-1 input#edit-title').change(function() {
	jQuery('form#views-exposed-form-product-catalog-page, form#views-exposed-form-product-catalog-page-1').submit();
});
    
jQuery('form#views-exposed-form-product-catalog-page select#edit-sort-bef-combine, form#views-exposed-form-product-catalog-page-1 select#edit-sort-bef-combine').change(function() {
	jQuery('form#views-exposed-form-product-catalog-page, form#views-exposed-form-product-catalog-page-1').submit();
});
jQuery(function(){

    var url =  window.location.pathname;
    url += window.location.search; 
        urlRegExp = new RegExp(url.replace(/\/$/,'')); // create regexp to match current url pathname and remove trailing slash if present as it could collide with the link in navigation in case trailing slash wasn't present there
    
        // now grab every link from the navigation
        jQuery('.page-taxonomy-term .pin_franchise_side a').each(function(){
            // and test its href against the url pathname regexp
            if(urlRegExp.test(this.href)){
                jQuery(this).addClass('active');
            }
        });
});
});



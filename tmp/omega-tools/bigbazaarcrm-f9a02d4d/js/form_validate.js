/**
 * @author kalidasan seetharaman
 * @copyright 2013
 */

jQuery(document).ready(function() {
	jQuery("#check-number-exists-form").validate({
		rules: {
			phone_number: {
				minlength: 10,
				required: true,
				maxlength: 10,
				number: true
			}
		},
		messages: {
			phone_number: 'Please enter a valid 10 digit mobile no'
		}
	});
	
	jQuery("#bbd-centre-search-record").validate({
		rules: {
			search: {
				minlength: 10,
				maxlength: 10,
				required: true,
				number: true
			}
		},
		messages: {
			search: 'Please enter a valid 10 digit mobile no'
		}
	});
	
	jQuery("#enquiry-node-form").validate({
		rules: {
			'field_pin_number[und][0][value]': {
				minlength: 6,
				maxlength: 6,
				required: true,
				number: true
			},
			'field_tel_no[und][0][value]': {
				minlength: 10,
				maxlength: 10,
				required: true,
				number: true
			},
			'field_email[und][0][value]': {
				email: true
			},
			'field_city_[und]': {
				required: true
			}
		},
		messages: {
			'field_pin_number[und][0][value]': 'Please enter a valid 6 digit Pin Code',
			'field_tel_no[und][0][value]': 'Please enter a valid 10 digit mobile no',
			'field_city_[und]' : 'Please select a City'
		}
	});
	
	// Apply online form validation
	jQuery("#application-node-form").validate({
		rules: {
			'field_pin_code[und][0][value]': {
				minlength: 6,
				maxlength: 6,
				required: true,
				number: true
			},
			'field_mobile_1[und][0][value]': {
				minlength: 10,
				maxlength: 10,
				required: true,
				number: true
			},
			'field_mobile_2[und][0][value]': {
				minlength: 10,
				maxlength: 10,
				number: true
			},
			'field_email[und][0][value]': {
				required: true,
				email: true
			}
		},
		messages: {
			'field_pin_code[und][0][value]': 'Please enter a valid 6 digit Pin Code',
			'field_mobile_1[und][0][value]': 'Please enter a valid 10 digit mobile no'
		}
	});
	
});
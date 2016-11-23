/**
 * @author kalidasan seetharaman
 * @copyright 2013
 */
Drupal.behaviors.formValidate = {
    attach: function(context, settings) {
        jQuery.validator.addMethod("check_date_of_birth", function(value, element) {

            //var data = jQuery("input[name='field_date_of_birth[und][0][value][date]']").text();
            //var arr = data.split('/');
            var arr = value.split('/');
            var day = arr[0];
            var month = arr[1];
            var year = arr[2];
            var age = 18;

            //var mydate = new Date();
            //mydate.setFullYear(year, month - 1, day);

            var currdate = new Date();
            
            var current_year = currdate.getFullYear();
            var current_month =  (currdate.getMonth() + 1);      

            if (current_year - year >= age) {
                if ((current_year - year) === age) {
                    if (current_month < month) {
                        return false;
                    }
                }
                return true;
            }
            else {
                return false;
            }
            //return currdate > mydate;

        }, "You must be at least 18 years of age.");


        jQuery(".node-application-form").find(".date-clear").attr("placeholder", "Date of Birth");
        jQuery(".page-node-edit .node-application-form .form-item-field-date-of-birth-und-0-value input").attr("readonly", "readonly");
        

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
                'field_city_[und]': 'Please select a City'
            }
        });

        // Apply online form validation
        jQuery("body").find(".node-application-form").validate({
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
                },
                'field_date_of_birth[und][0][value][date]': {
                    check_date_of_birth: true,
                    required: true,
                }

            },
            messages: {
                'field_pin_code[und][0][value]': 'Please enter a valid 6 digit Pin Code',
                'field_mobile_1[und][0][value]': 'Please enter a valid 10 digit mobile no',
                'field_email[und][0][value]': 'Please enter a valid email address (eg:bbd@gmail.com)'
            }
        });

    }
};

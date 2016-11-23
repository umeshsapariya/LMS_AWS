<?php
// Bootstrap drupal.
$path = $_SERVER['DOCUMENT_ROOT'];
chdir($path);
define('DRUPAL_ROOT',$path);
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$errorStr = "";
$errorCount = 0;
$post = $_POST;

if( isset($_POST) && !empty($_POST)) {
  $error = '';
  
  // First name validation.
  if(!empty($post['fname_booking'])) {
    $_SESSION['f_name'] = $post['fname_booking'];
    if(!preg_match("/^[a-zA-Z'-]/", $post['fname_booking'])) {
      $error .= 'Please enter a valid First Name for shop\n';
      $errorCount++;
    }
  }
  // Last name validation.
  if(!empty($post['lname_booking'])) {
    $_SESSION['l_name'] = $post['lname_booking'];
    if(!preg_match("/^[a-zA-Z'-]/", $post['lname_booking'])) {
      $error .= 'Please enter a valid Last Name for shop\n';
      $errorCount++;
    }
  }
  
  // Email validation.
  if(!empty($post['email'])) {
    $_SESSION['email'] = $post['email'];
    $emailval = '/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$/';
    if (!preg_match($emailval, $post['email'])) {
      $error .= 'Please enter valid email address for shop\n';
      $errorCount++;
    }
  }
  // Pincode validation.
  if(!empty($post['pincode'])) {
    $_SESSION['pincode'] = $post['pincode'];
    if (!is_numeric($post['pincode'])) {
      $error .= 'Pincode should be numeric for shop\n';
      $errorCount++;
    }
    else if (!preg_match("/^\d{6}$/", $post['pincode'])) {
      $error .= 'Please enter valid PIN code for Shop\n';
      $errorCount++;
    }
  }
  // Storing story infor.
  if (!empty($post['name_booking'])) {
     $_SESSION['name_booking'] = $post['name_booking'];
  }
  
  // Mobile number validation.
  if(!empty($post['mobile'])) {
    $_SESSION['mobile'] = $post['mobile'];
    $mobile_status_val = bigbazaarcrm_application_check_mobile_exists($_POST['mobile']);
    if (!is_numeric($post['mobile'])) {
      $error .= 'Please enter a valid mobile number for shop\n';
      $errorCount++;
    }
    else if( !preg_match("/^\d{10}$/", $post['mobile'])) {
      $error .= 'Please enter a valid mobile number for shop\n';
      $errorCount++;
    }
    else if(!empty($mobile_status_val)) {
      // Storing source already exit data used for agency.
      $source_already = db_insert('application_existing_lead_source')
      ->fields(array(
        'name' => $post['fname_booking'] . ' ' .$post['lname_booking'] ,
        'mobile' => $post['mobile'],
        'pincode' => $post['pincode'],
        'source' => 'Storycode'
      ))
      ->execute();
    }
  }

if($errorCount == 0) {
  unset($_SESSION['error']);
  $mobile_status = bigbazaarcrm_application_check_mobile_exists($_POST['mobile']);

  if (empty($mobile_status)) {
    $form_state = array(
    'values' => array(
      'source' => 'Storycode',
      'field_first_name' => $post['fname_booking'],
      'field_last_name' => $post['lname_booking'],
      'field_mobile_1' => $post['mobile'],
      'field_email'=> $post['email'],
      'field_pin_code' => $post['pincode'],
      'field_remark' => $post['name_booking'],
      ),
    );
  
    $result = bigbazaarcrm_forms_request_form_submit(NULL, $form_state, TRUE);
    //unset($_SESSION['error']);
    session_destroy();
  }
} 
else {  
  $_SESSION['error'] = $error;
  header("Location:index.php");
  drupal_exit('index.php');
}
}

?>


<!DOCTYPE html>
<html>
<head>
	<title></title>
      <link rel="shortcut icon" href="http://shop.bigbazaardirect.com/sites/default/files/favicon_0.ico" type="image/vnd.microsoft.icon">
	  <link rel="stylesheet" type="text/css" href="css/custom.css">
	  <link href="//netdna.bootstrapcdn.com/font-awesome/3.2.1/css/font-awesome.css" rel="stylesheet">
	  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">
	  <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-MfvZlkHCEqatNoGiOXveE8FIwMzZg4W85qfrfIFBfYc= sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">
      
  <script> 
    !function(f,b,e,v,n,t,s){if(f.fbq)return;n=f.fbq=function(){n.callMethod? 
    n.callMethod.apply(n,arguments):n.queue.push(arguments)};if(!f._fbq)f._fbq=n; 
    n.push=n;n.loaded=!0;n.version='2.0';n.queue=[];t=b.createElement(e);t.async=!0; 
    t.src=v;s=b.getElementsByTagName(e)[0];s.parentNode.insertBefore(t,s)}(window, 
    document,'script','//connect.facebook.net/en_US/fbevents.js'); 

    fbq('init', '538296873003766'); 
    fbq('track', "PageView");</script> 
    <noscript><img height="1" width="1" style="display:none" 
    src="https://www.facebook.com/tr?id=538296873003766&ev=PageView&noscript=1" 
    /></noscript> 
    
   <script>var _gaq = _gaq || [];_gaq.push(["_setAccount", "UA-41539951-1"]);_gaq.push(["_trackPageview"]);(function() {var ga = document.createElement("script");ga.type = "text/javascript";ga.async = true;ga.src = ("https:" == document.location.protocol ? "https://ssl" : "http://www") + ".google-analytics.com/ga.js";var s = document.getElementsByTagName("script")[0];s.parentNode.insertBefore(ga, s);})();</script>

</head>
<body class="thankyou">
   <header>

        <div class="container">

            <div class="customer-care">

                <i class="icon-phone-sign">1800 266 6700</i>

                <i class="fa fa-envelope">Support@bigbazaardirect.com</i>

            </div>

        </div>

    </header>

    <div class="container">

        <div class="logo">
          <a class="logo navbar-btn pull-left" target="_blank" href="http://<?php echo $_SERVER['SERVER_NAME']?>" title="Home">
            <img src="http://bigbazaardirect.com/sites/default/files/BBD-logo.png" alt="Home">
          </a>
        </div>

    </div>
    <div class="container">
    <div class="box">
    	<div class="outer-box">
    		<p>THANK YOU FOR SUBMITTING YOUR ENTRY</p>
    	</div>
    	<div class="inner-box">
    		<p>We will evaluate the your response and declare the the winner soon.<br>
    		In the mean time, our representative will get in touch with you.<br>
    		If you need any further assistance you may <br>
    		Contact us @ 1800 266 6700 <br>
    		or drop an email at support@bigbazaardirect.com </p>
    		</div>
        </div>
    </div>
    <div class="container">

	<div class="footer">

	<ul style="list-style-type:none;">

		

		<li class="contactf">Contact Us</li>	

		<li class="call-mail"><i class="icon-phone-sign">1800 266 6700</i></li>

		<li class="call-mail"><i class="fa fa-envelope">Support@bigbazaardirect.com</i></li>			

		</ul>

		<div class="social">

			<p>KEEP IN TOUCH</p>

			<a target="_blank" href="https://www.facebook.com/bigbazaardirect">
                <i class="fa fa-facebook"></i>
            </a>
            <a target="_blank" href="https://twitter.com/BBfranchisee">
              <i class="fa fa-twitter"></i>
            </a>
            <a target="_blank" href="http://www.linkedin.com/company/big-bazaar-direct">
              <i class="fa fa-linkedin"></i>
            </a>

		</div>

	</div>


</body>
</html>
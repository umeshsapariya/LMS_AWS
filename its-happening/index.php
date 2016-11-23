<?php
// Bootstrap drupal.
$path = $_SERVER['DOCUMENT_ROOT'];
chdir($path);
define('DRUPAL_ROOT',$path);
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$mobile = false;
$useragent=$_SERVER['HTTP_USER_AGENT'];
if(preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i',$useragent)||preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i',substr($useragent,0,4))) {
    $mobile = true;
}
?>

<!DOCTYPE html>

<html>



<head>

    <title></title>

    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
   <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
   <meta name="HandheldFriendly" content="true" />
<script> 
    !function(f,b,e,v,n,t,s){if(f.fbq)return;n=f.fbq=function(){n.callMethod? 
    n.callMethod.apply(n,arguments):n.queue.push(arguments)};if(!f._fbq)f._fbq=n; 
    n.push=n;n.loaded=!0;n.version='2.0';n.queue=[];t=b.createElement(e);t.async=!0; 
    t.src=v;s=b.getElementsByTagName(e)[0];s.parentNode.insertBefore(t,s)}(window, 
    document,'script','//connect.facebook.net/en_US/fbevents.js'); 

    fbq('init', '538296873003766'); 
    fbq('track', "PageView");
    </script> 
    <noscript><img height="1" width="1" style="display:none" 
    src="https://www.facebook.com/tr?id=538296873003766&ev=PageView&noscript=1" 
    /></noscript> 
    
   <script>var _gaq = _gaq || [];_gaq.push(["_setAccount", "UA-41539951-1"]);_gaq.push(["_trackPageview"]);(function() {var ga = document.createElement("script");ga.type = "text/javascript";ga.async = true;ga.src = ("https:" == document.location.protocol ? "https://ssl" : "http://www") + ".google-analytics.com/ga.js";var s = document.getElementsByTagName("script")[0];s.parentNode.insertBefore(ga, s);})();</script>

    

    <link rel="shortcut icon" href="http://shop.bigbazaardirect.com/sites/default/files/favicon_0.ico" type="image/vnd.microsoft.icon">
    <link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
    <!--      <link rel="stylesheet" href="css/jquery.mCustomScrollbar.css"> -->
  	<script src="//code.jquery.com/jquery-1.10.2.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>

    <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
        <!--script src="js/jquery.mCustomScrollbar.concat.min.js"></script-->

    <script src="js/custom.js"></script>

    <link href="//netdna.bootstrapcdn.com/twitter-bootstrap/2.3.2/css/bootstrap-combined.no-icons.min.css" rel="stylesheet">

    <link href="//netdna.bootstrapcdn.com/font-awesome/3.2.1/css/font-awesome.css" rel="stylesheet">

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css">

    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-MfvZlkHCEqatNoGiOXveE8FIwMzZg4W85qfrfIFBfYc= sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">

    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js" integrity="sha256-Sk3nkD6mLTMOF0EOpNtsIry+s1CsaqQC1rVLTAy+0yc= sha512-K1qjQ+NcF2TYO/eI3M6v8EiNYZfA95pQumfvcVrTHtwQVDG+aHRqLi/ETn2uB+1JqwYqVG3LIvdm9lj6imS/pQ==" crossorigin="anonymous"></script>

   
 
    <link rel="stylesheet" href="css/slider.css">

    <link rel="stylesheet" type="text/css" href="css/testimonial.css">
    <link rel="stylesheet" type="text/css" href="css/bootstrap-responsive-tabs.css">
    <link rel="stylesheet" type="text/css" href="css/responsive.css">
    <link rel="stylesheet" type="text/css" href="css/custom.css">
    <link rel="stylesheet" type="text/css" href="css/custom1.css">



   
    <script type="text/javascript" src="js/jquery.bootstrap-responsive-tabs.js"></script>


    <script type="text/javascript" src="js/jssor.slider.min.js"></script>
   
   <script> 
    !function(f,b,e,v,n,t,s){if(f.fbq)return;n=f.fbq=function(){n.callMethod? 
    n.callMethod.apply(n,arguments):n.queue.push(arguments)};if(!f._fbq)f._fbq=n; 
    n.push=n;n.loaded=!0;n.version='2.0';n.queue=[];t=b.createElement(e);t.async=!0; 
    t.src=v;s=b.getElementsByTagName(e)[0];s.parentNode.insertBefore(t,s)}(window, 
    document,'script','//connect.facebook.net/en_US/fbevents.js'); 

    fbq('init', '538296873003766'); 
    fbq('track', "PageView");
    </script> 
    <noscript><img height="1" width="1" style="display:none" 
    src="https://www.facebook.com/tr?id=538296873003766&ev=PageView&noscript=1" 
    /></noscript> 
    



    <!-- use jssor.slider.debug.js instead for debug -->

    <script>

        jssor_1_slider_init = function() {

            

            var jssor_1_options = {

              $AutoPlay: false,

              $AutoPlaySteps: 4,

              $SlideDuration: 160,
              <?php
              if($mobile==true) {
                ?>
                $SlideWidth: 900,
                $SlideSpacing: 1,
                <?php
              } else {
                ?>
                $SlideWidth: 300,
                $SlideSpacing: 3,
                <?php
              }
              ?>
              

              $Cols: 4,

              $ArrowNavigatorOptions: {

                $Class: $JssorArrowNavigator$,

                $Steps: 4

              },

              $BulletNavigatorOptions: {

                $Class: $JssorBulletNavigator$,

                $SpacingX: 1,

                $SpacingY: 1

              }

            };

            

            var jssor_1_slider = new $JssorSlider$("jssor_1", jssor_1_options);

            

            //responsive code begin

            //you can remove responsive code if you don't want the slider scales while window resizes

            function ScaleSlider() {

                var refSize = jssor_1_slider.$Elmt.parentNode.clientWidth;

                if (refSize) {

                    refSize = Math.min(refSize, 970);

                    jssor_1_slider.$ScaleWidth(refSize);

                }

                else {

                    window.setTimeout(ScaleSlider, 30);

                }

            }

            ScaleSlider();

            $Jssor$.$AddEvent(window, "load", ScaleSlider);

            $Jssor$.$AddEvent(window, "resize", $Jssor$.$WindowResizeFilter(window, ScaleSlider));

            $Jssor$.$AddEvent(window, "orientationchange", ScaleSlider);

            //responsive code end

        };

    </script>

<style type="text/css">
    span.error {
        position: relative;
    }
    span.error span {
        position: absolute;
        width: 175px;
        top: 38px;
        left: 0px;
        background: red;
        color: #fff;
        z-index: 5;
    }
    .sug span.error span{
        top: 68px !important; 
    }
    .lname span.error span{
        left: 11.5px !important;
        width: 178.5px !important;
    }
    </style>
<script>
/*
$(document).ready(function(){
    $("#check_avail").submit(function(event){
        var count = 0;
        $(".error").remove();
        $(".required", this).each(function(){
            if($(this).val()=="") {
                $(this).before('<span class="error"><span>This is required.</span></span>');
                count++;
            }
        });
        
        if(count>0) {
            event.preventDefault();
        }
    });
});
*/
$( document ).ready(function() {
    $('.responsive-tabs').responsiveTabs({
        accordionOn: ['xs', 'sm']
    });
});
</script>
</head>

<body>

    <header>
        <div class="container">
            <div class="customer-care">
                <a href="tel:18002666700"><i class="icon-phone-sign"> 1800 266 6700</i></a>
                <i class="fa fa-envelope"> Support@bigbazaardirect.com</i>
            </div>
        </div>
    </header>
    <div class="container">

        <div class="logo">
<!--          <a class="logo navbar-btn pull-left" target="_blank" href="http://bigbazaardirect.com" title="Home">-->
            <img src="http://bigbazaardirect.com/sites/default/files/BBD-logo.png" alt="Home">
<!--          </a>-->
        </div>

    </div>

    <div class="container">

        <div class="col-md-12 col-sm-12 col-xs-12" >

            <div class="row main">

                <div class="videobg">

                    <!--p class="firstp">Don't waste your time working on someone else's dream.</p--> <p class="secondp">Create your own Success Story with Big

                        Bazaar Direct</p>

             

                </div>

                <div class="video">
                    <iframe width="400" height="250" src="https://www.youtube.com/embed/jnoL6kOmcso?autoplay=1" frameborder="0"  allowfullscreen></iframe>
                    <div class="viewmore">

                    	<a href="#jssor-header"><img src="img/viewbutton.png"></a>

                    </div>

                </div>


                    <div id="book">

                        <div id="message-booking">

                            <p><strong>Become the face of a Revolutionary Idea</strong> <br> Participate in the Big Bazar Direct contest <br> and win a gift voucher worth Rs 10,000 </p>

                        </div>

                        <form role="form" method="post" action="thankyou.php" id="check_avail" autocomplete="off">

                            <div class="row">

					                            <div class="submit-form">

					                            	<img class="shadow" src="img/shadow.png">

					                                   

					                                    <div class="listplace">
                                                            
					                                        <div class="form-group">
                                                              <?php $fname = !empty($_SESSION['f_name']) ? $_SESSION['f_name'] : ''?>
                                                                <input type="text" class="fname_booking required" name="fname_booking" id="fname_booking" placeholder="First Name" required ="" value = "<?php echo $fname;?>">
					                                        </div>

					                                    </div>

					                                    <div class="listplace lname">

					                                        <div class="form-group">
                                                                <?php $lname = !empty($_SESSION['l_name']) ? $_SESSION['l_name'] : ''?>
                                                                <input type="text" class="form-control required" name="lname_booking" id="lname_booking" placeholder="Last Name" required = "" value = "<?php echo $lname;?>">

					                                        </div>

					                                    </div>

					                           

					                                <div class="row">

					                                    <div class="col-md-12">

					                                        <div class="listplace">

					                                            <div class="form-group">
                                                                    <?php $phone = !empty($_SESSION['mobile']) ? $_SESSION['mobile'] : ''?>
                                                                    <input type="text" class="form-control required" name="mobile" id="contact_booking" placeholder="Mobile No: +91" maxlength="10" required="" value ="<?php echo $phone; ?>">

					                                            </div>

					                                        </div>

					                                    </div>

					                                    <div class="col-md-12">

					                                        <div class="listplace">

					                                            <div class="form-group">
                                                                    <?php $email_address = !empty($_SESSION['email']) ? $_SESSION['email'] : ''?>
                                                                    <input type="text" class="form-control required" name="email" id="email_booking" placeholder="Email Id" required ="" value = "<?php echo $email_address; ?>">
					                                            </div>

					                                        </div>

					                                    </div>

					                                    <div class="col-md-12">

					                                        <div class="listplace">

					                                            <div class="form-group">
                                                                   <?php $pin_code = !empty($_SESSION['pincode']) ? $_SESSION['pincode'] : ''?>  
                                                                    <input type="text" class="form-control required" name="pincode" id="contact_booking" placeholder="Pincode" maxlength="6" required ="" value = "<?php echo $pin_code;?>">

					                                            </div>

					                                        </div>

					                                    </div>

					                                    <div class="col-md-12">

					                                        <div class="listplace sug">

					                                            <div class="form-group">
                                                                  <?php $name_booking = !empty($_SESSION['name_booking']) ? $_SESSION['name_booking'] : ''?> 
                                                                  <textarea class="form-control required" name="name_booking" id="franchisee_booking" placeholder="How would you like to create your own success story with Big Bazaar Direct" required = ""><?php echo $name_booking; ?></textarea>

					                                            </div>

					                                        </div>

					                                    </div>

					                                </div>

				                                    <div class="col-md-12 col-sm-12">
				                                    	 <input type="submit" value="Submit" class="submitbutton" >

				                          

				                                    </div>

					                            	<img class="shadowb" src="img/shadowb.png">				                                   

				                                </div>

                                			</div>

										</form>


									</div>

							                  

							</div>

						</div>

					</div>


		



		





 <!-- <div class="container">

		<div  class="col-md-12"  id="tabs">

		  <ul>

		    <li><a href="#tabs-1">What is <br>  Big Bazaar Direct?</a></li>

		    <li><a href="#tabs-2">How to do <br> Business</a></li>

		    <li><a href="#tabs-3">Earning <br> Opportunities</a></li>

		    <li><a href="#tabs-4">FAQs</a></li>

		  </ul>

		  <div id="tabs-1">

		    <div class="col-md-8" ><p><b>As we all know, online retail shopping is the latest trend. Big Bazaar Direct is a revolutionary idea to 



combine online retail with the offline sales in 3 simple steps</b> <br><br>



1. Receive a tablet on Sign-up, with the entire Big Bazaar Direct product catalog.<br>



2. Sell Big Bazaar Direct products via the tablet anywhere anytime.<br>



3. Earn commission on each sale <br><br>

<b>Advantages of associating with Big Bazaar Direct:</b>

			</p>



<ul> 

    <li>Start your own business with Big Bazaar Direct & associate with India's Most Trusted 



Retail Brand </li>



<li>Expand your existing customer base and add more value to your existing business </li>



<li> Avail the offers and promotions of Big Bazaar Direct along with the widest variety of 



products </li>

</ul>

</div>



		    <div class="col-md-3 tab1-img">

		    	<img src="img/knowmore.png">

		    	<a href="#book">  </a>

		    </div>



		  </div>

		  <div id="tabs-2">

		  	<div class="col-md-8">

		  		<ul>

		  			<li> Use technology to connect with customers across India and sell anywhere, anytime</li>



 					<li>Take orders via our tablet / website.



 <li>No need to stock & deliver goods - Big Bazaar will stock & deliver them to your customer's </li>



doorstep



<li>Big Bazaar sells everything a customer needs. So, anyone can become your customer</li>

		  		</ul>

		  </div>

		  	  <div class="col-md-3 tab1-img">

		    	<img src="img/knowmore.png">

		    	<a href="#">  </a>

		    </div>

		</div>

		  <div id="tabs-3">

		  	 	<div class="col-md-8">

		  <ul> 

		   <li> By partnering with Big Bazaar Direct, you have an opportunity to grow along with us</li>



<li> Time is a major investment in this business. The more time you invest, the more you earn</li>



<li> Apart from the commission, we have great rewards and recognition programs for our Big 



Bazaar Direct Franchisee that includes foreign trips, gold coins and many more</li>

		</ul>

		  </div>

 <div class="col-md-3 tab1-img">

		    	<img src="img/knowmore.png">

		    	<a href="#">  </a>

		    </div>



		  </div>

		  <div id="tabs-4">

		   	<div class="col-md-8">

		  	<ul>

		  		<li><b>Do I need to have a shop/business location for becoming an online franchisee?</b><br>



No. You can do business from anywhere. We will give you tablet/slate, using which you can 



take orders. </li>



<li><b> How do I book orders? Do I need to buy and sell?</b><br> 

	You can sell products using our Tablet/Slate or website. Once you sign up, you will receive a 



Big Bazaar Direct tablet that will have Big Bazaar's products in it. You can use this tablet to 



show the products to your customers and book orders.</li>



<li> <b>What will be the commission and how do I get paid?</b><br>



Commission is different for different categories/product. It ranges from 3% to 15%. 



Commission of each product is mentioned in the My Account section of the tablet/website. 



The net commission is paid monthly in your bank account.</li>



<li> <b>What kind of training do I get?</b><br>



Our tablet will come with full-fledged E-learning training module which you have to go 



through. This training covers Tablet & processes, Product training and Sales & Marketing 



related training. Apart from this you can always get in touch with our sales field staff.</li>



<li> <b>Will all the products available in Big Bazaar be available in Tab/website?</b><br>



We cover almost all the categories of Big Bazaar (except food/FMCG) and those which are 



not transport worthy. New products are constantly added and we will keep you updated via 



email, SMS and on social media.</li>



		  	</ul>

</div>

 <div class="col-md-3 tab1-img">

		    	<img src="img/knowmore.png">

		    	<a href="#">  </a>

		    </div>



</div>
</div>
</div>


 -->
<div class="container">
  

      <ul class="nav nav-tabs responsive-tabs">
        <li class="active"><a href="#home1">What is Big Bazaar Direct?</a></li>
        <li><a href="#profile1">How to do Business ?</a></li>
        <li><a href="#messages1">Earning Opportunities</a></li>
        <li class="faq"><a href="#settings1">FAQs</a></li>
      </ul>

      <div class="tab-content">
        <div class="col-md-12 tab-pane active" id="home1">
        <div class="col-md-8 tab1">  
          <p><b>As we all know, online retail shopping is the latest trend. Big Bazaar Direct is a revolutionary idea to
            combine online retail with the offline sales in 3 simple steps</b> <br><br>
            1. Receive a tablet on sign-up, with the entire Big Bazaar Direct product catalog<br>
            2. Sell Big Bazaar Direct products via the tablet anywhere, anytime<br>
            3. Earn commission on each sale <br><br>
            <b>Advantages of associating with Big Bazaar Direct:</b></p>
                        
        <ul> 
            <li>Start your own business with Big Bazaar Direct & associate with India's Most Trusted Retail Brand </li>
            <li>Expand your existing customer base and add more value to your existing business </li>
            <li> Avail the offers and promotions of Big Bazaar Direct along with the widest variety of products </li>

        </ul>   
        </div>
            <div class="col-md-3 tab1-img">
                <img src="img/knowmore.png">
                <a href="#book">  </a>
            </div>
        </div>




        <div class="col-md-12 tab-pane" id="profile1">
          <div class="col-md-8 tab2">
          <ul>
            <li> Use technology to connect with customers across India and sell anywhere, anytime</li>
            <li>Take orders via our tablet / website.</li>
            <li>No need to stock & deliver goods - Big Bazaar Direct will stock & deliver them to your customer's doorstep </li>
            <li>Big Bazaar Direct sells everything a customer needs. So, anyone can become your customer</li>
          </ul>
        </div>
            <div class="col-md-3 tab1-img">
                <img src="img/knowmore.png">
                <a href="#book">  </a>
            </div>
        </div>

        <div class="col-md-12 tab-pane" id="messages1">     
        <div class="col-md-8 tab3">  
        <ul> 
           <li> By partnering with Big Bazaar Direct, you have an opportunity to grow along with us</li>
           <li> Time is a major investment in this business. The more time you invest, the more you earn</li>
           <li> Apart from the commission, we have great rewards and recognition programs for our Big 
                Bazaar Direct Franchisee's that includes foreign trips, gold coins and many more</li>
        </ul>
        </div>
            <div class="col-md-3 tab1-img">
                <img src="img/knowmore.png">
                <a href="#book">  </a>
            </div>
        </div>

        <div class="col-md-12 tab-pane" id="settings1">
        <div class="col-md-8 tab4"> 
          <ul>
            <li><b>Do I need to have a shop/business location for becoming a Big Bazaar Direct franchisee?</b><br>
                No. You can do business from anywhere. We will give you tablet/slate, using which you can 
                take orders. </li>
            <li><b> How do I book orders? Do I need to buy and sell?</b><br> 
                You can sell products using our tablet/slate or website. Once you sign up, you will receive a 
                Big Bazaar Direct tablet that will have Big Bazaar's products in it. You can use this tablet to 
                show the products to your customers and book orders.</li>
            <li> <b>What will be the commission and how do I get paid?</b><br>
                Commission is different for different categories/product. It ranges from 3% to 15%. 
                Commission of each product is mentioned in the My Account section of the tablet/website. 
                The net commission is paid monthly in your bank account.</li>
            <li> <b>What kind of training do I get?</b><br>
                Our tablet will come with a full-fledged E-learning training module which you have to go 
                through. This training covers tablet & processes, product training and Sales & Marketing 
                related training. Apart from this you can always get in touch with our sales field staff.</li>
            <li> <b>Will all the products be available in Big Bazaar Direct's tablet/website?</b><br>
                We cover almost all the categories of Big Bazaar (except food/FMCG) and those which are 
                not transport worthy. New products are constantly added and we will keep you updated via 
                email, SMS and on social media.</li>
            </ul>
            </div>
            <div class="col-md-3 tab1-img">
                <img src="img/knowmore.png">
                <a href="#book">  </a>
            </div>
            </div>
      </div>

   
</div>    

<div class="container">

<div class="jssor-header" id="jssor-header">

    <p>Video</p>

</div>

<div class="jssor-header-second">

    <p><i>"They Dreamt. They Took Risk. We Helped. They Succeeded. Watch How!" </i></p>

</div>



<div class="col-md-12" id="jssor_1" style="position: relative; margin: 0 auto; right: 0px; width: 970px; <?php if($mobile) { echo 'height: 900px;'; } else { echo 'height: 300px;'; }?>overflow: hidden; visibility: hidden;">

        

        <div data-u="loading" style="position: absolute; top: 0px; left: 0px;">

            <div style="filter: alpha(opacity=70); opacity: 0.7; position: absolute; display: block; top: 0px; left: 0px; width: 100%; height: 100%;"></div>

            <div style="position:absolute;display:block;background:url('img/loading.gif') no-repeat center center;top:0px;left:0px;width:100%;height:100%;"></div>
       


        </div>

        <div data-u="slides" style="cursor: default; position: relative; top: 20px; left:33px; width: 909px; min-height: 900px; overflow: hidden;">

            <div style="display: none;">

                <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/yKK5KTfN9TY" frameborder="0" allowfullscreen></iframe>
         
            </div>

            <div style="display: none;">

                <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/ahQqn-ojk-k" frameborder="0" allowfullscreen></iframe>
      
            </div>

            <div style="display: none;">

              <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/1b1vjeJ1YwQ" frameborder="0" allowfullscreen></iframe>
       
            </div>

            <div style="display: none;">

                <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/ypDV8Eztnw8" frameborder="0" allowfullscreen></iframe>
             
                </p>

            </div>

            <div style="display: none;">

             <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/F4N4_P7TbQk" frameborder="0" allowfullscreen></iframe>

            </div>

            <div style="display: none;">

               <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/6wWaxdcDZ6k" frameborder="0" allowfullscreen></iframe>

            </div>

            <div style="display: none;">

              <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/PKSvPkqbtNw" frameborder="0" allowfullscreen></iframe>

            </div>

            <div style="display: none;">

              <iframe <?php if($mobile) { echo 'width="900px" height="900px"'; } else { echo 'width="300px" height="263px"'; } ?> src="https://www.youtube.com/embed/qI75Lfaycik" frameborder="0" allowfullscreen></iframe>

            </div>

           

        </div>

        <!-- Bullet Navigator -->

 

        <!-- Arrow Navigator -->

        <span data-u="arrowleft" class="jssora03l" style="top:123px;left:8px;width:55px;height:55px;" data-autocenter="2"></span>

        <span data-u="arrowright" class="jssora03r" style="top:123px;left:93.5%;width:55px;height:55px;" data-autocenter="2"></span>

        <a href="http://www.jssor.com" style="display:none">Jssor Slider</a>

    </div>

    </div>

    <script>

        jssor_1_slider_init();

    </script>





 

<!--3 -->

<div class="container">

<div class="testimonial-header" id="testimonial-header">

    <p>Testimonial</p>

</div>

<div class="testimonial-header-second">

    <p><i>"Here's what our associates have to say about us" </i></p>

</div>

	<div class="cd-testimonials-wrapper cd-container">

	<ul class="cd-testimonials">
        


		<li>
			<div id="demo" class="showcase">
				<section id="examples">


					<!-- content -->
					<div id="content-4" class="content">
						<p>I saw an interview of Mr. Kishore Biyani on the news channel about this new business model and 
                            without doing much research I signed up as Big Bazaar Direct franchisee. I thought it's a big 
                            opportunity to associate with such a big brand in the market and started my business in March 
                            this year even without enquiring about the commission structure etc. I run an electronics shop 
                            and after becoming Big Bazaar Direct vendor, I am able to offer much wider range of electronics 
                            with all other range of offers. So, the customers at my shop are spoilt for choices from ethnic 
                            dresses to home decor products, to household items and electronics, it's become one stop shop 
                            for all their needs.</p>
						<p>During events and promotions my entire family works together to maximise sales. It's easy and 
                            Simple to do business through tab. I never knew that I could be so passionate about sales and 
                            business. I promote the products and offers in my social circle and existing customers of my 
                            shop.</p>
					</div>
					<div class="cd-author">
						<img src="http://bigbazaardirect.com/sites/all/themes/bbdlms/images/testimonial/dhiraj.jpg" alt="Author image">
					</div>
					<div id="cd-author-info">
					<ul class="cd-author-info" style="list-style-type:none;">
						<li style="color:000;">Sandip Sanghavi</li>
						<li style="color:#ff6600;">
						Big Bazar Direct Franchisee, Bhuj, Gujarat </li>
					</ul>
					</div>
					<div class="arrowdown">
						<img src="http://snag.gy/4RtRG.jpg">
					</div>
				</section>
			</div>
		</li>



		<li>
<div id="demo" class="showcase">
        <section id="examples">
            
            
            <!-- content -->
            <div id="content-4" class="content">
                <p>I became Big Bazaar Direct vendor in March this year. I was working with an organization in 
                   Noida and saw the ad in the newspaper. I did more research about the business model and 
                   decided to quit my job to become a full time Big Bazaar Direct vendor in my hometown in 
                   Jodhpur. For me, this business opportunity was a value for money business deal. It's a great 
                   brand name to start a business with, it enjoys a very good reputation in the market.</p><br><br>



            <p>Muje lag raha tha itne kum investment main kaafi bade brand name ke sath judne ka mauka hai 
            aur bohot zyaada products bechne ke liye mil rahe hai. Plus, muje delivery ka koi tension nahi 
            hai, Big Bazaar Direct ki team directly orders mere customers ke ghar deliver karte hai. Main bus 
            sales maximize karne ke tarike sochta hun.
            </p></div>


			<div class="cd-author">

				<img src="http://bigbazaardirect.com/sites/all/themes/bbdlms/images/testimonial/tonyP.jpg" alt="Author image">

				

			</div>
            <div id="cd-author-info">
            <ul class="cd-author-info" style="list-style-type:none;">

                    <li style="color:000;">Tony Purohit</li>

                    <li style="color:#ff6600;">Big Bazaar Direct Franchisee, Jodhpur, Rajasthan</li>

                </ul>
                </div>
              <div class="arrowdown">
                    <img src="http://snag.gy/4RtRG.jpg">
            </div>
            </section>
            </div>



		</li>



		<li>

			<div id="demo" class="showcase">
        <section id="examples">
            
            
            <!-- content -->
            <div id="content-4" class="content">
                <p>I was in search for an opportunity where I could be recognized in the community I live in. This is 
                    when I came across Big Bazaar Direct's advertisement in the newspaper. I did some research 
                    and spoke to the Big Bazaar Direct team to understand how this unique business module works. 
                    Fortunately, I realized soon enough that this kind of business model has the potential to 
                    challenge the Wal-Mart's of the world and will help India to regain its financial strength to lead the 
                    world. I worked hard and the Big Bazaar Direct team helped me in promoting my business 
                    through promotional materials via WhatsApp and SMS. This helped me expand my existing 
                    customer base. I am now a known name in my community and I strive to cater them with the 
                    wide assortment of every day-use products from Big Bazaar Direct.<p><br><br>


<!-- 
           	<p> During events and promotions my entire family works together to maximise sales. It's easy and simple to do business through tab. I am a homemaker and now I balance home and business both with great efficiency.
           	I never knew that I could be so passionate about sales and business. I promote the products and offers in my social circle and existing customers of my shop..</p> -->
            </div>

			<div class="cd-author">

				<img src="http://bigbazaardirect.com/sites/all/themes/bbdlms/images/testimonial/anandG.jpg" alt="Author image">

			

			</div>
            
                <ul class="cd-author-info" style="list-style-type:none;">

                    <li style="color:000;">Anand Mukund Gadre</li>

                    <li style="color:#ff6600;">Big Bazaar Direct Franchisee, Nagpur, Maharastra</li>

                </ul>
              <div class="arrowdown">
                    <img src="http://snag.gy/4RtRG.jpg">
            </div>
            </section>
            </div>

		</li>

		

	</ul> <!-- cd-testimonials -->





</div>
<!--  -->
<script src="js/masonry.pkgd.min.js"></script>

<script src="js/jquery.flexslider-min.js"></script>

<script src="js/main.js"></script>
<!--  -->


        <div class="knowmorebottom">

    <a href="#book"><img src="img/knowmorebutton.png"></a>

</div>







</div> <!-- cd-testimonials-all -->
   

<div class="container">

	<div class="footer">

	<ul style="list-style-type:none;">

		

		<li class="contactf">Contact Us</li>	

		<li class="call-mail"><i class="icon-phone-sign"> 1800 266 6700</i></li>

		<li class="call-mail"><i class="fa fa-envelope"> Support@bigbazaardirect.com</i></li>			

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



<!-- <script src="js/jquery-2.1.1.js"></script> -->

<script src="js/masonry.pkgd.min.js"></script>

<script src="js/jquery.flexslider-min.js"></script>

<script src="js/main.js"></script>

	

	

 

</div>


<?php
    if(isset($_SESSION['error'])) {
        ?>
        <script type="text/javascript">alert('<?php echo $_SESSION["error"]; ?>');</script>
        <?php
        unset($_SESSION['error']);
        session_destroy();
    }
    ?>






<!-- <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>

 -->



















</body>

</html>
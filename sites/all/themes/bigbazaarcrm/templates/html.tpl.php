<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>  
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->

</head>
<body<?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php
  /*$pop_bg =  drupal_get_path('theme','bigbazaarcrm').'/images/roadblock_bg_2.png';
  $pop_close =  drupal_get_path('theme','bigbazaarcrm').'/images/roadblock_close.png';
   if(drupal_is_front_page()) {
    echo '<div class="home_light_box">
  <span><img src="'.$pop_close.'"/></span>
  <img src="'.$pop_bg.'"/>
</div>
<div class="bgshadow"> </div>';
   }*/
  ?>
</body>
</html>
 
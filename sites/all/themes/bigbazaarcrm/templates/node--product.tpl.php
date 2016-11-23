 
  
<div class="product-detail">
  <div class="prod-img-l">
    <div class="pmain-img"><img src= "<?php print_r($content['field_tile_image']['#items']['0']['value']); ?>"/></div>
  </div>
  <div class="prod-detail-r">
    <div class="p-data1">
      <h1 id="page-title"><?php print($title); ?></h1>
              <?php print($top_features); ?>
    </div>
 <?php if(!empty($content['field_product_short_description']['#items']['0']['value'])) { ?>
    <div class="p-data2">
      <h1 class="about-p">About</h1>
      <?php  print_r(render($content['field_product_short_description'])); print $test;?>
    </div>
<?php } ?>
    <div class="p-buy-btn">
	      <div class="p-data3">
        <table width="100%">
          <tr>
            <td class="p-mrp">
              <div class="mrp-cross"><div class="WebRupee"><span>Rs.&nbsp;</span> </div><?php print_r(render($content['field_mrp'])); ?></div>
              <div class="mrp-actual"><div class="WebRupee">Rs.&nbsp;</div><?php print_r(render($content['field_selling_price_'])); ?></div>
<?php
$mrp = $content['field_mrp']['#items']['0']['value'];
$sp =  $content['field_selling_price_']['#items']['0']['value'];
$saving = $mrp - $sp;
?>
              <div class="mrp-save"><div class="you-s">You Save:&nbsp;</div> <div class="WebRupee">Rs.&nbsp;</div><?php print_r($saving); ?></div>
            </td>
          </tr>
          <tr>
              <td><div class="menu-franchise">
<a href="/franchise"><img src="/sites/all/themes/bigbazaarcrm/images/new_home/buy-from-franchisee.png"></a></div>
             </td>
         </tr>
         </table>
      </div>
    </div>
  </div>
   <?php if(!empty($product_spec)) { ?>
   <div class="product_specification"><h1>Product Specification</h1><?php print_r($product_spec); ?></div>
 <?php } ?>
</div>

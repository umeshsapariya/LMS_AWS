<style>
table {
	border: 0;
}
table td {
	padding: 5px 0px;
}
table th {
	padding: 0px;
	border: none;
	background: none;
}
table td label {
	border: none;
}
h3,h4{ padding: 0;margin: 0;}
hr {color:sienna;}
h1 {font-weight: bold; color: black;}
h2 {font-weight: bold; color: black;}
label {font-weight: bold; color: black; clear: both;}
span {font-weight: bold; color: gray; text-transform: capitalize;}
.desc {font-size: 10px;}
p.mandatory{
  /*float: right;*/
   /* margin-right: 500px;*/
   /* margin-top: -100px;*/
    margin-left:200px;
		 font-size: 11px;
}
</style>

<?php

global $base_url;
  /*
  $app_id = db_select("bigbazaarcrm_applications", "ba")
          ->fields("ba", array("app_id"))
          ->condition("nid", $node->nid)
          ->execute()
          ->fetchField();*/
	if(isset($node->field_application_number['und'][0]['value'])) {
		$sno = $node->field_application_number['und'][0]['value'];
	}else {
		$sno = variable_get('application_node_'.$node->nid);
		variable_del('application_node_'.$node->nid);
	}
?>
<div class="outer_main">
	<table><tr><td style="width:720px;"></td><td><img src="<?php echo $base_url.'/sites/default/files/logo.jpg'; ?>" alt="Big Bazaar" height="86" width="202"><td></tr></table>
  <h1 style="background:#CCCCCC; border-top: 5px solid #EE5E2C;"> Franchisee Application Form (Online)</h1>
  <hr />
<table class="additional" style="width:720px;border-collapse: collapse;">
	<tr>
		<td><h3 style="float: left;text-align: left;">Applicant Details:</h3></td>
		<td></td>
		<td><label style="float: right;text-align: right;">Serial No: <?php print $sno;?></label></td>
	</tr>
		<tr>
		<td> <?php  if(isset($node->field_title['und'][0]['value'])) { print_r($node->field_title['und'][0]['value']); } ?> First Name:</td> <td><?php   if(isset($node->title)) { print_r($node->title); } ?> </td>
		<td rowspan="4" style="width: 150px;border: 1px solid #000;text-align: center;">
		<label>Photo</label> <br/>
		<label style="padding-top: 40px;">Sign Across </label><br/>
		</td>
	</tr>
	<tr>
		<td>Middle Name:</td> <td><?php   if(isset($node->field_middle_name[LANGUAGE_NONE][0]['value'])) { print_r($node->field_middle_name[LANGUAGE_NONE][0]['value']); } ?> </td>
	</tr>
	<tr>
		<td>Last Name: </td> <td><?php   if(isset($node->field_last_name[LANGUAGE_NONE][0]['value'])) { print_r($node->field_last_name[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Date Of Birth: </td> <td><?php   if(isset($node->field_date_of_birth[LANGUAGE_NONE][0]['value'])) {	print_r(date_format(date_create($node->field_date_of_birth[LANGUAGE_NONE][0]['value']),'d-m-Y')); } ?></td>
	</tr>
	<tr>
		<td>Applicant's Type:  </td> <td><?php   if(isset($node->field_applicant_type[LANGUAGE_NONE][0]['value'])) { print_r($node->field_applicant_type[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Address 1:  </td> <td><?php  if(isset($node->field_address_1[LANGUAGE_NONE][0]['value'])) { print_r($node->field_address_1[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Address 2 : </td> <td><?php  if(isset($node->field_address_1[LANGUAGE_NONE][0]['value'])) { print_r($node->field_address_1[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Land mark 1 : </td> <td><?php  if(isset($node->field_landmark[LANGUAGE_NONE][0]['value'])) { print_r($node->field_landmark[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>City: </td> <td><?php  if(isset($node->	field_city[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_city[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Pincode: </td> <td><?php  if(isset($node->field_pin_code[LANGUAGE_NONE][0]['value'])) { print_r($node->field_pin_code[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Mobile 1: </td> <td><?php  if(isset($node->	field_mobile_1[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_mobile_1[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Mobile 2 :</td> <td><?php  if(isset($node->field_mobile_2[LANGUAGE_NONE][0]['value'])) { print_r($node->field_mobile_2[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>E-mail :</td> <td><?php  if(isset($node->	field_email[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_email[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Tel No :</td> <td><?php  if(isset($node->field_landmark[LANGUAGE_NONE][0]['value'])) { print_r($node->field_tel_no[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>

<hr style="clear: both;display: block;"/>
<h3>Additional Information : </h3>
<table style="width: 70%;float: left;">
	<tr>
		<td>Existing retailer or trader :</td> <td><?php  if($node->field_existing_retailer_trader[LANGUAGE_NONE][0]['value'] == 1) { echo 'YES'; } else { echo 'No'; } ?></td>
	</tr>
	<tr>
		<td>Do you operate from :</td> <td><?php  if(isset($node->field_do_you_operate_from[LANGUAGE_NONE][0]['value'])) { print_r($node->field_do_you_operate_from[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Involvements of Agency / MLM :</td> <td><?php  if($node->field_involvement_in_agency_mlm[LANGUAGE_NONE][0]['value'] == 1) { echo 'YES'; } else { echo 'No'; } ?></td>
	</tr>
	<tr>
		<td>Leader of any Society, Community or Group :</td> <td><?php  if($node->	field_leader_of_society_commity[LANGUAGE_NONE][0]['value'] == 1) { echo 'YES'; } else { echo 'No'; } ?></td>
	</tr>
	<tr>
		<td>Housewife :</td> <td><?php  if($node->field_house_wife[LANGUAGE_NONE][0]['value'] == 1) { echo 'YES'; } else { echo 'No'; } ?></td>
	</tr>
	<tr>
		<td>Operating in present location since :</td> <td><?php  if(isset($node->field_no_of_yrs_present_on_loc[LANGUAGE_NONE][0]['value'])) { print_r($node->field_no_of_yrs_present_on_loc[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Jurisdiction of police station :</td> <td><?php  if(isset($node->field_jurisdiction_police_stn[LANGUAGE_NONE][0]['value'])) { print_r($node->field_jurisdiction_police_stn[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>
<hr style="clear: both;display: block;"/>
<h3>Shop / Business / Establishment Details : </h3>

<table style="width: 70%;float: left;">
	<tr>
		<td colspan="2">Details of Proprietor / Partners / Directors </br> Same as above</td> 
	</tr>
	<tr>
		<td>Name of Establishment:</td> <td><?php  if(isset($node->field_name_of_establishment[LANGUAGE_NONE][0]['value'])) { print_r($node->field_name_of_establishment[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Address 1:</td> <td><?php  if(isset($node->field_address_line_1[LANGUAGE_NONE][0]['value'])) { print_r($node->field_address_line_1[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Address 2 :</td> <td><?php  if(isset($node->	field_address_line_2[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_address_line_2[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Land mark 1 :</td> <td><?php  if(isset($node->	field_shop_landmark[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_shop_landmark[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>City:</td> <td><?php  if(isset($node->field_shop_in_city[LANGUAGE_NONE][0]['value'])) { print_r($node->field_shop_in_city[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Pincode:</td> <td><?php  if(isset($node->field_shop_pin_code[LANGUAGE_NONE][0]['value'])) { print_r($node->field_pin_code[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Mobile 1: </td> <td><?php  if(isset($node->field_shop_mobile_1[LANGUAGE_NONE][0]['value'])) { print_r($node->	field_shop_pin_code[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Mobile 2 : </td> <td><?php  if(isset($node->field_shop_mobile_2[LANGUAGE_NONE][0]['value'])) { print_r($node->field_shop_mobile_1[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> E-mail : </td> <td><?php  if(isset($node->	field_shop_email[LANGUAGE_NONE][0]['value'])) { print_r($node->field_shop_mobile_2[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Tel No :  </td> <td><?php  if(isset($node->field_shop_tel_no[LANGUAGE_NONE][0]['value'])) { print_r($node->field_shop_email[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>

<h4 style="clear: both;display: block;font-size:12px;">Current Oprations : </h4>
<table style="width: 70%;float: left;">
	<tr>
		<td> Area In Sq. Ft. :  </td> <td><?php  if(isset($node->field_area[LANGUAGE_NONE][0]['value'])) { print_r($node->field_area[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Property Type : </td> <td><?php  if(isset($node->field_select[LANGUAGE_NONE][0]['value'])) { print_r($node->field_select[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>

<h4 style="clear: both;display: block;font-size:12px;">Branding Feasibility : </h4>
<table style="width: 70%;float: left;">
	<tr>
		<td> NEON / FLEX Board Size (Inside / Outside):  </td> <td><?php  if($node->field_neon_flex_board_size[LANGUAGE_NONE][0]['value'] == 1) { echo 'YES'; } else { echo 'No'; } ?></td>
	</tr>
	<tr>
		<td> Location: </td> <td><?php  if(isset($node->field_location[LANGUAGE_NONE][0]['value'])) { print_r($node->field_location[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>

<hr style="clear: both;display: block;"/>
<h3>Bank Information : </h3>
<table style="width: 70%;float: left;">
	<tr>
		<td>Bank Name:</td> <td><?php  if(isset($node->field_bank_name[LANGUAGE_NONE][0]['value'])) { print_r($node->field_bank_name[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td>Branch: </td> <td><?php  if(isset($node->field_branch[LANGUAGE_NONE][0]['value'])) { print_r($node->field_branch[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> A/c No: </td> <td><?php  if(isset($node->field_a_c_no[LANGUAGE_NONE][0]['value'])) { print_r($node->field_a_c_no[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> Type of A/C: </td> <td><?php  if(isset($node->field_type_of_account[LANGUAGE_NONE][0]['value'])) { print_r($node->field_type_of_account[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> IFSC Code: </td> <td><?php  if(isset($node->field_ifsc_code[LANGUAGE_NONE][0]['value'])) { print_r($node->field_ifsc_code[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>

<hr style="clear: both;display: block;"/>
<h3>Document Submitted : </h3>
<table style="width: 70%;float: left;">
	<tr>
		<td colspan="2">Cancelled Chaque: <br/>Passport size photograph:</td>
	</tr>
</table>


<table style="width: 70%;float: left;">
	<tr>
		<td> <strong>Photo ID Proof:</strong> </td> <td> <?php  if(isset($node->field_photo_id_proof[LANGUAGE_NONE][0]['value'])) { print_r($node->field_photo_id_proof[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
	<tr>
		<td> <strong>Address Proof: </strong></td> <td> <?php  if(isset($node->field_photo_id_proof[LANGUAGE_NONE][0]['value'])) { print_r($node->field_photo_id_proof[LANGUAGE_NONE][0]['value']); } ?></td>
	</tr>
</table>
<hr style="clear: both;display: block;"/>
  <div>
    <div class="desc">
    <label> Declaration : </label><br/>
  I hereby declare that the details given herein are true, correct and complete to the best of my knowledge and belief, the photo copy of the documents submitted along with this application are genuine and belong to the applicant. I
  hearby undertake to promptly inform Future Value Retail Limited (FVRL) in writing, of any changes in the information provided herein above and agree and accept that FVRL is not liable or responsible for any losses, costs, damages
  arising out of any actions undertaken or activities performed by FVRL on the basis of the information provided by me as also due to my not intimating / delay in intimating such changes. I hereby authorize FVRL to disclose, share,
  remit in any form, mode or manner, all / any of the information provided by me. I hereby agree to provide any additional information / documentation that may be required by FVRL, in connection with this Form. I also agree that
  FVRL has the right to reject my application form on any ground without any reason and I understand that the money paid towards the application is non refundable
    </div>
    <div class="desc">Once your form is selected, you will be called for personal interview. Passing it, we will sign franchisee agreement with you and you will have to pay 1.5 Lacs as refundable security deposit and 1.5 Lacs for franchise fees. For more details, visit our website <a href="http://www.bigbazaardirect.com">www.bigbazaardirect.com</a>
      <div><div></div>Applicant's signature<input type="text"/></div>
    </div>
  </div>
  
  <div>
    <label>Don't Forget : </label><br/>
    <div class="desc">
    Self attest, write the application form number behind the 2nd Photograph, Photo ID Proof and Address Proof attached/ submitted along with the application form. Kindly fill-up and complete the form in all respects, sign it and send
  along with required proof of documents to Big Bazaar Direct, 4th floor Future Retail Home Office, 247 Park, Tower C, L.B.S. Marg, Vikhroli (West), Mumbai - 400 083, Maharashtra, India. Or visit the nearest collection center for more
  details call on 922 330 5000 Or visit www.bigbazaardirect.com for more details.
    </div>
  </div>

</div>


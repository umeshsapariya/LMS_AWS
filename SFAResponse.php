<?php
include("Sfa/EncryptionUtil.php");


		 $strMerchantId = "96009295";
		 $astrFileName = getcwd()."/bankkey/96009295.key";
		 $astrClearData;
		 $ResponseCode = "";
		 $Message = "";
		 $TxnID = "";
		 $ePGTxnID = "";
	         $AuthIdCode = "";
		 $RRN = "";
		 $CVRespCode = "";
		 $Reserve1 = "";
		 $Reserve2 = "";
		 $Reserve3 = "";
		 $Reserve4 = "";
		 $Reserve5 = "";
		 $Reserve6 = "";
		 $Reserve7 = "";
		 $Reserve8 = "";
		 $Reserve9 = "";
		 $Reserve10 = "";


		 if($_POST){

			if($_POST['DATA']==null){
				print "null is the value";
			}
			 $astrResponseData=$_POST['DATA'];
			 $astrDigest = $_POST['EncryptedData'];
			 $oEncryptionUtilenc = 	new 	EncryptionUtil();
			 $astrsfaDigest  = $oEncryptionUtilenc->getHMAC($astrResponseData,$astrFileName,$strMerchantId);

			if (strcasecmp($astrDigest, $astrsfaDigest) == 0) {
			 parse_str($astrResponseData, $output);
			 if( array_key_exists('RespCode', $output) == 1) {
			 	$ResponseCode = $output['RespCode'];
			 }
			 if( array_key_exists('Message', $output) == 1) {
			 	$Message = $output['Message'];
			 }
			 if( array_key_exists('TxnID', $output) == 1) {
			 	$TxnID=$output['TxnID'];
			 }
			 if( array_key_exists('ePGTxnID', $output) == 1) {
			 	$ePGTxnID=$output['ePGTxnID'];
			 }
			 if( array_key_exists('AuthIdCode', $output) == 1) {
			 	$AuthIdCode=$output['AuthIdCode'];
			 }
			 if( array_key_exists('RRN', $output) == 1) {
			 	$RRN = $output['RRN'];
			 }
			 if( array_key_exists('CVRespCode', $output) == 1) {
			 	$CVRespCode=$output['CVRespCode'];
			 }
			 if( array_key_exists('Reserve1', $output) == 1) {
				$Reserve1 = $output['Reserve1'];
			 }

			 if( array_key_exists('Reserve2', $output) == 1) {
			 	$Reserve2 = $output['Reserve2'];
			 }
			 if( array_key_exists('Reserve3', $output) == 1) {
			 	$Reserve3 = $output['Reserve3'];
			 }

			 if( array_key_exists('Reserve4', $output) == 1) {
			 	$Reserve4 = $output['Reserve4'];
			 }

			 if( array_key_exists('Reserve5', $output) == 1) {
			 	$Reserve5 = $output['Reserve5'];
			 }
			 if( array_key_exists('Reserve6', $output) == 1) {
			 	$Reserve6 = $output['Reserve6'];
			 }

			 if( array_key_exists('Reserve7', $output) == 1) {
			 	$Reserve7 = $output['Reserve7'];
			 }
			 if( array_key_exists('Reserve8', $output) == 1) {
			 	$Reserve8 = $output['Reserve8'];
			 }

			 if( array_key_exists('Reserve9', $output) == 1) {
			 	$Reserve9 = $output['Reserve9'];
			 }
			 if( array_key_exists('Reserve10', $output) == 1) {
			 	$Reserve10 = $output['Reserve10'];
			 }
			}
		 }
	print "<h3>Response Code:: $ResponseCode <br>";
	print "<h3>Response Message:: $Message <br>";
	print "<h3>Auth ID Code:: $AuthIdCode <br>";
	print "<h3>RRN:: $RRN<br>";
	print "<h3>Transaction id:: $TxnID<br>";
	print "<h3>Epg Transaction ID:: $ePGTxnID<br>";
	print "<h3>CV Response Code:: $CVRespCode<br>";
	print "<h3>Reserve Filed 1:: $Reserve1<br>";
	print "<h3>Reserve Filed 2:: $Reserve2<br>";
	print "<h3>Reserve Filed 3:: $Reserve3<br>";
	print "<h3>Reserve Filed 4:: $Reserve4<br>";
	print "<h3>Reserve Filed 5:: $Reserve5<br>";
	print "<h3>Reserve Filed 6:: $Reserve6<br>";
	print "<h3>Reserve Filed 7:: $Reserve7<br>";
	print "<h3>Reserve Filed 8:: $Reserve8<br>";
	print "<h3>Reserve Filed 9:: $Reserve9<br>";
	print "<h3>Reserve Filed 10:: $Reserve10<br>";





?>

-- SUMMARY --

Commerce ICICI integrates ICICI payment gateway(a leading payment gateway) in
India with Drupal Commerce. This module will add a new payment method ICICI
payment under payment methods settings(admin/commerce/config/payment-methods).

-- REQUIREMENTS --

* Drupal commerce: http://drupal.org/project/commerce
* commerce_payment module
* commerce_ui
* commerce_order

-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.
* Get merchant account from ICICI Payseal.
* Get bankkey as well as php library folder.
* Copy Sfa folder + SFAResponse.php + sfa.properties and put it in your Drupal
  root folder (This is for initial module version. This will go to libraries
  folder in future)
* Get bankkey which will be in XXXXXXXX.key and put it in
  sites/all/modules/commerce_icici/ (This wil also change in future. It will be
  moved to libraries in future).
* Edit sfa.properties file and set Key.Directory attribute. Currently it will
  be sites/all/modules/commerce_icici/bankkey/. Also set
  OS.Type=LINUX(for linux OS) or OS.Type=NT(for windows os).

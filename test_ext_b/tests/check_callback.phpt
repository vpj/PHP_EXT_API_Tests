--TEST--
Test extension API
--FILE--
<?php
var_dump(check_callback(0, 100, 120));
var_dump(check_callback(0, 2000000000, 1999999999));
var_dump(check_callback(1, 100, 120));
var_dump(check_callback(1, 2000000000, 1999999999));
var_dump(check_callback(2, 100, 120));

var_dump(check_latest_callback(0, 100, 120));
var_dump(check_latest_callback(0, 2000000000, 1999999999));
var_dump(check_latest_callback(1, 100, 120));

var_dump(check_empty_callback(1, 100, 120));
 ?>
--EXPECT--
Extension: eapi_test - 16777216
int(220)
Extension: eapi_test - 16777216
int(-294967297)
Extension: eapi_test - 16842752
int(220)
Extension: eapi_test - 16842752
int(0)
string(13) "Not available"
Extension: eapi_test - 16842752
int(220)
Extension: eapi_test - 16842752
int(0)
string(13) "Not available"
int(1)

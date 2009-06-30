--TEST--
Test extension API
--FILE--
<?php
var_dump(check_api('ext_api_test', '1.0.0.0', 100, 120));
var_dump(check_api('ext_api_test', '1.0.0.0', 2000000000, 1999999999));
var_dump(check_api('ext_api_test', '1.1.0.0', 100, 120));
var_dump(check_api('ext_api_test', '1.1.0.0', 2000000000, 1999999999));
var_dump(check_api('ext_api_test', '1.1.2.0', 100, 120));
var_dump(check_api('ext_api_tst', '1.1.0.0', 100, 120));
 ?>
--EXPECT--
int(220)
int(-294967297)
int(220)
int(0)
string(13) "Not available"
string(13) "Not available"

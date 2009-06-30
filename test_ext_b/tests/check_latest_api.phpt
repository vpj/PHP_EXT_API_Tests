--TEST--
Test extension API
--FILE--
<?php
var_dump(check_latest_api('ext_api_test', 100, 120));
var_dump(check_latest_api('ext_api_test', 2000000000, 1999999999));
var_dump(check_latest_api('ext_aspi_test', 100, 120));
var_dump(check_latest_api('ext_api_tst', 100, 120));
 ?>
--EXPECT--
int(220)
int(0)
string(13) "Not available"
string(13) "Not available"

--TEST--
Test extension API
--FILE--
<?php
var_dump(check_callback(0, 100, 120));
var_dump(check_callback(0, 2000000000, 1999999999));
var_dump(check_callback(1, 100, 120));
var_dump(check_callback(1, 2000000000, 1999999999));
var_dump(check_callback(2, 100, 120));
var_dump(check_callback(2, 100, 120));
 ?>
--EXPECT--
int(220)
int(-294967297)
int(220)
int(0)
string(13) "Not available"
string(13) "Not available"

--TEST--
Test extension API
--FILE--
<?php
var_dump(check_version_to_text(16014866));
var_dump(check_version_to_int('0.244.94.18'));
var_dump(check_version_to_text(0xffffffff));
var_dump(check_version_to_int('255.255.255.255'));
var_dump(check_version_to_text(0x0));
var_dump(check_version_to_int('0.0.0.0'));
 ?>
--EXPECT--
string(11) "0.244.94.18"
int(16014866)
string(15) "255.255.255.255"
int(-1)
string(7) "0.0.0.0"
int(0)

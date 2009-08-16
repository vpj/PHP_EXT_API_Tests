--TEST--
Test extension API
--FILE--
<?php
var_dump(check_empty_callback(1, 100, 120));
dl('test_ext_dl2.so');
var_dump(check_empty_callback(1, 100, 120));
dl('test_ext_dl.so');
var_dump(check_empty_callback(1, 100, 120));
 ?>
--EXPECT--
int(1)
dl2 callback (eapi_test) (16777216)
dl2 empty callback
int(2)
dl callback
dl2 callback (eapi_test_dl) (16842752)
dl2 empty callback
int(3)

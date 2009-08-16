--TEST--
Test extension API
--FILE--
<?php
var_dump(check_empty_callback(1, 100, 120));

/*dl('/home/varuna/php/test/test_ext_dl/modules/test_ext_dl.so');*/
dl('test_ext_dl.so');
var_dump(check_empty_callback(1, 100, 120));
 ?>
--EXPECT--
int(1)
dl callback
int(2)

--TEST--
Test extension API
--FILE--
<?php

function output_version_list($vl)
{
	var_dump($vl);

	foreach($vl as $v)
	{
		echo dechex($v) . "\n";
	}

	echo "\n";
}

output_version_list(check_find_versions('eapi_test2', hexdec('00000100'), hexdec('0000ff00')));
output_version_list(check_find_versions('eapi_test2', hexdec('01000100'), hexdec('ff000000')));
output_version_list(check_find_versions('eapi_test2', hexdec('01000101'), hexdec('000000ff')));
 ?>
--EXPECT--
array(2) {
  [0]=>
  int(33554689)
  [1]=>
  int(16777474)
}
2000101
1000102

array(4) {
  [0]=>
  int(16777731)
  [1]=>
  int(16777216)
  [2]=>
  int(16777474)
  [3]=>
  int(16777217)
}
1000203
1000000
1000102
1000001

array(2) {
  [0]=>
  int(33554689)
  [1]=>
  int(16777217)
}
2000101
1000001


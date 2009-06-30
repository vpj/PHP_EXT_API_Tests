#ifndef PHP_TEST_EXT_B_H
#define PHP_TEST_EXT_B_H 1

#define PHP_TEST_EXT_B_VERSION "1.0"
#define PHP_TEST_EXT_B_EXTNAME "test_ext_b"

PHP_FUNCTION(test_extension_api);
PHP_FUNCTION(check_api);
PHP_FUNCTION(check_callback);
PHP_FUNCTION(check_version_to_text);
PHP_FUNCTION(check_version_to_int);
PHP_FUNCTION(check_latest_api);
PHP_MINIT_FUNCTION(test_ext_b);

extern zend_module_entry test_ext_b_module_entry;
#define phpext_test_ext_b_ptr &test_ext_b_module_entry

#endif


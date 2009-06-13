#ifndef PHP_TEST_EXT_A_H
#define PHP_TEST_EXT_A_H 1

#define PHP_TEST_EXT_A_VERSION "1.0"
#define PHP_TEST_EXT_A_EXTNAME "test_ext_a"

PHP_MINIT_FUNCTION(test_ext_a);
PHP_MSHUTDOWN_FUNCTION(test_ext_a);

extern zend_module_entry test_ext_a_module_entry;
#define phpext_test_ext_a_ptr &test_ext_a_module_entry

struct _SAMPLE_EXT_API {
	int (*sum)(int, int);
	int code;
};

typedef struct _SAMPLE_EXT_API SAMPLE_EXT_API;

#endif


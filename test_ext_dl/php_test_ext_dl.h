#ifndef PHP_TEST_EXT_DL_H
#define PHP_TEST_EXT_DL_H 1

#define PHP_TEST_EXT_DL_VERSION "1.0"
#define PHP_TEST_EXT_DL_EXTNAME "test_ext_dl"

PHP_MINIT_FUNCTION(test_ext_dl);
PHP_MSHUTDOWN_FUNCTION(test_ext_dl);
PHP_RINIT_FUNCTION(test_ext_dl);

extern zend_module_entry test_ext_dl_module_entry;
#define phpext_test_ext_dl_ptr &test_ext_dl_module_entry

struct _SAMPLE_EXT_API {
	int (*mul)(int, int);
	int code;
};

typedef struct _SAMPLE_EXT_API SAMPLE_EXT_API;

#endif


#ifndef PHP_TEST_EXT_DL2_H
#define PHP_TEST_EXT_DL2_H 1

#define PHP_TEST_EXT_DL2_VERSION "1.0"
#define PHP_TEST_EXT_DL2_EXTNAME "test_ext_dl2"

PHP_MINIT_FUNCTION(test_ext_dl2);
PHP_MSHUTDOWN_FUNCTION(test_ext_dl2);
PHP_RINIT_FUNCTION(test_ext_dl2);

extern zend_module_entry test_ext_dl2_module_entry;
#define phpext_test_ext_dl2_ptr &test_ext_dl2_module_entry

struct _SAMPLE_EXT_API {
	int (*mul)(int, int);
	int code;
};

typedef struct _SAMPLE_EXT_API SAMPLE_EXT_API;

#endif


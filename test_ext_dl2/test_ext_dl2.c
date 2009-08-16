#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test_ext_dl2.h"

static function_entry test_ext_dl2_functions[] = {
	{NULL, NULL, NULL}
};

zend_module_entry test_ext_dl2_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_TEST_EXT_DL2_EXTNAME,
	test_ext_dl2_functions,
	PHP_MINIT(test_ext_dl2),
	PHP_MSHUTDOWN(test_ext_dl2),
	PHP_RINIT(test_ext_dl2),
	NULL,
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_TEST_EXT_DL2_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TEST_EXT_DL2
ZEND_GET_MODULE(test_ext_dl2)
#endif

EAPI_CALLBACK_FUNCTION(my_callback)
{
	php_printf("dl2 callback (%s) (%d)\n", ext_name, version);
}

EAPI_EMPTY_CALLBACK_FUNCTION(my_empty_callback)
{
	php_printf("dl2 empty callback\n");
}

int mul(int x, int y)
{
	return x * y;
}

PHP_RINIT_FUNCTION(test_ext_dl2)
{
#ifdef TEST_DEBUG
	php_printf("RINIT test ext dl2\n");
#endif

	return SUCCESS;
}

PHP_MINIT_FUNCTION(test_ext_dl2)
{
	SAMPLE_EXT_API ext_new;
	
	ext_new.mul = mul;
	ext_new.code = 1234;

	zend_eapi_register("eapi_test_dl2", "1.1.0.0", (void *)&ext_new, sizeof(ext_new));
	EAPI_SET_CALLBACK("eapi_test", "1.0.0.0", my_callback);
	EAPI_SET_CALLBACK("eapi_test_dl", "1.1.0.0", my_callback);
	EAPI_SET_EMPTY_CALLBACK(my_empty_callback);

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(test_ext_dl2)
{
	return SUCCESS;
}

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test_ext_dl.h"

static function_entry test_ext_dl_functions[] = {
	{NULL, NULL, NULL}
};

zend_module_entry test_ext_dl_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_TEST_EXT_DL_EXTNAME,
	test_ext_dl_functions,
	PHP_MINIT(test_ext_dl),
	PHP_MSHUTDOWN(test_ext_dl),
	PHP_RINIT(test_ext_dl),
	NULL,
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_TEST_EXT_DL_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TEST_EXT_DL
ZEND_GET_MODULE(test_ext_dl)
#endif

int mul(int x, int y)
{
	return x * y;
}

PHP_RINIT_FUNCTION(test_ext_dl)
{
#ifdef TEST_DEBUG
	php_printf("RINIT test ext dl\n");
#endif

	return SUCCESS;
}

PHP_MINIT_FUNCTION(test_ext_dl)
{
	SAMPLE_EXT_API ext_new;
	
	ext_new.mul = mul;
	ext_new.code = 1234;

	zend_eapi_register("eapi_test_dl", "1.1.0.0", (void *)&ext_new, sizeof(ext_new));

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(test_ext_dl)
{
	return SUCCESS;
}

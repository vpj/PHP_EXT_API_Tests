#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test_ext_b.h"

static function_entry test_ext_b_functions[] = {
    PHP_FE(test_extension_api, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry test_ext_b_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TEST_EXT_B_EXTNAME,
    test_ext_b_functions,
    NULL,
    NULL,
	NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TEST_EXT_B_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TEST_EXT_B
ZEND_GET_MODULE(test_ext_b)
#endif

PHP_FUNCTION(test_extension_api)
{
    struct SAMPLE_EXT_API
	{
		int (*sum)(int, int);
		int code;
	} *api_new = NULL, *api_old = NULL;

	uint version;
	char *version_text;
	
	php_printf("Exists 1.0.0.0: %d\n", zend_ext_api_exists("ext_api_test", "1.0.0.0"));
	php_printf("Exists 1.1.0.0: %d\n", zend_ext_api_exists("ext_api_test", "1.1.0.0"));
    
	php_printf("Getting old api...\n");
	if(zend_ext_api_get("ext_api_test", "1.0.0.0", (void **)&api_old) == SUCCESS)
	{
		php_printf("\tsum(100, 100) = %d\n", api_old->sum(100, 100));
		php_printf("\tsum(1<<30, 1<<30) = %d\n", api_old->sum(1<<30, 1<<30));
		php_printf("\tcode = %d\n", api_old->code);
	}
	else
	{
		php_printf("\tAPI get failed\n");
	}

	php_printf("Getting new api...\n");
	if(zend_ext_api_get("ext_api_test", "1.1.0.0", (void **)&api_new) == SUCCESS)
	{
		php_printf("\tsum(100, 100) = %d\n", api_new->sum(100, 100));
		php_printf("\tsum(1<<30, 1<<30) = %d\n", api_new->sum(1<<30, 1<<30));
		php_printf("\tcode = %d\n", api_new->code);
	}
	else
	{
		php_printf("\tAPI get failed\n");
	}

	zend_ext_api_get_latest_version("ext_api_test", &version);

	php_printf("API max version %x\n", version);

	php_printf("Converting version to text... ", zend_ext_api_version_toa(version, &version_text));
	php_printf("%s\n", version_text);

	php_printf("Converting version 0x0510a00f to text... ", zend_ext_api_version_toa(0x0510a00f, &version_text));
	php_printf("%s\n", version_text);
	
    RETURN_STRING("Tests completed", 1);
}


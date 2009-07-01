#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test_ext_b.h"

static function_entry test_ext_b_functions[] = {
    PHP_FE(test_extension_api, NULL)
    PHP_FE(check_api, NULL)
    PHP_FE(check_callback, NULL)
    PHP_FE(check_latest_callback, NULL)
    PHP_FE(check_empty_callback, NULL)
    PHP_FE(check_version_to_text, NULL)
    PHP_FE(check_version_to_int, NULL)
    PHP_FE(check_latest_api, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry test_ext_b_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TEST_EXT_B_EXTNAME,
    test_ext_b_functions,
    PHP_MINIT(test_ext_b),
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

typedef struct _SAMPLE_EXT_API
{
	int (*sum)(int, int);
	int code;
} SAMPLE_EXT_API;

typedef struct _EXTENSION
{
	SAMPLE_EXT_API *api;
	char *name;
	uint version;
} EXTENSION;

EXTENSION callbacked[10];
int n_callbacked = 0;
EXTENSION latest[10];
int n_latest = 0;
int n_empty = 0;

void my_callback(void *api_void, char *ext_name, uint version)
{
	callbacked[n_callbacked].api = (SAMPLE_EXT_API *)api_void;
	callbacked[n_callbacked].name = ext_name;
	callbacked[n_callbacked++].version = version;
}

void my_latest_callback(void *api_void, char *ext_name, uint version)
{
	latest[n_latest].api = (SAMPLE_EXT_API *)api_void;
	latest[n_latest].name = ext_name;
	latest[n_latest++].version = version;
}

void my_empty_callback()
{
	n_empty++;
}

PHP_MINIT_FUNCTION(test_ext_b)
{
	zend_ext_api_set_callback("ext_api_test", "1.0.0.0", my_callback);
	zend_ext_api_set_callback("ext_api_test", "1.0.22.0", my_callback);
	zend_ext_api_set_callback("ext_api_test", "1.1.0.0", my_callback);
	
	zend_ext_api_set_callback("ext_api_test", NULL, my_latest_callback);
	zend_ext_api_set_callback("ext_api_tst", NULL, my_latest_callback);
	
	zend_ext_api_set_empty_callback(my_empty_callback);
}

PHP_FUNCTION(check_latest_callback)
{
	int n;
	int x, y;
	SAMPLE_EXT_API *api;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &n, &x, &y) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(n >= n_latest)
	{
		RETURN_STRING("Not available", 1);
	}

	php_printf("Extension: %s - %u\n", latest[n].name, latest[n].version);

	RETURN_LONG(latest[n].api->sum(x, y));
}

PHP_FUNCTION(check_empty_callback)
{
	RETURN_LONG(n_empty);
}

PHP_FUNCTION(check_callback)
{
	int n;
	int x, y;
	SAMPLE_EXT_API *api;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &n, &x, &y) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(n >= n_callbacked)
	{
		RETURN_STRING("Not available", 1);
	}

	php_printf("Extension: %s - %u\n", callbacked[n].name, callbacked[n].version);

	RETURN_LONG(callbacked[n].api->sum(x, y));
}

PHP_FUNCTION(check_version_to_text)
{
	int vi;
	char *vt;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &vi) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(zend_ext_api_version_toa(vi, &vt) == FAILURE)
	{
		RETURN_STRING("Cannot convert", 1);
	}

	RETURN_STRING(vt, 1);
}


PHP_FUNCTION(check_version_to_int)
{
	int vi;
	char *vt;
	int l;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &vt, &l) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(zend_ext_api_version_toi(vt, &vi) == FAILURE)
	{
		RETURN_STRING("Cannot convert", 1);
	}

	RETURN_LONG(vi);
}

PHP_FUNCTION(check_latest_api)
{
	char *name;
	int name_len;
	int version;
	int x, y;
	SAMPLE_EXT_API *api;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sll", &name, &name_len, &x, &y) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(zend_ext_api_get_latest_version(name, &version) == FAILURE)
	{
		RETURN_STRING("Not available", 1);
	}

	if(zend_ext_api_get_int_ver(name, version, (void **)&api) == FAILURE)
	{
		RETURN_STRING("ERROR!", 1);
	}

	RETURN_LONG(api->sum(x, y));
}

PHP_FUNCTION(check_api)
{
	char *name, *version;
	int name_len, version_len;
	int x, y;
	SAMPLE_EXT_API *api;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ssll", &name, &name_len, &version, &version_len, &x, &y) == FAILURE)
	{
		RETURN_NULL();
	} 

	if(zend_ext_api_get(name, version, (void **)&api) == FAILURE)
	{
		RETURN_STRING("Not available", 1);
	}

	RETURN_LONG(api->sum(x, y));
}

PHP_FUNCTION(test_extension_api)
{
    SAMPLE_EXT_API *api_new = NULL, *api_old = NULL;

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


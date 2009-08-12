PHP_ARG_ENABLE(test_ext_dl, test dl extension,
[ --enable-test_ext_dl   Test DL Extension])

if test "$PHP_TEST_EXT_DL" = "yes"; then
  AC_DEFINE(HAVE_TEST_EXT_DL, 1, [Whether you have Test Extension DL])
  PHP_NEW_EXTENSION(test_ext_dl, test_ext_dl.c, $ext_shared)
fi


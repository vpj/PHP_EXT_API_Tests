PHP_ARG_ENABLE(test_ext_dl2, test dl2 extension,
[ --enable-test_ext_dl2   Test DL2 Extension])

if test "$PHP_TEST_EXT_DL2" = "yes"; then
  AC_DEFINE(HAVE_TEST_EXT_DL2, 1, [Whether you have Test Extension DL2])
  PHP_NEW_EXTENSION(test_ext_dl2, test_ext_dl2.c, $ext_shared)
fi


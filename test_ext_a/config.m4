PHP_ARG_ENABLE(test_ext_a, test extension,
[ --enable-test_ext_a   Test Extension])

if test "$PHP_TEST_EXT_A" = "yes"; then
  AC_DEFINE(HAVE_TEST_EXT_A, 1, [Whether you have Test Extension A])
  PHP_NEW_EXTENSION(test_ext_a, test_ext_a.c, $ext_shared)
fi


PHP_ARG_ENABLE(test_ext_b, Test Extension,
[ --enable-test_ext_b   Enable Test Extension B])

if test "$PHP_TEST_EXT_B" = "yes"; then
  AC_DEFINE(HAVE_TEST_EXT_B, 1, [Whether you have Test Extension B])
  PHP_NEW_EXTENSION(test_ext_b, test_ext_b.c, $ext_shared)
fi


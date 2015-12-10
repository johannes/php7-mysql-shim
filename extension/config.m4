dnl $Id$
dnl config.m4 for extension mysql

PHP_ARG_ENABLE(mysql, whether to enable mysql support,
[  --enable-mysql           Enable mysql support])

if test "$PHP_MYSQL" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(mysql, mysql.cxx, $ext_shared,,-std=c++11 -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
  PHP_ADD_MAKEFILE_FRAGMENT
fi

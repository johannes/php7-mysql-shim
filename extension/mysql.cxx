/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_mysql.h"

#include "mysql.php.h"

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(mysql)
{
#if defined(COMPILE_DL_MYSQL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_eval_string(const_cast<char*>(mysql_src), nullptr, const_cast<char*>("(mysql.php)"));

	return SUCCESS;
}
/* }}} */

/* {{{ mysql_module_entry
 */
zend_module_entry mysql_module_entry = {
	STANDARD_MODULE_HEADER,
	"mysql",
	nullptr,
	nullptr,
	nullptr,
	PHP_RINIT(mysql),
	nullptr,
	nullptr,
	PHP_MYSQL_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MYSQL
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(mysql)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

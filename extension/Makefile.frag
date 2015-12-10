$(srcdir)/mysql.php.h: $(srcdir)/../lib/mysql.php
	@echo "Creating: $(srcdir)/mysql.php.h"
	@# This should use build dir etc.
	@echo -n 'static auto mysql_src = R"=====(?>' > $(srcdir)/mysql.php.h.tmp
	@cat $(srcdir)/../lib/mysql.php >> $(srcdir)/mysql.php.h.tmp
	@echo ')=====";' >> $(srcdir)/mysql.php.h.tmp
	@mv $(srcdir)/mysql.php.h.tmp $(srcdir)/mysql.php.h

$(srcdir)/mysql.cxx: $(srcdir)/mysql.php.h

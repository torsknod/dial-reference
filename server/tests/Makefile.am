@CODE_COVERAGE_RULES@
@VALGRIND_CHECK_RULES@
AUTOMAKE_OPTIONS = subdir-objects
check_PROGRAMS = test_url_lib test_dial_data
TESTS = $(check_PROGRAMS)
AM_CPPFLAGS = -I$(top_srcdir)/server -I$(top_srcdir)/c-tap-harness
AM_CFLAGS = -I$(top_srcdir)/server -I$(top_srcdir)/c-tap-harness
LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) $(top_srcdir)/tap-driver.sh

test_url_lib_SOURCES = test_url_lib.c ../url_lib.c
test_url_lib_LDADD = $(top_builddir)/c-tap-harness/tests/tap/libtap.a

test_dial_data_SOURCES = test_dial_data.c ../dial_data.c
test_dial_data_LDADD = $(top_builddir)/c-tap-harness/tests/tap/libtap.a

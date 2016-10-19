AUTOMAKE_OPTIONS = subdir-objects
EXTRA_DIST = test_dial_data.h test.h test_url_lib.h 
check_PROGRAMS = test
TESTS = $(check_PROGRAMS)

test_SOURCES = run_tests.c test_dial_data.c test_url_lib.c ../url_lib.c ../dial_data.c
test_CPPFLAGS = $(AM_CPPFLAGS) -I$(top_srcdir)/server
test_CFLAGS = $(AM_CFLAGS) -I$(top_srcdir)/server

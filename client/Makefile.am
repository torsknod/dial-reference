@CODE_COVERAGE_RULES@
@VALGRIND_CHECK_RULES@
EXTRA_DIST = DialClientInput.h DialConformance.h DialDiscovery.h DialServer.h 

bin_PROGRAMS = dialclient

dialclient_SOURCES = main.cpp DialServer.cpp DialDiscovery.cpp DialConformance.cpp DialClientInput.cpp
dialclient_CFLAGS = $(LIBCURL_CFLAGS) $(AM_CFLAGS)
dialclient_CPPFLAGS = $(LIBCURL_CPPFLAGS) $(AM_CPPFLAGS)
dialclient_LDADD = $(LIBCURL_LIBS) $(AM_LIBS)

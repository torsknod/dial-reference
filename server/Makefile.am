@CODE_COVERAGE_RULES@
EXTRA_DIST = dial_data.h dial_options.h dial_server.h LinuxInterfaces.h mongoose.h nf_callbacks.h url_lib.h 
SUBDIRS = . tests
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = dialserver
noinst_LTLIBRARIES = libnfCallbacks.la

dialserver_SOURCES = dial_data.c dial_server.c LinuxInterfaces.c main.c mongoose.c quick_ssdp.c url_lib.c
dialserver_LDADD = $(PTHREAD_STUBS_LIBS) $(AM_LIBS) libnfCallbacks.la
dialserver_CFLAGS = $(PTHREAD_STUBS_CFLAGS) $(AM_CFLAGS)
dialserver_CPPFLAGS = $(PTHREAD_STUBS_CPPFLAGS) $(AM_CPPFLAGS)

libnfCallbacks_la_SOURCES = nf_callbacks.c

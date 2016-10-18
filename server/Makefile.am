SUBDIRS = . tests
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = dialserver
noinst_LTLIBRARIES = libnfCallbacks.la

dialserver_SOURCES = dial_data.c dial_server.c LinuxInterfaces.c main.c mongoose.c quick_ssdp.c url_lib.c
dialserver_LDADD = libnfCallbacks.la

libnfCallbacks_la_SOURCES = nf_callbacks.c

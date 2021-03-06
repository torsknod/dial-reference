#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([dial-reference], [2.1], [jcli@netflix.com])
AM_INIT_AUTOMAKE([1.13.2 -Wall -Werror])
AM_MAINTAINER_MODE
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_SUBDIRS([c-tap-harness])
AC_REQUIRE_AUX_FILE([tap-driver.sh])
AX_GENERATE_CHANGELOG

# Checks for programs.
AM_PROG_AR
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG
LT_INIT()

AX_GCC_WARN_UNUSED_RESULT
AX_COMPILER_FLAGS()
#AX_COMPILER_FLAGS_CFLAGS()
#AX_COMPILER_FLAGS_CXXFLAGS()
#AX_COMPILER_FLAGS_LDFLAGS()
AX_CFLAGS_WARN_ALL
AX_CXXFLAGS_WARN_ALL

PKG_CHECK_MODULES([LIBCURL], [libcurl])
PKG_CHECK_MODULES([PTHREAD_STUBS], [pthread-stubs])

AX_CFLAGS_NO_WRITABLE_STRINGS
AX_CFLAGS_STRICT_PROTOTYPES

# Checks for libraries.
AC_CHECK_LIB([pthread], [pthread_self])
LIBCURL_CHECK_CONFIG

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h limits.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h sys/ioctl.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([inet_ntoa memmove memset putenv regcomp select socket strchr strcspn strdup strerror strrchr strspn strstr strtol strtoul])

AM_WITH_DMALLOC
AX_WITH_MPATROL

AX_CODE_COVERAGE
AX_VALGRIND_CHECK

AC_CONFIG_FILES([Makefile
                 server/Makefile
                 server/tests/Makefile
                 client/Makefile])
AC_OUTPUT

AC_INIT([guake-indicator], [1.3.3], [gun101@email.it])

AM_INIT_AUTOMAKE([-Wall -Werror])

# safety check , make sure that config is not run from outer space
AC_CONFIG_SRCDIR([src])
AC_CONFIG_MACRO_DIR([m4])

AM_MAINTAINER_MODE([enable])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_STDC_HEADERS

AM_PATH_PYTHON(2.5.0)

# Checks for libraries.
AC_CHECK_FUNCS([bzero]) 
AC_CHECK_FUNCS([mkdir]) 
AC_CHECK_FUNCS([strdup])
AC_CHECK_FUNCS([strerror])

PKG_PROG_PKG_CONFIG

GLIB_REQUIRED=2.50.0
GTK_REQUIRED=3.22.0
POLKIT_AGENT_REQUIRED=0.97
POLKIT_GOBJECT_REQUIRED=0.97
APPINDICATOR_REQUIRED=0.0.13

PKG_CHECK_MODULES(GLIB, glib-2.0 >= $GLIB_REQUIRED gio-2.0 >= $GLIB_REQUIRED)

PKG_CHECK_MODULES(GTK, gtk+-3.0 >= $GTK_REQUIRED)
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

# Application Indicator (Ubuntu and Ayatana implementation)
AYATANA_APPINDICATOR_PKG=ayatana-appindicator3-0.1
PKG_CHECK_MODULES(AYATANA_APPINDICATOR,
                 [$AYATANA_APPINDICATOR_PKG >= $APPINDICATOR_REQUIRED],
                 [AC_DEFINE(HAVE_AYATANA_APPINDICATOR, 1, [Have Ayatana AppIndicator])])
AC_SUBST(AYATANA_APPINDICATOR_CFLAGS)
AC_SUBST(AYATANA_APPINDICATOR_LIBS)

PKG_CHECK_MODULES(JSONC, json-c)
AC_SUBST(JSONC_CFLAGS)
AC_SUBST(JSONC_LIBS)

PKG_CHECK_MODULES(XML2, libxml-2.0)
AC_SUBST(XML2_CFLAGS)
AC_SUBST(XML2_LIBS)

PKG_CHECK_MODULES(DBUSGLIB, dbus-glib-1)
AC_SUBST(DBUSGLIB_CFLAGS)
AC_SUBST(DBUSGLIB_LIBS)

# python checks
AC_MSG_CHECKING([for the python-urllib package])
ac_urllib2_result=`$PYTHON -c 'try:
    import urllib2
except Exception, e:
    print str(e)' 2> /dev/null`

if test -z "$ac_urllib2_result"; then
    AC_MSG_RESULT([yes])
else
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([cannot import Python module "urllib2".
    Please check if you have python-urllib2 installed. The error was:
    $ac_urllib2_results])
fi

AC_MSG_CHECKING([for the python-BeautifulSoup package])
ac_BeautifulSoup_result=`$PYTHON -c 'try:
    import BeautifulSoup
except Exception, e:
    print str(e)' 2> /dev/null`

if test -z "$ac_BeautifulSoup_result"; then
    AC_MSG_RESULT([yes])
else
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([cannot import Python module "BeautifulSoup".
    Please check if you have python-beautifulsoup installed. The error was:
    $ac_BeautifulSoup_result])
fi

AC_MSG_CHECKING([for the python-BeautifulSoup package])

# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.
# Output files.

# needed to install gsettings schema
GLIB_GSETTINGS

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
Makefile
src/Makefile
data/Makefile
plugins/Makefile
data/icons/Makefile
])

AC_OUTPUT

ACLOCAL_AMFLAGS = -I m4 --install
AM_CXXFLAGS = -I$(top_srcdir)/include
lib_LTLIBRARIES	=	libbtree.la
dist_libbtree_la_SOURCES	=	src/btree.cc
include_HEADERS = include/btree.h
bin_PROGRAMS = test
dist_test_SOURCES = src/main.cc
test_LDADD = $(lib_LTLIBRARIES)

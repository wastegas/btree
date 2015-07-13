ACLOCAL_AMFLAGS = -I m4 --install
AM_CXXFLAGS = -I$(top_srcdir)/include
lib_LTLIBRARIES	=	libbtree.la
libbtree_la_SOURCES	=	src/btree.cpp 

bin_PROGRAMS = test
test_SOURCES = src/main.cc
test_LDADD = libbtree.la

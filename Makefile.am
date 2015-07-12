ACLOCAL_AMFLAGS = -I m4 --install
lib_LTLIBRARIES	=	libbtree.la
libbtree_la_SOURCES	=	src/btree.cpp src/btree.h
bin_PROGRAMS = test
test_SOURCES = src/main.cc src/btree.h
test_LDADD = libbtree.la

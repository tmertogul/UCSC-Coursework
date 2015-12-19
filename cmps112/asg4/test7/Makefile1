# $Id: Makefile1,v 1.1 2011-03-24 17:20:58-07 - - $

all : foo.o

%.o : %.c
	echo first %.o : %.c

%.o : %.c
	echo second %.o : %.c

foo.o: foo.c foo.h bar.h baz.h

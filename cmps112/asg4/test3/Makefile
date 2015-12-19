# $Id: Makefile,v 1.1 2015-12-08 21:35:09-08 - - $

SOURCES = main.c hello.c
HEADERS = hello.h
OBJECTS = main.o hello.o
CHECKIN = Makefile ${SOURCES} ${HEADERS}
EXECBIN = hello

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	cc ${OBJECTS} -o ${EXECBIN}

main.o : main.c hello.h
	cc -c main.c

hello.o : hello.c hello.h
	cc -c hello.c

ci : ${CHECKIN}
	cid ${CHECKIN}

test : ${EXECBIN}
	./${EXECBIN}

clean : 
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN}


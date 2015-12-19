# $Id: Makefile,v 1.1 2015-12-08 21:35:09-08 - - $

MKFILE   = Makefile
CCOPTS   = -D__EXTENSIONS__ -Xc -v -g -xO0
LINTOPTS = -D__EXTENSIONS__ -Xa -fd -m -u -x -errchk=%all,no%longptr64
SOURCES  = main.c hello.c
HEADERS  = hello.h
OBJECTS  = main.o hello.o
CHECKIN  = ${MKFILE} ${SOURCES} ${HEADERS}
EXECBIN  = hello

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	cc ${CCOPTS} ${OBJECTS} -o ${EXECBIN}

%.o : %.c
	cc ${CCOPTS} -c $<

ci : ${CHECKIN}
	cid + ${CHECKIN}

lint : ${SOURCES}
	lint ${LINTOPTS} ${SOURCES}

test : ${EXECBIN}
	./${EXECBIN} ; echo status = $$?

clean : 
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN}

hello.o: hello.c
hello.o: hello.h
main.o: hello.h
main.o: main.c

# Tim Mertogul
# tmertogu@ucsc.edu
# Michael Lowe
# mimlowe@ucsc.edu
# CMPS109
# Spring 2015
# ASG 5

GPP      = g++ -g -O0 -Wall -Wextra -std=gnu++11

DEPFILE  = Makefile.dep
HEADERS  = sockets.h protocol.h logstream.h
CPPLIBS  = sockets.cpp protocol.cpp 
CPPSRCS  = ${CPPLIBS} cix.cpp cixd.cpp
LIBOBJS  = ${CPPLIBS:.cpp=.o}
CIXOBJS  = cix.o ${LIBOBJS}
CIXDOBJS = cixd.o ${LIBOBJS}
OBJECTS  = ${CIXOBJS} ${CIXDOBJS}
EXECBINS = cix cixd
LISTING  = Listing.ps
SOURCES  = ${HEADERS} ${CPPSRCS} Makefile
PAIR     = README PARTNER
ASOURCES = ${SOURCES} ${PAIR}

CLASS       = cmps109-wm.s15
PROJECT     = asg5

all: ${DEPFILE} ${EXECBINS}

cix: ${CIXOBJS}
	${GPP} -o $@ ${CIXOBJS}

cixd: ${CIXDOBJS}
	${GPP} -o $@ ${CIXDOBJS}

%.o: %.cpp
	${GPP} -c $<

ci:
	- checksource ${SOURCES}
	- cid + ${SOURCES}

lis: all ${SOURCES} ${DEPFILE}
	mkpspdf ${LISTING} ${SOURCES} ${DEPFILE}

clean:
	- rm ${OBJECTS} Makefile.dep *.log

spotless: clean
	- rm ${EXECBINS}

redo : spotless
	make
	clear

run : spotless
	mk.build
	mk.tests
	clear
	
submit : ${ASOURCES}
	- checksource ${ASOURCES}
	submit ${CLASS} ${PROJECT} ${ASOURCES}

subpartner : ${ASOURCES}
	- checksource ${ASOURCES}
	submit ${CLASS} ${PROJECT} ${PAIR}

dep:
	- rm ${DEPFILE}
	make --no-print-directory ${DEPFILE}

${DEPFILE}:
	${GPP} -MM ${CPPSRCS} >${DEPFILE}

again: ${SOURCES}
	make --no-print-directory spotless ci all lis

include ${DEPFILE}


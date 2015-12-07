# Tim Mertogul
# tmertogu@ucsc.edu
# Michael Lowe
# mimlowe@ucsc.edu
# CMPS109
# Spring 2015
# ASG 3

# $Id: Makefile,v 1.10 2015-01-30 14:30:57-08 - - $

# By default, gmake sets the variable ${CXX}=g++ on a Linux system.
# To use Sun Studio C++ (CC), set the variable CXX=CC, either on
# the command line when calling make, or in an environment variable.

MKFILE      = Makefile
DEPFILE     = ${MKFILE}.dep
NOINCL      = ci clean spotless
NEEDINCL    = ${filter ${NOINCL}, ${MAKECMDGOALS}}
GMAKE       = ${MAKE} --no-print-directory

COMPILECPP  = g++ -g -O0 -Wall -Wextra -std=gnu++11
MAKEDEPCPP  = g++ -MM

CPPHEADER   = listmap.h trace.h util.h xless.h xpair.h
TEMPLATES   = listmap.tcc util.tcc
CPPSOURCE   = trace.cpp util.cpp main.cpp
ALLCPPSRC   = ${CPPHEADER} ${TEMPLATES} ${CPPSOURCE}
OBJECTS     = ${CPPSOURCE:.cpp=.o}
EXECBIN     = keyvalue
OTHERS      = ${MKFILE} README PARTNER
ALLSOURCES  = ${ALLCPPSRC} ${OTHERS}
LISTING     = Listing.ps
OUT         = 1 2 3 4 5 6 7
TESTS       = *.ydc.* *.log leaks-test.*
SUBSRC      = ${ALLSOURCES}

SUBMIT	    = submit cmps109-wm.s15 asg3
GOTO        = cd /afs/cats.ucsc.edu/class/cmps109-wm.s15/asg3/tmertogu;

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILECPP} -o $@ ${OBJECTS}

%.o : %.cpp
	${COMPILECPP} -c $<

ci : ${ALLSOURCES}
	- checksource ${ALLSOURCES}
	cid + ${ALLSOURCES}

lis : ${ALLSOURCES}
	mkpspdf ${LISTING} ${ALLSOURCES} ${DEPFILE}

clean : 
	- rm ${OBJECTS} ${DEPFILE} keyvalue run* valgrind.out *.log

spotless : clean
	- rm ${EXECBIN} ${LISTING} ${LISTING:.ps=.pdf}

redo : spotless
	make
	clear

run : spotless
	mk.build
	mk.tests
	clear

check : 
	@for number in ${OUT} ; do \
	echo "file $$number"; \
	diff run$$number.* out.run$$number.* ; \
	echo ""; \
	done

dep : ${ALLCPPSRC}
	@ echo "# ${DEPFILE} created `LC_TIME=C date`" >${DEPFILE}
	${MAKEDEPCPP} ${CPPSOURCE} >>${DEPFILE}

${DEPFILE} :
	@ touch ${DEPFILE}
	${GMAKE} dep

again :
	${GMAKE} spotless dep ci all lis

submit: ${SUBSRC}  
	${SUBMIT} ${SUBSRC} 

ifeq (${NEEDINCL}, )
include ${DEPFILE}
endif


# Tim Mertogul
# tmertogu@ucsc.edu
# Michael Lowe
# mimlowe@ucsc.edu
# CMPS109
# Spring 2015
# ASG 2

# $Id: Makefile,v 1.11 2014-07-02 20:01:17-07 - - $

MKFILE      = Makefile
DEPFILE     = ${MKFILE}.dep
NOINCL      = ci clean spotless
NEEDINCL    = ${filter ${NOINCL}, ${MAKECMDGOALS}}
GMAKE       = ${MAKE} --no-print-directory

COMPILECPP  = g++ -g -O0 -Wall -Wextra -std=gnu++11
MAKEDEPCPP  = g++ -MM

CPPHEADER   = bigint.h   scanner.h   debug.h   util.h   iterstack.h
CPPSOURCE   = bigint.cpp scanner.cpp debug.cpp util.cpp main.cpp
EXECBIN     = ydc
OBJECTS     = ${CPPSOURCE:.cpp=.o}
OTHERS      = ${MKFILE} README PARTNER
ALLSOURCES  = ${CPPHEADER} ${CPPSOURCE} ${OTHERS}
LISTING     = Listing.ps

TESTS       = *.ydc.* *.log leaks-test.*
SUBSRC      = ${ALLSOURCES}


SUBMIT	   = submit cmps109-wm.s15 asg2 
GOTO      = cd /afs/cats.ucsc.edu/class/cmps109-wm.s15/asg2/tmertogu;

all : ${EXECBIN}
	- checksource ${ALLSOURCES}

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
	- rm ${OBJECTS} ${DEPFILE} ydc ${EXECBIN}.errs ${TESTS}

redo : spotless
	make
	clear

spotless : clean
	- rm ${EXECBIN} ${LISTING} ${LISTING:.ps=.pdf}

run : spotless
	mk.build
	mk.tests
	clear

diff :
	- diff test0-stk.ydc.out test0-stk.dc.output
	- diff test1-stk.ydc.out test1-stk.dc.output
	- diff test2-add.ydc.out test2-add.dc.output
	- diff test3-sub.ydc.out test3-sub.dc.output
	- diff test4-mul.ydc.out test4-mul.dc.output
	- diff test5-div.ydc.out test5-div.dc.output
	- diff test6-exp.ydc.out test6-exp.dc.output
	- diff leaks-test.out testx-leaks.dc.output

dep : ${CPPSOURCE} ${CPPHEADER}
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


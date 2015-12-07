
MKFILE    = Makefile
DEPSFILE  = ${MKFILE}.deps
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
VALGRIND  = valgrind --leak-check=full --show-reachable=yes
 
#
# Definitions of list of files:
#
M        = main.cc 
#HSOURCES = astree.h  lyutils.h  auxlib.h  stringset.h symtable.h
#CSOURCES = astree.cc lyutils.cc auxlib.cc stringset.cc symtable.cc ${M}
HSOURCES = astree.h  lyutils.h  auxlib.h  stringset.h 
CSOURCES = astree.cc lyutils.cc auxlib.cc stringset.cc ${M}
LSOURCES = scanner.l
YSOURCES = parser.y
SOURCES  = ${CSOURCES} ${HSOURCES} ${LSOURCES} ${YSOURCES}
ETCSRC   = README ${MKFILE} ${DEPSFILE}
CLGEN    = yylex.cc
HYGEN    = yyparse.h
CYGEN    = yyparse.cc
CGENS    = ${CLGEN} ${CYGEN}
ALLGENS  = ${HYGEN} ${CGENS}
EXECBIN  = oc
ALLCSRC  = ${CSOURCES} ${CGENS} 
OBJECTS  = ${ALLCSRC:.cc=.o}
LREPORT  = yylex.output
YREPORT  = yyparse.output
IREPORT  = ident.output
REPORTS  = ${LREPORT} ${YREPORT} ${IREPORT}
ALLSRC   = ${ETCSRC} ${YSOURCES} ${LSOURCES} ${HSOURCES} ${CSOURCES}
TESTINS  = ${wildcard test?.in}
LISTSRC  = ${ALLSRC} ${HYGEN}
SUBSRC   =  README ${MKFILE} ${SOURCES}
 
SUBMIT	   = submit cmps104a-wm.f14 asg4 
GOTO      = cd /afs/cats.ucsc.edu/class/cmps104a-wm.f14/asg4/tmertogu;

#
# Definitions of the compiler and compilation options:
#
GCC       = g++ -g -O0 -Wall -Wextra -std=gnu++11
MKDEPS    = g++ -MM -std=gnu++11

#
# The first target is always ``all'', and hence the default,
# and builds the executable images
#
all : ${EXECBIN}

#
# Build the executable image from the object files.
#
${EXECBIN} : ${OBJECTS}
	${GCC} -o${EXECBIN} ${OBJECTS}
	ident ${OBJECTS} ${EXECBIN} >${IREPORT}

#
# Build an object file form a C source file.
#
%.o : %.cc
	${GCC} -c $<


#
# Build the scanner.
#
${CLGEN} : ${LSOURCES}
	flex --outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^  ' ${LREPORT}

#
# Build the parser.
#
${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

#
# Check sources into an RCS subdirectory.
#
ci : ${ALLSRC} ${TESTINS}
	cid + ${ALLSRC} ${TESTINS} test?.inh

#
# Make a listing from all of the sources
#
lis : ${LISTSRC} tests
	mkpspdf List.source.ps ${LISTSRC}
	mkpspdf List.output.ps ${REPORTS} \
		${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, in out err}}

#
# Clean and spotless remove generated files.
#
clean :
	- rm ${OBJECTS} ${ALLGENS} ${REPORTS} ${DEPSFILE}
	- rm *.str *.tok *.err *.out *.log oc parser.tab.* 
	- rm ${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, out err}}

cleant :
	- rm *.str *.tok *.ast *.sym *.err *.out *.log parser.tab.*
	
redo : clean
	make
	clear 
	
spotless : clean
	- rm ${EXECBIN}

rungood :
	oc 00-trivial.oc 
	oc 01-hello.oc 
	oc 03-test3.oc 
	oc 04-test4.oc 
	oc 06-test6.oc 
	oc 07-assert.oc 
	oc 10-hundred.oc 
	oc 11-numbers.oc 
	oc 12-elseif.oc 
	oc 13-assertfail.oc 
	oc 14-ocecho.oc 
	oc 20-fib-array.oc 
	oc 21-eratosthenes.oc 
	oc 23-atoi.oc 
	oc 30-fac-fnloop.oc 
	oc 31-fib-2supn.oc
	oc 40-arraystack.oc 
	oc 41-linkedstack.oc 
	oc 42-viiiqueens.oc 
	oc 44-dot-product.oc 
	oc 45-towers-of-hanoi.oc 
	oc 53-insertionsort.oc 

#
# Build the dependencies file using the C preprocessor
#
deps : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

#
# Test
#

tests : ${EXECBIN}
	touch ${TESTINS}
	make --no-print-directory ${TESTINS:.in=.out}

%.out %.err : %.in ${EXECBIN}
	( ${VALGRIND} ${EXECBIN} -ly -@@ $< \
	;  echo EXIT STATUS $$? 1>&2 \
	) 1>$*.out 2>$*.err

#
# Everything
#
again :
	gmake --no-print-directory spotless deps ci all lis
	
ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif

submit: ${SUBSRC}  
	${SUBMIT} ${SUBSRC} 
	

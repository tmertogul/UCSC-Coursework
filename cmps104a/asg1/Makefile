# $Id: Makefile,v 1.8 2014-10-07 18:13:45-07 - - $

GCC        = g++ -g -O0 -Wall -Wextra -std=gnu++11
MKDEPS      = g++ -MM -std=gnu++11
VALGRIND   = valgrind --leak-check=full --show-reachable=yes

MKFILE     = Makefile
DEPSFILE    = Makefile.deps
SOURCES    = auxlib.cpp stringset.cpp main.cpp 
HEADERS    = auxlib.h stringset.h
OTHERS	   = README ${MKFILE}
OBJECTS    = ${SOURCES:.cpp=.o}
EXECBIN    = oc
SRCFILES   = ${HEADERS} ${SOURCES} ${MKFILE}
SMALLFILES = ${DEPSFILE} README  
CHECKINS   = ${SRCFILES} ${SMALLFILES}
SUBMIT	   = submit cmps104a-wm.f14 asg1 
GOTO      = cd /afs/cats.ucsc.edu/class/cmps104a-wm.f14/asg1/tmertogu;
CHECK 	   = 
#LISTING    = Listing.ps

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GCC} -o${EXECBIN} ${OBJECTS}

%.o : %.cpp
	${GCC} -c $<

ci :
	cid + ${CHECKINS}
	checksource ${CHECKINS}

clean :
	- rm ${OBJECTS} 

spotless : clean
	- rm ${EXECBIN} 

${DEPSFILE} :
	${MKDEPS} ${SOURCES} >${DEPSFILE}

deps :
	- rm ${DEPSFILE}
	${MAKE} --no-print-directory ${DEPSFILE}

include Makefile.deps

# Everything
again :
	gmake --no-print-directory spotless deps ci all lis

submit: ${SOURCES} ${HEADERS} ${OTHERS} 
	${SUBMIT} ${SOURCES} ${HEADERS} ${OTHERS} 

checksubmit: 
	${GOTO} ls; cd -

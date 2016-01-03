# Tim Mertogul
# 1331402
# CMPS12B
# 08/15/13
# makefile for Dictionary.c with Macros
# makefile

FLAGS   = -std=c99 -Wall
SOURCES = Dictionary.c DictionaryClient.c 
FILES = makefile README DictionaryTest.c $(SOURCES)
OBJECTS = Dictionary.o DictionaryClient.o
HEADERS = Dictionary.h
EXEBIN  = DictionaryClient
SUBMIT     = submit cmps012b-pt.u13 pa5

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN) 
	
submit: ${FILES}
	${SUBMIT} ${FILES}
		
checksubmit: 
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/pa5/tmertogu; ls; cd -

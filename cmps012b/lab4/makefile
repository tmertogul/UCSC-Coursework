
# Tim Mertogul
# 1331402
# CMPS12B
# 07/24/13
# makefile for charType.c with Macros
# makefile

FLAGS = -std=c99 -Wall
SOURCES = charType.c
FILES = makefile README $(SOURCES)
OBJECTS = charType.o
EXEBIN = charType
SUBMIT     = submit cmps012b-pt.u13 lab4

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

submit: ${FILES}
	${SUBMIT} ${FILES}

check:
	valgrind --leak-check=full charType infile outfile

checksubmit: 
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/lab4/tmertogu; ls; cd -


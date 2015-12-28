# Tim Mertogul
# 1331402
# CMPS12B
# 07/17/13
# makefile for FileReverse.c with Macros
# makefile

FLAGS = -std=c99 -Wall
SOURCES = FileReverse.c
FILES = makefile README $(SOURCES)
OBJECTS = FileReverse.o
EXEBIN = FileReverse
SUBMIT     = submit cmps012b-pt.u13 lab3

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
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/lab3/tmertogu; ls; cd -

#Tim Mertogul
# 1331402
# CMPS101 Summer14
# 07/09/14
# MakeFile for PA2



#------------------------------------------------------------------------------
# Makefile for CMPS 101 Programming Assignment 2
#
#       make                   makes Lex
#       make ListClient        makes ListClient
#		make ListTest			makes ListTest
#
#------------------------------------------------------------------------------
FILES = Makefile README Lex.c ListClient.c List.c List.h 
SUBMIT     = submit cmps101-pt.u14 pa2


Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c
	
ListTest : ListTest.o List.o	
	gcc -o ListTest ListTest.o List.o
	
ListTest.o : ListTest.c List.h
	gcc -c -std=c99 -Wall ListTest.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f Lex ListClient ListTest Lex.o ListClient.o ListTest.o List.o

check:
	valgrind --leak-check=full $(EXEBIN) 
 
submit: ${FILES}
	${SUBMIT} ${FILES}

checksubmit: 
	cd /afs/cats.ucsc.edu/class/cmps101-pt.u14/pa2/tmertogu; ls; cd -


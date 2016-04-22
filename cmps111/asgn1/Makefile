# Tim Mertogul
# tmertogu
# CS 111 Winter 16
# MakeFile for ASG 1, Simple Shell

all : myshell

myshell : lex.yy.c
	cc -o myshell myshell.c lex.yy.c -lfl -Wno-int-to-pointer-cast #-Wall

lex.yy.c : lex.l
	flex lex.l

clean :
	rm myshell *.o lex.yy.c myshell.core

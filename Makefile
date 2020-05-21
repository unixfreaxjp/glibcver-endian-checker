# This is a Makefile for glibcver-endian-checker program.  .
# Typing 'make' will create the executable file.
CC = gcc
CFLAGS  = -g

all: glibcver-endian-checker

glibcver-endian-checker: check-gcc-endian.c
	$(CC) $(CFLAGS) -o glibcver-endian-checker check-gcc-endian.c

clean: 
	$(RM) glibcver-endian-checker *.o *~

# Makefile for ‘bag’ module
#
# Raunak Bhojwani, April 2016

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb

PROG = bagtest
OBJS = bagtest.o bag.o

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

bagtest.o: bag.h
bag.o: bag.h

clean:
	rm -f *~
	rm -f *.o
	rm -f $(PROG)
# Makefile for ‘counters’ module
#
# Raunak Bhojwani, April 2016

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb

PROG = counterstest
OBJS = counterstest.o counters.o

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

counterstest.o: counters.h
counters.o: counters.h

clean:
	rm -f *~
	rm -f *.o
	rm -f $(PROG)
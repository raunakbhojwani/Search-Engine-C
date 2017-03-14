# Makefile for 'querier' module
#
# George Hito and Raunak Bhojwani, May 2016

PROG = querier
OBJS = querier.o 
LLIBS = ../lib/cs50ds.a ../common/common.a 

CFLAGS = -Wall -pedantic -std=c11 -ggdb
CC = gcc
MAKE = make

# build the querier
$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@

# querier source dependencies; add others as needed
querier.o: ../common/index.c ../indexer/indexer.h

clean:
	rm -f *~
	rm -f *.o
	rm -f $(PROG)

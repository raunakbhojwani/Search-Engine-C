# Makefile for 'indexer' module
#
# George Hito and Raunak Bhojwani, May 2016

# makes both indexer and indextest
	
# make all
all: indexer indextest

OBJS1 = indexer.o 
OBJS2 = indextest.o
LLIBS = ../common/common.a ../lib/cs50ds.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb
CC = gcc
MAKE = make


# crawler source dependencies; add others as needed
indexer.o: ../common/file.h ../common/word.h ../common/index.c
indextest.o: ../common/file.h ../common/index.c 

indexer: $(OBJS1) $(LLIBS) 
	$(CC) $(CFLAGS) $^ -o $@

indextest: $(OBJS2) $(LLIBS) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *~
	rm -f *.o
	rm -f indexer
	rm -f indextest

# Makefile for 'crawler' module
#
# George Hito and Raunak Bhojwani, April 2016

PROG = crawler
OBJS = crawler.o 
LIBS = -lcurl
LLIBS = ../lib/cs50ds.a ../common/common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb
CC = gcc
MAKE = make

# build the crawler
$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

# crawler source dependencies; add others as needed
crawler.o: ../common/web.h crawler.h 

clean:
	rm -f *~
	rm -f *.o
	rm -f $(PROG)

# Makefile for entire TSE module
#
# George Hito and Raunak Bhojwani, May 2016

CC = gcc
MAKE = make

LLIBS = lib/cs50ds.a
COMMONLIBS = common/lib.o
CRAWLER = crawler/crawler.o
INDEXER = indexer/indexer.o indexer/indextest.o
QUERIER = querier/querier.o

all: $(LLIBS) $(COMMONLIBS) $(CRAWLER) $(INDEXER) $(QUERIER)

# build the library
$(LLIBS): 
	cd lib; $(MAKE)

# build common
$(COMMONLIBS):
	cd common; $(MAKE)

# build the crawler
$(CRAWLER):
	cd crawler; $(MAKE)

# build the indexer
$(INDEXER):
	cd indexer; $(MAKE) all

# build the querier
$(QUERIER):
	cd querier; $(MAKE)

clean:
	cd crawler; $(MAKE) clean
	cd indexer; $(MAKE) clean
	cd querier; $(MAKE) clean
	cd common; $(MAKE) clean
	cd lib; $(MAKE) clean

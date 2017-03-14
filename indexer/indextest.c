//simple test code for index module, part 2 of TSE project
//by George Hito and Raunak Bhojwani, May 2016

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../lib/hashtable/hashtable.h"
#include "../lib/hashtable/list.h"
#include "../lib/counters/counters.h"
#include "../common/file.h"
#include "../common/index.c"

/*
* Reads and loads an index file into a hashtable, writes the resulting hashtable 
* to a new file, then cleans up the data structure.
*/
void indextest(char *oldIndexFilename, char *newIndexFilename)
{
	hashtable_t *wordCount = hashtable_new(1000);							//initialise the new hashtable
	indexStore(wordCount, oldIndexFilename); 											//pull index from file and store in hashtable
	writeIndexer(wordCount, newIndexFilename);								// write the hashtable to the newIndex
	hashtable_delete(wordCount);									//delete everything, no memory leaks
}

/*
* Used to test indexer functions and ensure everything is working properly
*/
int main (int argc, char *argv[]) 
{
	//check number of arguments
	if (argc != 3) {
		printf("indexer.c works by passing 2 arguments: pageDirectory, and indexFilename.\n");
		exit(1); //incorrect number of arguments
	}
	indextest(argv[1], argv[2]);
	exit(0); //no errors
}

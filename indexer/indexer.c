/* 
 * indexer.c - indexes a pageDirectory of webpages pulled using crawler
 *
 * George Hito and Raunak Bhojwani, May 2016
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "../lib/hashtable/hashtable.h"
#include "../lib/counters/counters.h"
#include "../lib/hashtable/list.h"
#include "../common/word.h"
#include "../common/file.h"
#include "../lib/hashtable/jhash.h"
#include "../common/index.c"

//globals
int docID = 1;
int FILENAMESIZE = 100; //arbitrary filename size

/*
* Indexes a directory of crawled webpages and stores the results within an output file
* in a specific format.
*/
void indexer(char *pageDirectory, char *indexFilename) {	
	//initialize hashtable for filling 
	hashtable_t *wordCount = hashtable_new(1000);

	//initilize first filename
	char fileName[FILENAMESIZE];
	sprintf(fileName, "%s/%d", pageDirectory, docID);
	char *file = fileName; //create pointer to fileName

	FILE *page; //pointer to file to open and index
	
	while ((page = fopen(file, "r")) != NULL) {
		//skip first two lines of file, depth and url
		free(readline(page));
		free(readline(page));
		//read rest of file into a char array
		char *doc = readfile(page);
		//prepare for iteration along that array
		char *word = NULL;
		int pos = 0;
		//iterate along until the end is reached
		while ((pos = GetNextWord(doc, pos, &word)) > 0) {
			if (strlen(word) > 3) {
				if (!NormalizeWord(word)) { //normalize word
					printf("%s\n", "Error normalizing word");
					if(word){ free(word); word = NULL;}
					continue;
				}
				counters_t *ctrs = hashtable_find(wordCount, word);						// find the counter associated with the key
				if (ctrs == NULL) {
					ctrs = counters_new();												// if this counter is NULL, then the key does not exist
					if (hashtable_insert(wordCount, word, ctrs)) {				// create a new counter and add it to the hashtable, adding a new countersItem
						counters_add(ctrs, docID);
						continue;
					}
				}
				counters_add(ctrs, docID);
			}
			if(word){ free(word); word = NULL;}											//free the word inside the while loop
		}
		fclose(page); //close file in preparation for moving to next one

		docID++; //increment docID
		sprintf(fileName, "%s/%d", pageDirectory, docID); //print string into fileName to be used next
		if(doc){ free(doc); doc = NULL;}												//free the doc after the end of a page
	}
	
	//iterate along hashtable and print contents into file
	writeIndexer(wordCount, indexFilename);

	//delete the hashtable
	hashtable_delete(wordCount);
}

/*
* Used to test indexer functions and ensure everything is working properly
*/
int main (int argc, char *argv[]) {
	//check number of arguments
	if (argc != 3) {
		printf("indexer.c works by passing 2 arguments: pageDirectory, and indexFilename.\n");
		exit(1); //incorrect number of arguments
	}
	if (!isCrawlerDirectory(argv[1])) {
		printf("The chosen directory is not a valid crawler directory!\n");
		exit(2); //pageDirectory error
	}
	indexer(argv[1], argv[2]);
	exit(0); //no errors
}

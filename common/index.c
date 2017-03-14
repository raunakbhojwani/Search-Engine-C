//file to store functions relevant to saving and loading index files

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/hashtable/hashtable.h"
#include "../lib/counters/counters.h"
#include "../common/file.h"

//use access() to check if there is a .crawler file inside the specified
//directory to index from. if it fails, either the directory is invalid, cannot be read
//from, or there is no .crawler file inside
/*
* Use access() to check if there is a .crawler file inside the specified directory
* to index from. if it fails, either the directory is invalid, cannot be read
* from, or there is no .crawler file inside.
*/
bool isCrawlerDirectory(char *dir) {
	char testFile[100];
	char *testFilePointer = testFile;
	sprintf(testFilePointer, "%s/.crawler", dir);
	if (access(testFilePointer, W_OK) == 0) {
		return true;
	}
	return false;
}

/*
* Function pointer passed to a counters object that prints out the key, data pairs within.
*/
void writeCounters(void *arg, int key, int data) {
	fprintf(arg, " %d %d", (int)key, (int )data);
}

/*
* Writes individual lines of the index file.
*/
void writeLine(void *arg, char *key, void *data) {
	fprintf(arg, "%s", key);

	counters_t *ctrs = data;
	counters_iterate(ctrs, writeCounters, arg);
	fprintf(arg, "\n");

	counters_delete(ctrs);
}

/*
* To be passed as function pointer for deleting counters objects in the hashtable->lists
*/
void topLevelDeleteCounters(void *arg, char *key, void *data) {
	counters_t *ctrs = data;
	counters_delete(ctrs);
}

/*
* Takes a hashtable and prints it out as the index of a crawler output.
* outputs an index to indexFilename in a particular format:
* one line per word, one word per line
* each line provides the word and one or more (docID, count) pairs, in the format
* word docID count [docID count]…
* where word is a string of lower-case letters,
* where docID is a positive non-zero integer,
* where count is a positive non-zero integer,
* where the word and integers are separated by spaces.
*/
void writeIndexer(hashtable_t *wordCount, char *indexFilename) {
	FILE *indexFile; //file to store index in
	if ((indexFile = fopen(indexFilename, "w")) != NULL) {
		hashtable_iterate(wordCount, writeLine, indexFile);
		fclose(indexFile);
	}
	else {
		printf("%s\n", "Unable to open the file specified. Error.");
		exit(3); //indexfile open error
	}
	return;
}

/*
* Stores an index from a file into a hashtable data structure.
*/
void indexStore(hashtable_t *index, char *oldIndexFilename) {
	FILE *oldFile;
	if ((oldFile = fopen(oldIndexFilename, "r")) != NULL) {					//open the oldIndex to read it
		int docID = 0;
		int count = 0;
		char *word = malloc(3 * sizeof(char*));								//allocate memory for the key (the word)
		while (fscanf(oldFile, "%s ", word) > 0) {
			while (fscanf(oldFile, "%d %d ", &docID, &count) > 0) {			// read the word, and a corresponding docID count pair
				counters_t *ctrs = hashtable_find(index, word);
				if (ctrs == NULL) {
					ctrs = counters_new();									//find the ocunter for the key, if it doesn't exist, create a new counter and add to hashtable
					hashtable_insert(index, word, ctrs);
				}
				counters_set(ctrs, docID, count);							//set the counter of the specified key to count.
			}
			word = malloc(3 * sizeof(char*));								//malloc for the word so the word can be updats
		}
		free(word);															// be sure to free the excess word
		fclose(oldFile);
	}
	else {
		printf("%s\n", "Invalid file");
		exit(2);
	}
}

 /* 
 * querier.c - queries a pageDirectory of webpages pulled using crawler and
 * indexed using indexer. The index file that is read from is assumed to be correct.
 *
 * George Hito and Raunak Bhojwani, May 2016
 */
#define _GNU_SOURCE
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../indexer/indexer.h"
#include "../common/index.c"
#include "../lib/hashtable/hashtable.h"
#include "../common/word.h"
#include "../lib/counters/counters.h"

//struct to hold (docID,score) pair
typedef struct docIDScore {
 	int docID;
 	int score;
 } docIDScore_t;

//struct to hold pair of counters
typedef struct twoCounters {
	counters_t *currentlyIterating;
	counters_t *currentlyComparing;
} twoCounters_t;

//global to define number of bytes per line to pull for a query
size_t line_size = 1000;
int countToFillArray = 0;		//count to fill array
int *startCount = &countToFillArray;
int FILENAMESIZE = 100; //arbitrary filename size


/*
* Consolidation of memory frees/data structure cleanups
*/
void cleanUp(hashtable_t *index, char **tokenizedWords, int *tokenizedWordsCount) {
	for (int k = 0; k <= *tokenizedWordsCount; k++) {
		free(tokenizedWords[k]);
	}
	free(tokenizedWords);
	hashtable_iterate(index,topLevelDeleteCounters,NULL); //first, free counters in initialized hashtable
	hashtable_delete(index); //then free the hashtable itself
}

/*
* Compare the counts of two identical keys passed to two counters objects.
* This acts as an intersection between sets.
* Takes as parameters:
*	arg, which is a struct containing two counters objects
*	key, the key of the counters->key object in the counters set that is currently being iterated on
*	count, the count of each counters->key object in the counters set that is currently being iterated on
*/
void compareCountersAnd(void *arg, int key, int count) {
	if (count < counters_get(((twoCounters_t *)arg)->currentlyComparing, key)) {
		counters_set(((twoCounters_t *)arg)->currentlyComparing, key, count);
		return;
	} else if (counters_get(((twoCounters_t *)arg)->currentlyComparing, key) < count) {
		counters_set(((twoCounters_t *)arg)->currentlyIterating, key, counters_get(((twoCounters_t *)arg)->currentlyComparing, key));
		return;
	} 
	return;
}

/*
* Compare the counts of two identical keys passed to two counters objects.
* This acts as a union between sets.
* Takes as parameters:
*	arg, which is a counters object
*	key, the key of the counters->key object in the counters set that is currently being iterated on
*	count, the count of each counters->key object in the counters set that is currently being iterated on
*/
void compareCountersOr(void *arg, int key, int count) {
	counters_set((counters_t *)arg, key, (count + counters_get((counters_t *)arg, key)));
}

/*
* Count the number of items in a counters set being iterated upon.
* Takes as parameters:
*	arg, which is a pointer to an integer and is incremented by 1
*	key, which is irrelevant
*	count, which is irrelevant
*/
void numberOfCountersItems(void *arg, int key, int count) {
	(*((int *)arg))++;
}

/*
* This function compares the scores of the DOCIDScore items that are passed
* to qsort(), and sorts them in ascending order for display to the user.
*/
int cmpfunc(const void *a, const void *b) {
	return (*((docIDScore_t*)b)).score - (*((docIDScore_t*)a)).score;
}


/*
* Fill an array with (docID,score) structs pulled from coutners objects
* Takes as parameters:
*	arg, which is a pointer to an integer and is incremented by 1
*	key, which is irrelevant
*	count, which is irrelevant
*/
void fillCountersArray(void *arg, int key, int count) {	
	((docIDScore_t*)arg)[*startCount].docID = key;
	((docIDScore_t*)arg)[*startCount].score = count;
	(*startCount)++;
}

/*
* This function processes the query and prints out documents that match it in descending order.
* Takes as parameters: 
*	pageDirectory holding crawled pages
*	hashtable holding index
*	char** holding query words, normalized and tokenized, guaranteed to be 'correct' in
*		terms of query syntax and query ordering
*/
void processQuery(char *pageDirectory, hashtable_t *index, char **tokenizedWords, int *tokenizedWordsCount) {
	int orFlag = 0; //initialize flags
	int firstWordFlag = 1;
	int andOrFlag = 0;
	counters_t *leftSequence; //initialize counters objects to use as placeholders
	counters_t *rightSequence;
	//basic methodology: start at first word and trigger andFlag immediately
	//keep andFlag on until an 'or' is reached (building andsequence meanwhile), then 
	//trigger firstOrFlag and begin computing andsequence of all terms to the right of that 
	//'or' until the NEXT 'or' is reached. once that is reached, take the two existing andsequences
	//and 'or' them together into one sequence. treat this next sequence as the lefthand
	//'andsequence' for the next 'or' and rinse and repeat until no more words left.
	//then, print the results in a ranked fashion.
	
	if ((strcmp(tokenizedWords[0], "and")) == 0 || (strcmp(tokenizedWords[0], "or")) == 0) {
		printf("%s\n", "Error: cannot begin a query with 'and' or 'or'.");
		cleanUp(index, tokenizedWords, tokenizedWordsCount);
		exit(5); //and/or ordering error
	}
	if ((strcmp(tokenizedWords[*tokenizedWordsCount], "and")) == 0 || (strcmp(tokenizedWords[*tokenizedWordsCount], "or")) == 0) {
		printf("%s\n", "Error: cannot end a query with 'and' or 'or'.");
		cleanUp(index, tokenizedWords, tokenizedWordsCount);
		exit(5); //and/or ordering error
	}


	for (int i = 0; i <= *tokenizedWordsCount; i++) {
		//get first counters object for first word

		if ((strcmp(tokenizedWords[i], "and")) == 0 || (strcmp(tokenizedWords[i], "or")) == 0) {
			if (andOrFlag == 1) {
				printf("%s\n", "Error: cannot have and/or consecutively.");
				cleanUp(index, tokenizedWords, tokenizedWordsCount);
				exit(5); //and/or ordering error
			}
			andOrFlag = 1;
		}

		if (firstWordFlag == 1) {
			leftSequence = (counters_t *)hashtable_find(index, tokenizedWords[i]);
			firstWordFlag = 0;
			continue;
		} 
		if (strcmp(tokenizedWords[i], "and") == 0) {
			continue; //ands don't matter as this case is identical to having words next to each other
		} else if (strcmp(tokenizedWords[i], "or") == 0 && orFlag == 0) {
			//first 'or' seen, set orFlag to true and initialize rightSequence
			orFlag = 1;
			rightSequence = (counters_t *)hashtable_find(index, tokenizedWords[i+1]);
			continue;
		} else if ((strcmp(tokenizedWords[i], "or") == 0 && orFlag == 1)) {
			counters_iterate(rightSequence, compareCountersOr, leftSequence);
			rightSequence = (counters_t *)hashtable_find(index, tokenizedWords[i+1]); //reset rightSequence
			continue;
		} else if (i == *tokenizedWordsCount && orFlag == 1) {
			counters_iterate(rightSequence, compareCountersOr, leftSequence);
			andOrFlag = 0;
			continue;
		} else if (orFlag == 1) {
			//orFlag is 1, so we know to build rightSequence
			twoCounters_t *pair;
			if (!(pair = malloc(2 * sizeof(twoCounters_t)))) {
				printf("Memory allocation error!");
				exit(7);
			}
			pair->currentlyIterating = (counters_t *)hashtable_find(index, tokenizedWords[i]);
			pair->currentlyComparing = rightSequence;
			counters_iterate(rightSequence, compareCountersAnd, pair);
			andOrFlag = 0;
			if (pair) {free(pair); pair = NULL;}
			continue;
		} else { //not 'and' nor 'or', so build leftsequence
			twoCounters_t *pair;
			if (!(pair = malloc(2 * sizeof(twoCounters_t)))) {
				printf("Memory allocation error!");
				exit(7);
			}
			pair->currentlyIterating = leftSequence;
			pair->currentlyComparing = (counters_t *)hashtable_find(index, tokenizedWords[i]);
			counters_iterate(leftSequence, compareCountersAnd, pair);
			andOrFlag = 0;
			if (pair) {free(pair); pair = NULL;}
			continue;
		}
	}

	//once entire query has been processed, print the result in a clean, canonical form
	//count the number of elements within leftSequence at this point
	int count = 0;					//count to test for size of array
	int *leftCount = &count;
	
	counters_iterate(leftSequence, numberOfCountersItems, leftCount);
	//now malloc space for array to hold (docID, score) pairs
	docIDScore_t scorePairs[*leftCount];

	//iterate along leftSequence to fill scorePairs with structs
	counters_iterate(leftSequence, fillCountersArray, scorePairs);

	*startCount = 0;
	//qsort the array in ascending order based on score
	qsort(&scorePairs[0],*leftCount,sizeof(docIDScore_t),cmpfunc);
	printf("Matches %i documents (ranked): \n", *leftCount);
	//print the array out as a query response
	//open and close relevant files in pageDirectory to print URLs
	for(int i = 0; i< *leftCount; i++) {
		char fileName[FILENAMESIZE];
		sprintf(fileName, "%s/%d", pageDirectory, scorePairs[i].docID);
		char *file = fileName; //create pointer to fileName
		FILE *page = fopen(file, "r+");
		char *url = readline(page);
		printf("score\t%i doc\t%i: %s\n", scorePairs[i].score, scorePairs[i].docID, url);
		if(url) {free(url); url = NULL;}
		fclose(page);
	}
	printf("----------------------------------------------------------------------------------------------\n");
}


/*
* This function tokenizes the query and returns it broken up into a char**.
* Takes as parameters:
*	line holding latest query to be tokenized
*	int* to hold number of words in query
*/
char **tokenizeQuery(char *line, hashtable_t *index, int *tokenizedWordsCount) {
	//pull each word one by one, tokenize it, and store it in an array
	//note that tokenizedWordsCount is the number of strings stored within this array
	*tokenizedWordsCount = 0;
	char **tokenizedWords;
	if (!(tokenizedWords = malloc(line_size * sizeof(char **)))) {
		printf("Memory allocation error!");
		exit(7);
	}
	char *word;
	word = strtok(line, " "); //pull off first word
	//checks for the case when the user just presses 'enter' and inputs nothing
	if (word == NULL) {
		printf("%s\n", "Error: please enter a query!");
		free(line);
		free(tokenizedWords);
		hashtable_iterate(index,topLevelDeleteCounters,NULL); //first, free counters in initialized hashtable
		hashtable_delete(index); //then free the hashtable itself
		exit(6); //error when just pressing enter and inputting no characters
	}
	if (!(tokenizedWords[*tokenizedWordsCount] = malloc(5 * sizeof(char*)))) {
		printf("Memory allocation error!");
		exit(7);
	}
	strcpy(tokenizedWords[*tokenizedWordsCount],word);
	//pull each consecutive word off with strtok() and store it in tokenizedWords
	while ((word = strtok(NULL, " ")) != '\0') {
		(*tokenizedWordsCount)++;
		if (!(tokenizedWords[*tokenizedWordsCount] = malloc(5 * sizeof(char*)))) {
			printf("Memory allocation error!");
			exit(7);
		}
		strcpy(tokenizedWords[*tokenizedWordsCount],word);
	}
	//because the termination character for strtok() in this case is '\0', what happens is
	//that the null character that terminates all strings in C is incorrectly stripped off the last
	//word in the line that is read. this results in 'invalid read' errors in Valgrind because functions
	//like strlen() on line 254 rely on that null character to function properly. so, I manually add its
	//null character back on. 
	strcat(tokenizedWords[*tokenizedWordsCount],"\0");

	//check for invalid characters and convert each string to lowercase in the meantime
	for (int i = 0; i <= *tokenizedWordsCount; i++) {
		for (int j = 0; j < (strlen(tokenizedWords[i])); j++) {
			tokenizedWords[i][j] = tolower(tokenizedWords[i][j]);
			char c = tokenizedWords[i][j];
			if (!((c >= 'a' && c <= 'z') || c == ' ' || c == '\n')) {
      			printf("Invalid characters entered in query!\n");
      			cleanUp(index, tokenizedWords, tokenizedWordsCount);
      			exit(4); //invalid characters entered exit code
      		}
		}
	}
	//print user's query back to them in a clean, normalized form
	//removed extraneous spaces, converted all characters to lowercase,
	//and checked for any invalid characters
	printf("%s", "Query: ");
	for (int i = 0; i <= *tokenizedWordsCount; i++) {
		printf("%s ", tokenizedWords[i]);
	}
	printf("\n");
	return tokenizedWords;
}

/*
* Queries a directory of webpages created by crawler and indexed using indexer.
*/
void querier(char *pageDirectory, char *indexFileName) {
	//read search queries from stdin, one per line, until EOF
	//print the 'clean' query for user to see
	//use the index to identify the set of documents that satisfy the query
	//if no documents satisfy the query, print 'No documents match'
	
	//begin processing lines of queries
	char *line; 
	int count = 0;
	int *tokenizedWordsCount = &count; 
	line = readline(stdin); //read first line
	while (line != NULL) {
		hashtable_t *index = hashtable_new(1000); //initialize index hashtable
		indexStore(index, indexFileName); //load index from file
		char **tokenizedWords = tokenizeQuery(line, index, tokenizedWordsCount); //tokenize query
		if (line){free(line); line = NULL;} //free line and set to null after each loop iteration
		processQuery(pageDirectory, index, tokenizedWords, tokenizedWordsCount); //process query now
		//clean up
		cleanUp(index, tokenizedWords, tokenizedWordsCount);
		line = readline(stdin); //process next line
	}
	if (line){free(line); line = NULL;} //free line one last time
}

//used to test querier and ensure everything is working properly
//also used to build executable to run on command line
int main (int argc, char *argv[]) {
	//check number of arguments
	if (argc != 3) {
		printf("querier.c works by passing 2 arguments: pageDirectory, and indexFilename.\n");
		exit(1); //incorrect number of arguments
	}
	if (!isCrawlerDirectory(argv[1])) {
		printf("The chosen directory is not a valid crawler directory!\n");
		exit(2); //pageDirectory error
	}
	if (!access(argv[2], (F_OK || X_OK))) {
		printf("The chosen index file does not exist!\n");
		exit(3); //index file error
	}
	querier(argv[1], argv[2]);
	exit(0); //no errors
}

//**EXTRA CREDIT** : instead of printing no documents match, if the query is within
	//a certain threshold compared to the indexed words in the documents (perhaps there was a typo?),
	//ask the user 'Did you mean _____?' where the underscores represent the word in the index
	//that both has the shortest string length from the user-inputted word and also the most
	//number of instances that it appears in the index


 /* 
 * querier.h - header file for simple web querier module, part 3 of TSE project
 *
 * George Hito and Raunak Bhojwani, May 2016
 */

#ifndef __QUERIER_H
#define __QUERIER_H

#include <stdbool.h>

/**************** global types ****************/


/**************** functions ****************/
/*
* Consolidation of memory frees/data structure cleanups
*/
void cleanUp(hashtable_t *index, char **tokenizedWords, int *tokenizedWordsCount);

/*
* Compare the counts of two identical keys passed to two counters objects.
* This acts as an intersection between sets.
* Takes as parameters:
*	arg, which is a struct containing two counters objects
*	key, the key of the counters->key object in the counters set that is currently being iterated on
*	count, the count of each counters->key object in the counters set that is currently being iterated on
*/
void compareCountersAnd(void *arg, int key, int count);

/*
* Compare the counts of two identical keys passed to two counters objects.
* This acts as a union between sets.
* Takes as parameters:
*	arg, which is a counters object
*	key, the key of the counters->key object in the counters set that is currently being iterated on
*	count, the count of each counters->key object in the counters set that is currently being iterated on
*/
void compareCountersOr(void *arg, int key, int count);

/*
* Count the number of items in a counters set being iterated upon.
* Takes as parameters:
*	arg, which is a pointer to an integer and is incremented by 1
*	key, which is irrelevant
*	count, which is irrelevant
*/
void numberOfCountersItems(void *arg, int key, int count);

/*
* This function compares the scores of the DOCIDScore items that are passed
* to qsort(), and sorts them in ascending order for display to the user.
*/
int cmpfunc(const void *a, const void *b);

/*
* Fill an array with (docID,score) structs pulled from coutners objects
* Takes as parameters:
*	arg, which is a pointer to an integer and is incremented by 1
*	key, which is irrelevant
*	count, which is irrelevant
*/
void fillCountersArray(void *arg, int key, int count);

/*
* This function processes the query and prints out documents that match it in descending order.
* Takes as parameters: 
*	pageDirectory holding crawled pages
*	hashtable holding index
*	char** holding query words, normalized and tokenized, guaranteed to be 'correct' in
*		terms of query syntax and query ordering
*/
void processQuery(char *pageDirectory, hashtable_t *index, char **tokenizedWords, int *tokenizedWordsCount);

/*
* This function tokenizes the query and returns it broken up into a char**.
* Takes as parameters:
*	line holding latest query to be tokenized
*	int* to hold number of words in query
*/
char **tokenizeQuery(char *line, hashtable_t *index, int *tokenizedWordsCount);

/*
* Queries a directory of webpages created by crawler and indexed using indexer.
*/
void querier(char *pageDirectory, char *indexFileName);


#endif // __QUERIER_H

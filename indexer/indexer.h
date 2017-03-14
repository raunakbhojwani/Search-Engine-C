/* 
 * indexer.h - header file for simple indexer module, part 2 of TSE project
 *
 * George Hito and Raunak Bhojwani, May 2016
 */

#ifndef __INDEXER_H
#define __INDEXER_H

#include <stdbool.h>

/**************** global types ****************/


/**************** functions ****************/
/*
* The main indexer function, takes a pageDirectory filled with crawler output and
* outputs an index to indexFilename in a particular format.
*/
void indexer(char *pageDirectory, char *indexFilename);


#endif // __INDEXER_H

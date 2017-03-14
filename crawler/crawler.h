/* 
 * crawler.h - header file for simple web crawler module, part 1 of TSE project
 *
 * George Hito and Raunak Bhojwani, April 2016
 */

#ifndef __CRAWLER_H
#define __CRAWLER_H

#include <stdbool.h>

/**************** global types ****************/


/**************** functions ****************/
bool isWritableDirectory(char *dir);

void pageSaver(WebPage* page, char *pageDirectory);

void crawler(char *seedURL, char *pageDirectory, int maxDepth);


#endif // __CRAWLER_H

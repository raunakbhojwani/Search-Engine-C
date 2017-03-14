//simple web crawler, part 1 of the TSE project
//by George Hito and Raunak Bhojwani, MAy 2016

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "../lib/bag/bag.h"
#include "../lib/bag/bag.c"
#include "../lib/hashtable/hashtable.h"
#include "../lib/hashtable/hashtable.c"
#include "../lib/hashtable/list.h"
#include "../lib/hashtable/list.c"
#include "../lib/hashtable/jhash.h"
#include "../common/web.h"
#include "../lib/memory/memory.h"
#include "../lib/memory/memory.c"


//globals
int docID = 0;
const int FILENAMESIZE = 100; //arbitrary filename size

//use access() to check if directory exists and is writable, if so then write a
//.crawler file within
bool 
isWritableDirectory(char *dir) {
	//if valid directory, write a .crawler file inside
	if (access(dir, W_OK) == 0) {
		char testFile[FILENAMESIZE];
		char *testFilePointer = testFile;
		sprintf(testFilePointer, "%s/.crawler", dir);
		FILE *temp = fopen(testFilePointer, "w");
		fclose(temp);
		return true;
	}
	return false;
}

/*
* Outputs a page to the appropriate file
*/
void 
pageSaver(WebPage *page, char *pageDirectory) {
	//increment docID on function call
	docID++;
	//write file to pageDirectory
	char fileName[FILENAMESIZE];
	sprintf(fileName, "%s/%d", pageDirectory, docID);
	char *file = fileName;
	FILE *f = fopen(file, "w"); //open file for writing
	if (f == NULL) {
	    printf("Error opening file to save webpage!\n");
	    exit(6); //file open error 
	}
	//write URL (non-normalized), depth, and page content to file
	fprintf(f, "%s\n%d\n%s", page->url, page->depth, page->html);
	fclose(f); //close file
}

/* 
* Crawls webpages starting at seedURL and ending whenever maxDepth is reached.
*/
void 
crawler(char *seedURL, char *pageDirectory, int maxDepth) {	
	//initialize bag to hold pages to parse, and hashtable to hold already visited pages
	bag_t *pageHolder = bag_new();
	hashtable_t *pageRecorder = hashtable_new(1000); //arbitrary size of hashtable, change with depth of crawler as needed

	//initialize temp WebPage with seedURL and initial depth of zero to overwrite later
	WebPage *temp = malloc(2 * sizeof(WebPage)); //initialize memory buffer for webpages to be pulled from bag
	if (!NormalizeURL(seedURL)) { //if unable to normalize seed url for whatever reason, exit with error
		printf("Could not normalize seedURL!\n");
		free(temp);
		exit(7);
	}
	char *currentURL = malloc(10 * sizeof(char*));
	strcpy(currentURL, seedURL);
	temp->url = currentURL; //set initial seedURL in webpage to be inserted into bag
	temp->depth = 0; //set initial depth of temp
	temp->html = NULL;
	bag_insert(pageHolder,temp);

	//begin crawl from seed page
	while ((temp = bag_extract(pageHolder)) != NULL) { //while there are still webpages within the bag that haven't been crawled
		// sleep(1); //stagger crawling for one second to prevent server overload
		if (!GetWebPage(temp)) { //retrieve webpage for given url, if error continue to next one
			if (temp->html) {free(temp->html); temp->html = NULL;}
			if (temp->url && temp->url != seedURL) {free(temp->url); temp->url = NULL;}
			if (temp) {free(temp); temp = NULL;}
			continue;
		}
		pageSaver(temp, pageDirectory); //save fetched page into pageDirectory
		// printf("%s\n", temp->url);
		if (temp->depth < maxDepth) { //explore contents if page depth is less than maxdepth
			//pull all URLs from page one by one and process them
			char *URLholder = NULL;
			int pos = 0; //initialize pos to zero
			while ((pos = GetNextURL(temp->html, pos, temp->url, &URLholder)) > 0) {
				//for each URL inside the char array, process it
				if (!NormalizeURL(URLholder)) {
					printf("URL failed: %s\n", URLholder);
					if (URLholder) {free(URLholder); URLholder = NULL;}
					continue; //if URL can't be normalized for some reason, continue to next one
				}
				if (IsInternalURL(URLholder) && URLholder != NULL) { //if it is internal, insert into hashtable
					if(hashtable_insert(pageRecorder, URLholder, NULL)) { //if not in hashtable, insert it, otherwise skip
						WebPage *newPage = malloc(2 * sizeof(WebPage));
						newPage->url = URLholder;
						newPage->depth = temp->depth + 1;
						printf("%s\n",newPage->url);
						bag_insert(pageHolder,newPage);		
						continue;
					} 
				}
				// clean up URLholder at the end on internal while loop if it is not internal
				if (URLholder) {free(URLholder); URLholder = NULL;}
			}
		}
		// clean up temp at the end of each while loop
		if (temp->html) {free(temp->html); temp->html = NULL;}
		if (temp) {free(temp); temp = NULL;}
	}
	//if (((temp->url)) && *(temp->url) != *seedURL) {free(((temp->url))); (temp->url) = NULL;}
	//done with crawl, clean up mallocs, callocs, and data structures
	// if (temp->url) {free(temp->url); (temp->url) = NULL;}
	free(currentURL);
	bag_delete(pageHolder);
	hashtable_delete(pageRecorder);
}

/*
* Used to test crawler functions and ensure everything is working properly
*/
int 
main (int argc, char *argv[]) {
	//check number of arguments
	if (argc != 4) {
		printf("crawler.c works by passing 3 arguments: seedURL, pageDirectory, and maxDepth.\n");
		exit(1); //incorrect number of arguments
	}

	//check validity of arguments
	WebPage *seed = malloc(2 * sizeof(WebPage));
	seed->url = argv[1];
	if (!GetWebPage(seed)) {
		printf("there was an error retrieving the webpage!\n");
		exit(2); //pageDirectory error
	}
	free(seed->html);
	free(seed);
	if (!IsInternalURL(argv[1])) {
		printf("seedURL is not internal!\n");
		exit(3); //pageDirectory error
	}
	if (!isWritableDirectory(argv[2])) {
		printf("pageDirectory is either not writable or does not exist!\n");
		exit(4); //pageDirectory error
	}
	if (atoi(argv[3]) < 0 || atoi(argv[3]) > 10) {
		printf("maxDepth cannot be less than zero or greater than 10.\n");
		exit(5); //maxDepth less than 0 or greater than 10 error
	}
	//if arguments have no errors, make pageDirectory and begin crawl!
	mkdir(argv[2], 0777);
	crawler(argv[1], argv[2], atoi(argv[3]));
	exit(0); //no errors
}

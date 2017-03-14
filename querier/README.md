 ### README for querier.c
##### Raunak Bhojwani & George Hito, May 2016

**Compiling:**
	make
	make clean

**Usage:**
/* 
 * querier.c - search all the files in the pageDirectory provided, outputting a list of docIDs that matches the query in a descending order of rank/score.
 *         
 * usage: ./querier pageDirectory indexFilename
 *
 * where:
 *   pageDirectory is a directory that contains pages crawled by crawler.c
 *   indexFilename is a file that is written by indexer.c
 *
 * output:
 *   write to stdout the query itself, followed by a list of matches in descending order of rank.
 *   
 * stdin: stdin; the pagesDirectory and indexFilename
 * stdout: stdout
 * stderr: stdout
 *
 * Raunak Bhojwani & George Hito, May 2016
 *
 */

**Example command lines:**
	querier ../data ../indexer/INDEX

**Exit status:**
  0 - success
  1 - Incorrect number of arguments
  2 - pageDirectory is not writeable or doesn't exist or is not a crawler directory
  3 - unable to open/create indexFilename
  4 - Invalid characters entered in the query
  5 - Started or finished with and or or, or and/or put together
  6 - No query entered
  7 - Memory allocation error


**Assumptions:**

- It is assumed that pagesDirectory contains pages that have been crawled by the crawler program
- It is assumed that pagesDirectory is laid out in a way where each page is named its docID, ie: 1, 2, 3.... with no numbers skipped
- It is assumed that the index filename or the indextest new filename do not coincide with current code files in the directory. For example, it is possible to run "indexer ../data indexer.c" and overwrite the code!

Non-Assumptions:

- There are checks in place to normalize the query

Limitations:

- The program is written to read a pageDirectory in the very specific format that crawler outputs it, so it is dependable on the effectiveness crawler

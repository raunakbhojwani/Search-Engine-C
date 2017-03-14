### README for indexer.c
##### Raunak Bhojwani & George Hito, May 2016

**Compiling:**
	make

**Usage:**
/* 
 * indexer.c - read all the files in the pageDirectory provided, creating an inverted index data structure as a word counting structure for the words in the pages
 *             write this data structure into a file indicated indexFilename in the format: "word docID count docId count..."
 * 
 * usage: ./indexer pagesDirectory indexFilename
 *
 * where:
 *   pageDirectory is a directory that contains pages crawled and should be read by indexer
 *   indexFilename is a file that should be created/overwritten in the format indicated to indicated words, docIDs and counts.
 *
 * output:
 *   Use the index programs to read the appropriate pages and creating an inverted index data structure
 *   wrting this structure into a file: indexFilename
 *   
 * stdin: stdin; the pagesDirectory and indexFilename
 * stdout: indexFilename
 * stderr: stdout
 *
 * Raunak Bhojwani & George Hito, May 2016
 *
 */

Example command lines:
	
  indexer pages INDEX
  indexer ../data NEWINDEX
  indexer pageDirectory indexFilename

Exit status:
  0 - success
  1 - Incorrect number of arguments
  2 - pageDirectory is not writeable or doesn't exist
  3 - unable to open/create indexFilename

Assumptions:

- It is assumed that pagesDirectory contains pages that have been crawled by the crawler program
- It is assumed that pagesDirectory is laid out in a way where each page is named its docID, ie: 1, 2, 3.... with no numbers skipped
- It is assumed that the index filename or the indextest new filename do not coincide with current code files in the directory. For example, it is possible to run "indexer ../data indexer.c" and overwrite the code!

Non-Assumptions:

- There are checks in place to see if pagesDirectory exists and is writeable to, and also if indexFile can be opened

Limitations:

- The program is written to read a pageDirectory in the very specific format that crawler outputs it, so it is dependable on the effectiveness crawler

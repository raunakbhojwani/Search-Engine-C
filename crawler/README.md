### README for crawler.c
##### Raunak Bhojwani & George Hito, May 2016

**Compiling:**
	make

**Usage:**
/* 
 * crawler.c - crawl through the seedURL provided and the maximum depth indicated, storing all the pages visited into the pageDirectoy indicated
 * 
 * usage: crawler seedURL pagesDirectory maxDepth
 *
 * where:
 *   seedURL is considered as the initial URL,
 *   pageDirectory is a directory in which to download webpages, and
 *   maxDepth is the maximum crawl depth.
 *
 * output:
 *   Use the crawler and web programs to crawl the indicated URL to the indicated depth and reach the appropriate pages
 *   saving these pages in the indicated pagesDirectory with the html contect of each such page.
 *   
 * stdin: stdin; the seedURL, pagesDirectory and maxDepth
 * stdout: pageDirectory indicated for output files, stdout for potential errors
 * stderr: error messages
 *
 * Raunak Bhojwani & George Hito, May 2016
 *
 */

Example command lines:
	
  crawler http://old-www.cs.dartmouth.edu/~kotz/tse pages 0
  crawler http://old-www.cs.dartmouth.edu/~kotz/tse pages 1
  crawler http://old-www.cs.dartmouth.edu/~cs50/index.html 2
  crawler http://old-www.cs.dartmouth.edu/~cs50/index.html 3

Exit status:
  0 - success
  1 - Incorrect number of paramters
  2 - Error retrieving webpage
  3 - seedURL is not internal
  4 - pageDirectory is not writeable or it does not exist
  5 - maxDepth is less than 0
  6 - Error opening file to save webpage
  7 - Error normalizing the URL

Assumptions:

- We assume that for the program to work the seedURL provided is an internal URL and that the pagesDirectory is a directory that exists and can be written to.
- Code provided by Prof. Kotz works as indicated, integrating seamlessly with crawler.h and crawler.c


Non-Assumptions:

- There are checks in place to see if seedURL is internal and if pagesDirectory exists and is writeable to.
- MaxDepth must be more than 0 

Limitations:

- The program is written to crawl only internal pages, as defined by web.c
- Program can be very slow due to sleep function especially for a depth in excess of 2.


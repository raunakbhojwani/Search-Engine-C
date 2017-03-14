###Design Overview for Indexer
#####Raunak Bhojwani & George Hito, May 2016

**Requirements Specification:**
	**The indexer shall:**
		1. execute from a command line with usage syntax ./indexer pageDirectory indexFilename
					where pageDirectory is a directory produced by the crawler, and
					where indexFilename is the name of a file into which the index should be written.
		2. read documents from the pageDirectory, each of which has a unique document ID,
					wherein the document id starts at 1 and increments for each new document,
					and the filename is of form pageDirectory/id,
					and the first line of the file is the URL,
					and the second line of the file is the depth,
					and the rest of the file is the page content.
		3. build an inverted-index data structure mapping from words to (documentID, count) pairs, wherein each count represents the number of occurrences of the 			given word in the given document. Ignore words with fewer than three characters, and NormalizeWord before indexing.
		4. create a file indexFilename and write the index to that file, in the format described below.
		
		5. The indexer shall validate its command-line arguments:
					pageDirectory is a directory produced by the crawler (see below), and
					indexFilename is the name of a writeable file.
		6. The indexer may assume that

					pageDirectory has files named 1, 2, 3, …, without gaps.
					The content of files in pageDirectory follow the format as defined in the crawler specs; thus your code (to create a WebPage by reading a file) need not have extensive error checking.
		
	**The index tester shall:**

		1. execute from a command line with usage syntax ./indextest oldIndexFilename newIndexFilename
					where oldIndexFilename is the name of a file produced by the indexer, and
					where newIndexFilename is the name of a file into which the index should be written.
		2. load the index from the oldIndexFilename into an inverted-index data structure.
		3. create a file newIndexFilename and write the index to that file, in the format described below.
		4. It need not validate its command-line arguments other than to ensure that it receives precisely two arguments; it may simply try to open the 					oldIndexFilename for reading and, later, try to open the newIndexFilename for writing. You may use indextest.sh (provided) to verify that the 			  output is identical to (or equivalent to) the input.

		5. The index tester may assume that
					The content of the index file follows the format specified below; thus your code (to recreate an index structure by reading a file) need not have extensive error checking.
	
	**Index file format**
		The indexer writes the inverted index to a file, and the querier reads the inverted index from a file; the file must be in the following format.

		one line per word, one word per line
		each line provides the word and one or more (docID, count) pairs, in the format
		word docID count [docID count]…
		where word is a string of lower-case letters,
		where docID is a positive non-zero integer,
		where count is a positive non-zero integer,
		where the word and integers are separated by spaces.

**Design Specification:**

	The indexer is designed to create an inverted index data structure, leveraging the data structures created in lab 3. An inverted index data structure is simply
	a hashtable, implemented using lists. Each list has a key and data, and in this structure the key is the word, and its data is a Counter data structure. Each word has its own counter. Counters are also implemented like linked lists and contain a key and data. In this case the key will be the docID and data is the count, as in the number of times that word has appeared.

	In summary, the indexer uses a hashtable of lists that contain a counter.


**Implementation Specifation:**

	**indexer**
		To implement indexer, we will first create a string to store the filepath of each page, and the loop through each page, reading every word, normalizing it and adding it to the inverted index data strucutre. Once the entire data structure is complete, we will write this to the file using the iterate functions in the data strucutres.

	**indextest**
		To implement indextest, we will open up the file provided and use fscanf to read the formatted file. Use this information to build an inverted index data structure. Once built, write this data strucutre into the file using the abstract iterate functions as well as helper functions to pass to the iterators.
	


**Testing Plan:**

	Our plans to test this program are robust. We plan to start by successfully running the indexer with a valid pageDirectory and indexFile. Then, we want to pass an existing, writeable directory in the wrong format, an empty directory, and a non-existing directory. In order to robustly test indextest, we plan to give it an oldIndex file in the incorrect format, as well as an empty and nonexisting oldIndexFile. These errors should be caught by the programs. We will also run diff -s on INDEX and NEWINDEX to test how similar the two files are.
  
 ###Design Overview for Querier
#####Raunak Bhojwani & George Hito, May 2016

**Requirements Specification:**
	**The querier shall:**
		1. execute from a command line with usage syntax ./querier pageDirectory indexFilename
					where pageDirectory is a directory produced by the crawler, and
					where indexFilename is an index file produced by the indexer.
		2. load the index from indexFilename into an internal data structure.
		3. read search queries from stdin, one per line, until EOF.
		4. clean and parse each query according to the syntax described below.
		5. print the ‘clean’ query for user to see.
		6. use the index to identify the set of documents that satisfy the query, as described below.
					if no documents satisfy the query, print No documents match.
					otherwise, rank the resulting set of documents according to its score, as described below, and print the set of documents in decreasing rank order; for each, list the score, document ID and URL. (Obtain the URL by reading the first line of the relevant document file from the pageDirectory.)
		
	**The querier shall validate its command-line arguments:**
		1. pageDirectory is a directory produced by the crawler, and
		2. indexFilename is the name of a readable file.

	**The querier may assume:**
		1. that the input directory and files follow the designated formats.
		2. pageDirectory has files named 1, 2, 3, …, without gaps.
		3. The content of document files in pageDirectory follow the format as defined in the crawler specs; thus your code (to read a document file) need not have extensive error checking.
		4. The content of the file named by indexFilename follows our Index file format; thus your code (to recreate an index structure by reading a file) need not have extensive error checking.
	
	**Example Output from Querier**

		Query: dartmouth or computer science or programming or unix or doug mcilroy 
		Matches 7 documents (ranked):
		score 292 doc   7: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
		score   9 doc   4: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
		score   7 doc   6: http://old-www.cs.dartmouth.edu/~dfk/people.html
		score   6 doc   1: http://old-www.cs.dartmouth.edu/~dfk/index.html
		score   5 doc  10: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
		score   4 doc   9: http://old-www.cs.dartmouth.edu/
		score   4 doc   5: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
		--------------------------------------------------------------------------------------------

		Query: and 
		Error: 'and' cannot be first

		Query: or 
		Error: 'or' cannot be first

		Query: and dartmouth 
		Error: 'and' cannot be first

		Query: or dartmouth 
		Error: 'or' cannot be first

		Query: dartmouth college or 
		Error: 'or' cannot be last

		Query: dartmouth college and 
		Error: 'and' cannot be last

		Query: dartmouth college and or computer 
		Error: 'and' and 'or' cannot be adjacent

		Query: dartmouth college and and computer 
		Error: 'and' and 'and' cannot be adjacent

		Query: dartmouth college or and computer 
		Error: 'or' and 'and' cannot be adjacent
		Error: bad character '5' in query.
		Error: bad character '!' in query.
		Error: bad character '-' in query.

**Design Specification:**

	The querier makes use of an inverted index data structure. An inverted index data structure is simply a hashtable, implemented using lists. Each list has a key and data, and in this structure the key is the word, and its data is a Counter data structure. Each word has its own counter. Counters are also implemented like linked lists and contain a key and data. In this case the key will be the docID and data is the count, as in the number of times that word has appeared.

	In summary, the querier allows the user to search for words in a directory of pages.

**Implementation Specifation:**

	**querier**
	The querier is designed to search for words in the pageDirectory indicated, leveraging the data structures created in lab 3. It does this by creating an inverted index data structure is simply, much like in indextest, from the indexFilename provided. Once it does this, it searches for the words indicated in the query, and ranks them based on the structure of the query, correctly handling 'and' and 'or' and then outputs the documents in a descending order in terms of score. 

	The program is designed to read the query, and parse it to create an array of words. The program correctly deals with errors like beginning and concluding with 'and' or 'or' and other unwanted characters. Once the query has been normalized, the program reads each word and finds its corresponding counter object from the inverted index data structure. The program manipulates this data to then appropriately calculate scores for each docID for each query. Then, the program outputs the top scores in the method presented.

**Testing Plan:**

	Our plans to test this program are robust. We plan to start by testing valid queries: single word searches, disjunction searches, conjuction searches and a combination of both or-sequences and and-sequences. Furthermore, we plan to test querier with errors in the query, like for example with and/or in the beginning or the end, and with special characters. Lastly, we will test querier with a non existant indexFilename and an unwriteable or non-existant pageDirectory.
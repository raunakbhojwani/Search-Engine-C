### The Tiny Search Engine
##### Raunak Bhojwani & George Hito, May 2016

**Compiling:**
	make
  make clean

**Information**
  This project, the tiny search engine, has several components to it. All these components can be compiled and decompiled by make and make clean respectively. The first component, the crawler, crawls a seedURL provided to a maxDepth indicated and saves all the pages it visits into a pageDirectory. The indexer, the second part of the TSE, uses this directory to read each page and creat and inverted index data structure, which is then written into and indexFile in the specified format: "word docID count docID count...". The third of the project, the querier leverages the inverted index data structure to search through the page directory's contents for words. Use the queries, users can search for different combinations of words that occur in pageDirectory. The program will output a ranking of documents that match the specified query.

**Usage:**
	You can run these programs in a few different ways. Once you make all executables you can either cd into the relevant directory, crawler or indexer or querier, and run each executable or you can run it from the parent directory using indexer/indexer or crawler/crawler or querier/querier.
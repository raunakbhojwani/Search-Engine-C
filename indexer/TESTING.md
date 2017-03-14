###TESTING for indexer and indextest
#####Raunak Bhojwani & George Hito, May 2016


Last login: Mon May  9 20:28:51 on ttys000
ivybridge:~ georgehito$ ssh george@flume.cs.dartmouth.edu
george@flume.cs.dartmouth.edu's password: 
Last login: Mon May  9 20:28:55 2016 from 10.31.200.136

[flume:~] 101) cd cs50/labs/tse

[flume:tse] 102) make clean
cd crawler; make clean
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/crawler'
rm -f *~
rm -f *.o
rm -f crawler
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/crawler'
cd indexer; make clean
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/indexer'
rm -f *~
rm -f *.o
rm -f 
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/indexer'
cd common; make clean
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/common'
rm -f *~
rm -f *.o
rm -f common.a
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/common'
cd lib; make clean
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib'
rm -f *~
rm -f *.o
rm -f cs50ds.a
cd memory; make clean
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/memory'
rm -f *~
rm -f *.o
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/memory'
cd bag; make clean
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/bag'
rm -f *~
rm -f *.o
rm -f bagtest
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/bag'
cd hashtable; make clean
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
rm -f *~
rm -f *.o
rm -f hashtabletest
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
cd counters; make clean
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/counters'
rm -f *~
rm -f *.o
rm -f counterstest
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/counters'
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib'

[flume:tse] 103) make
cd lib; make
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib'
cd memory; make memory.o
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/memory'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o memory.o memory.c
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/memory'
cd bag; make bag.o
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/bag'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o bag.o bag.c
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/bag'
cd hashtable; make hashtable.o
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o hashtable.o hashtable.c
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
cd counters; make counters.o
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/counters'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o counters.o counters.c
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/counters'
cd hashtable; make list.o
make[2]: Entering directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o list.o list.c
make[2]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib/hashtable'
ar cr cs50ds.a memory/memory.o bag/bag.o hashtable/hashtable.o counters/counters.o hashtable/list.o
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib'
cd common; make
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/common'
gcc -c -o file.o file.c -Wall -pedantic -std=c11 -ggdb
gcc -c -o web.o web.c -Wall -pedantic -std=c11 -ggdb
gcc -c -o word.o word.c -Wall -pedantic -std=c11 -ggdb
ar cr common.a file.o web.o word.o
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/common'
cd crawler; make
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/crawler'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb crawler.o ../lib/cs50ds.a ../common/common.a -lcurl -o crawler
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/crawler'
cd indexer; make all
make[1]: Entering directory '/net/tahoe3/george/cs50/labs/tse/indexer'
gcc -Wall -pedantic -std=c11 -ggdb   -c -o indexer.o indexer.c
gcc -Wall -pedantic -std=c11 -ggdb indexer.o ../common/common.a ../lib/cs50ds.a -lcurl -o indexer
gcc -Wall -pedantic -std=c11 -ggdb   -c -o indextest.o indextest.c
gcc -Wall -pedantic -std=c11 -ggdb indextest.o ../common/common.a ../lib/cs50ds.a -lcurl -o indextest
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/indexer'

[flume:tse] 104) cd indexer

**INDEXER SUCCESS**

[flume:indexer] 105) ./indexer ../data INDEX

**incorrect directory**

[flume:indexer] 106) ./indexer ../data2 INDEX
The chosen directory is not a valid crawler directory!

**INDEXTEST SUCCESS**

[flume:indexer] 107) ./indextest INDEX NEWINDEX

**RUNNING DIFF - BOTH IDENTIAL**

[flume:indexer] 108) diff -s INDEX NEWINDEX
Files INDEX and NEWINDEX are identical

**INVALID FILE**
[flume:indexer] 109) ./indextest INDEXFAKE NEWINDEX
Invalid file

**INCORRECT ARGUMENTS**
[flume:indexer] 110) ./indextest INDEXFAKE 
indexer.c works by passing 2 arguments: pageDirectory, and indexFilename.

[flume:indexer] 111) ./indextest INDEXFAKE INDEX INDEX INDEX
indexer.c works by passing 2 arguments: pageDirectory, and indexFilename.


**VALGRIND INDEXER**

[flume:indexer] 112) valgrind --leak-check=full --show-leak-kinds=all indexer ../data INDEX
==16303== Memcheck, a memory error detector
==16303== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==16303== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==16303== Command: indexer ../data INDEX
==16303== 
==16303== 
==16303== HEAP SUMMARY:
==16303==     in use at exit: 0 bytes in 0 blocks
==16303==   total heap usage: 294,621 allocs, 294,621 frees, 21,794,616,514 bytes allocated
==16303== 
==16303== All heap blocks were freed -- no leaks are possible
==16303== 
==16303== For counts of detected and suppressed errors, rerun with: -v
==16303== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

**VALGRIND INDEXTEST**

[flume:indexer] 113) valgrind --leak-check=full --show-leak-kinds=all indextest INDEX NEWINDEX
==16334== Memcheck, a memory error detector
==16334== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==16334== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==16334== Command: indextest INDEX NEWINDEX
==16334== 
==16334== 
==16334== HEAP SUMMARY:
==16334==     in use at exit: 0 bytes in 0 blocks
==16334==   total heap usage: 11,620 allocs, 11,620 frees, 206,656 bytes allocated
==16334== 
==16334== All heap blocks were freed -- no leaks are possible
==16334== 
==16334== For counts of detected and suppressed errors, rerun with: -v
==16334== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

[flume:indexer] 114) logout
Connection to flume.cs.dartmouth.edu closed.
ivybridge:~ georgehito$ 

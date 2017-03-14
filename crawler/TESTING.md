### TESTING
#####T his file tests several different contingencies in the crawler program including but not limited to:
##### incorrect parameters, incorrect depth, incorrect directory, incorrect URLs, as well as all correct parameters with depths of 0, 1, 2, 3.


Last login: Mon May  2 20:34:25 on ttys001
ivybridge:~ georgehito$ ssh -l george flume.cs.dartmouth.edu
george@flume.cs.dartmouth.edu's password: 
Last login: Mon May  2 20:34:35 2016 from 10.31.196.2

[flume:~] 101) make clean
make: *** No rule to make target 'clean'.  Stop.

[flume:~] 102) cd cs50/labs/tse

[flume:tse] 103) make clean
rm -f *~
rm -f *.o
rm -f crawler
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
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib'

[flume:tse] 104) make
gcc -Wall -pedantic -std=c11 -ggdb   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb   -c -o web.o web.c
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
ar cr cs50ds.a memory/memory.o bag/bag.o hashtable/hashtable.o
make[1]: Leaving directory '/net/tahoe3/george/cs50/labs/tse/lib'
gcc -Wall -pedantic -std=c11 -ggdb crawler.o web.o lib/cs50ds.a -lcurl -o crawler

[flume:tse] 105) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 0
http://old-www.cs.dartmouth.edu/~cs50/index.html

[flume:tse] 106) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 1
http://old-www.cs.dartmouth.edu/~cs50/index.html
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~cs50/

[flume:tse] 107) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 2
http://old-www.cs.dartmouth.edu/~cs50/index.html
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
URL failed: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
http://old-www.cs.dartmouth.edu/~dfk/seatpack/
http://old-www.cs.dartmouth.edu/~dfk/kids.html
http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
http://old-www.cs.dartmouth.edu/~dfk/teaching.html
http://old-www.cs.dartmouth.edu/~dfk/people.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
http://old-www.cs.dartmouth.edu/
http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
http://old-www.cs.dartmouth.edu/~cs50/
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~cs50/

[flume:tse] 108) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 3
http://old-www.cs.dartmouth.edu/~cs50/index.html
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
URL failed: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
http://old-www.cs.dartmouth.edu/~dfk/seatpack/
http://old-www.cs.dartmouth.edu/~dfk/kids.html
http://old-www.cs.dartmouth.edu/~dfk/#contact
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
http://old-www.cs.dartmouth.edu/~dfk/people.html
http://old-www.cs.dartmouth.edu/~dfk/teaching.html
http://old-www.cs.dartmouth.edu/~cs50/
http://old-www.cs.dartmouth.edu/~epics/
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~dfk/people.html
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/graduation2008b.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/MurthyGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/CorneliusGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/TanGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/DeshpandeGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/MingLiGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/NandaGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/SongGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/MinamiGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/ChenGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/OldfieldGrad.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/BredinGrad.jpg
http://old-www.cs.dartmouth.edu/~map
http://old-www.cs.dartmouth.edu/~bennet
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
http://old-www.cs.dartmouth.edu/~dfk/armada/
http://old-www.cs.dartmouth.edu/
http://old-www.cs.dartmouth.edu/~amolina
http://old-www.cs.dartmouth.edu/~ashubina/
http://old-www.cs.dartmouth.edu/~rapjr
http://old-www.cs.dartmouth.edu/~tjp/
http://old-www.cs.dartmouth.edu/~shrirang/
http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
http://old-www.cs.dartmouth.edu/~dfk/favorites.html
http://old-www.cs.dartmouth.edu/~dfk/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
URL failed: http://www.cs.dartmouth.edu/~dfk/vita.pdf
URL failed: http://arnetminer.org/viewperson.do?naid=465549&name=David%20Kotz
URL failed: http://gaia.cs.umass.edu/pc3/index.htm
URL failed: http://www.nsf.gov/awardsearch/showAward.do?AwardNumber=1329686
URL failed: http://www.nsf.gov/awardsearch/showAward.do?AwardNumber=1314281
URL failed: http://www.nsf.gov/awardsearch/showAward.do?AwardNumber=0910842
URL failed: http://www.nsf.gov/awardsearch/showAward.do?AwardNumber=1016823
URL failed: http://www.nsf.gov/awardsearch/showAward.do?AwardNumber=1143548
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-agenda.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/pierson-wanda.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././pierson-wanda.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/pierson-wanda-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././pierson-wanda-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-frontiers.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-frontiers.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-voice-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-voice-tr.pdf
URL failed: http://dx.doi.org/10.1145/2594368.2594369
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-wearable.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-wearable.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/liang-healthtech14.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-hns-j.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-hns-j.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-zebra-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-zebra-tr.pdf
URL failed: http://dx.doi.org/10.1109/SP.2014.51
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-zebra14.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-zebra14.pdf
URL failed: http://dx.doi.org/10.1145/2594368.2601454
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mm-amulet-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mm-amulet-poster.pdf
URL failed: http://dx.doi.org/10.1145/2676431.2676432
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/molina-markham-wmmadd.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././molina-markham-wmmadd.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2014.6734920
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/murthy-bp.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././murthy-bp.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/murthy-thesis.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././murthy-thesis.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/peters-emg-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././peters-emg-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-bfitbit.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-bfitbit.pdf
URL failed: http://dx.doi.org/10.1145/2594368.2601448
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-mobisys-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-mobisys-poster.pdf
URL failed: http://dx.doi.org/10.1109/MSP.2013.104
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/anthony-sith3.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././anthony-sith3.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-thesis.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-thesis.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kini-compliance-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kini-compliance-tr.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2013.6465599
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-nethealth13.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-nethealth13.pdf
URL failed: http://dx.doi.org/10.1145/2379776.2379779
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/avancha-survey.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././avancha-survey.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-biometrics-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-biometrics-poster.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-impedance.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-impedance.pdf
URL failed: http://dx.doi.org/10.1016/j.pmcj.2012.06.005
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-j-same-body.bib
URL failed: http://dx.doi.org/10.1145/2381966.2381983
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-fitbit.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-fitbit.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-msthesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2012-711.pdf
URL failed: http://dx.doi.org/10.1145/2396276.2396287
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-provenance-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-provenance-poster.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/smithayer-bp.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././smithayer-bp.pdf
URL failed: http://dx.doi.org/10.1145/2162081.2162092
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sorber-amulet.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sorber-amulet.pdf
URL failed: http://dx.doi.org/10.1145/2307636.2307665
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sorber-pnt.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sorber-pnt.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-same-body.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-same-body.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2011.5716518
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-mHealth-threats.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-mHealth-threats.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-healthsec11.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-healthsec11.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-hns-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-hns-tr.pdf
URL failed: http://dx.doi.org/10.1145/2046556.2046574
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-hns-w.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-hns-w.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-healthsec11.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-healthsec11.pdf
URL failed: http://dx.doi.org/10.1145/1999995.2000058
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sorber-pnt-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sorber-pnt-poster.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-healthsec10.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-healthsec10.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-healthsec10.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-healthsec10.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/prasad-healthsec10.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././prasad-healthsec10.pdf
URL failed: http://dx.doi.org/10.4108/ICST.MOBIQUITOUS2009.6829
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-mpcs.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-mpcs.pdf
URL failed: http://dx.doi.org/10.1145/1655084.1655086
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-mhealth-spimacs.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-mhealth-spimacs.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sriram-challenges.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sriram-challenges.pdf
URL failed: http://dx.doi.org/10.1145/1647314.1647378
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sriram-ecg.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sriram-ecg.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/shin-anonytiles.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././shin-anonytiles.pdf
URL failed: http://dx.doi.org/10.1016/j.pmcj.2010.04.001
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/shin-anonysense.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././shin-anonysense.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/./internal/shin-anonysense.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/peebles-anonytl.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././peebles-anonytl.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2009.4808850
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kapadia-metrosec-challenges.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kapadia-metrosec-challenges.pdf
URL failed: http://dx.doi.org/10.1109/SAHCN.2009.5168925
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/shin-deamon.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././shin-deamon.pdf
URL failed: http://dx.doi.org/10.1145/1378600.1378624
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cornelius-anonysense.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cornelius-anonysense.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kapadia-anonysense.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kapadia-anonysense.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/shin-senseright-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././shin-senseright-poster.pdf
URL failed: http://dx.doi.org/10.1109/MPRV.2007.83
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/anthony-pervasive.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././anthony-pervasive.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/johnson-metrosec-challenges-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././johnson-metrosec-challenges-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kapadia-walls.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kapadia-walls.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-handbook.bib
URL failed: http://books.emeraldinsight.com/display.asp?K=9781848551947
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-scalability.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././minami-scalability.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2006-571.pdf
URL failed: http://dx.doi.org/10.1109/PERCOM.2005.37
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-csa.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././minami-csa.pdf
URL failed: http://dx.doi.org/10.1016/j.pmcj.2005.01.004
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-jcsa.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././minami-jcsa.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-csa-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././minami-csa-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/minami-aclprop-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././minami-aclprop-tr.pdf
URL failed: http://dx.doi.org/10.1504/IJCNDS.2009.026555
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/li-ijcnds.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././li-ijcnds.pdf
URL failed: http://dx.doi.org/10.1016/j.pmcj.2007.10.001
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-jsolar.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-jsolar.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/li-jfilter.bib
URL failed: http://www.cs.dartmouth.edu/~dfk/papers/internal/li-jfilter.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/./internal/li-jfilter.pdf
URL failed: http://dx.doi.org/10.1145/1385989.1385998
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/li-quality.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././li-quality.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mingli-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2008-621.pdf
URL failed: http://dx.doi.org/10.1109/ICDCSW.2007.38
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/li-wwasn07.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././li-wwasn07.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-bnaming.bib
URL failed: http://dx.doi.org/10.1109/PERCOM.2005.32
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-pack.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-pack.pdf
URL failed: http://dx.doi.org/10.1109/ICAC.2004.1301375
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-dependency.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-dependency.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-dependency-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-dependency-tr.pdf
URL failed: http://dx.doi.org/10.1109/MOBIQ.2004.1331731
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-fusenet.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-fusenet.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-pack-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-pack-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2004-514.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/wang-meeting.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././wang-meeting.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/wang-meeting-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././wang-meeting-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/wang-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2004-513.pdf
URL failed: http://dx.doi.org/10.1109/PERCOM.2003.1192747
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-naming.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-naming.pdf
URL failed: http://dx.doi.org/10.1109/MCSA.2002.1017490
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-abstraction.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-abstraction.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-abstraction-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-abstraction-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-pervasive.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-pervasive.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-pervasive-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-pervasive-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-solar.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-solar.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-solar-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-solar-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-survey-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-survey-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-kerf-news.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././aslam-kerf-news.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-kerf-WIP.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././aslam-kerf-WIP.pdf
URL failed: http://dx.doi.org/10.1109/MSP.2004.113
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-toolkit.bib
URL failed: http://ieeexplore.ieee.org/iel5/8013/29915/01366118.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-toolkit-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././aslam-toolkit-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-toolkit-p.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././aslam-toolkit-p.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-end-to-end.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-end-to-end.pdf
URL failed: http://dx.doi.org/10.1145/346152.346268
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-restricted.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-restricted.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-spki.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-spki.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-spki-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-spki-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-thesis.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-calculus-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-calculus-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-snowflake2-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././howell-snowflake2-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/howell-snowflake.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-jclassify.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-jclassify.pdf
URL failed: http://dx.doi.org/10.1109/INFOCOM.2006.173
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-mobility.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-mobility.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-wardriving.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-wardriving.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-classify.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-classify.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-classify-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-classify-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kim-hotspots.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kim-hotspots.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2008-611.pdf
URL failed: http://dx.doi.org/10.1145/1287791.1287799
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-dtn.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././song-dtn.pdf
URL failed: http://dx.doi.org/10.1109/TMC.2006.185
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-jpredict.bib
URL failed: http://ieeexplore.ieee.org/iel5/7755/36129/01717434.pdf
URL failed: http://dx.doi.org/10.1109/INFOCOM.2006.171
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-reserv.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././song-reserv.pdf
URL failed: http://dx.doi.org/10.1145/1215976.1215987
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-reserv-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././song-reserv-poster.pdf
URL failed: http://dx.doi.org/10.1145/965732.965747
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-predict.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././song-predict.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-predict-tr.bib
URL failed: http://dx.doi.org/10.1145/965732.965747
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-predict-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././song-predict-poster.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/song-predict-tr-old.bib
URL failed: http://dx.doi.org/10.1109/IPCCC.2002.995160
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mills-tettey-mvoip.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mills-tettey-mvoip.pdf
URL failed: http://dx.doi.org/10.1109/TMC.2012.237
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-dist.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././tan-dist.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2011-703.pdf
URL failed: http://dx.doi.org/10.1145/1741866.1741894
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/arackaparambil-clock-skew.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././arackaparambil-clock-skew.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/arackaparambil-clock-skew-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././arackaparambil-clock-skew-tr.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2010.5431957
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/mare-models.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././mare-models.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-saluki.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././tan-saluki.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bratus-dist-cset.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bratus-dist-cset.pdf
URL failed: http://dx.doi.org/10.1145/1352533.1352543
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bratus-fingerprint.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bratus-fingerprint.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bratus-fingerprint-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bratus-fingerprint-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bratus-streaming-poster.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bratus-streaming-poster.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/deshpande-refocusing.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/./internal/deshpande-refocusing.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/deshpande-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2008-620.pdf
URL failed: http://dx.doi.org/10.1109/MWC.2008.4653127
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sheng-map.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sheng-map.pdf
URL failed: http://dx.doi.org/10.1109/INFOCOM.2007.239
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sheng-spoofing.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././sheng-spoofing.pdf
URL failed: http://dx.doi.org/10.1109/ICON.2007.4444112
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/deshpande-coordinated.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././deshpande-coordinated.pdf
URL failed: http://dx.doi.org/10.1109/WIOPT.2006.1666486
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/deshpande-sampling.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././deshpande-sampling.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/baek-survey-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././baek-survey-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-dartmouth-campus-20090909.bib
URL failed: http://dx.doi.org/10.1016/j.comnet.2008.05.003
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-jvoice.bib
URL failed: http://www.cs.dartmouth.edu/~dfk/papers/internal/henderson-jvoice.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/./internal/henderson-jvoice.pdf
URL failed: http://dx.doi.org/10.1002/0471755591.ch1
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-measuring.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/blinn-hotspot.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././blinn-hotspot.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-social-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-social-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-esm.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././henderson-esm.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jcampus.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jcampus.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/chen-traces.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././chen-traces.pdf
URL failed: http://dx.doi.org/10.1145/1023720.1023739
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-voice.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././henderson-voice.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-voice-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././henderson-voice-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-problems.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././henderson-problems.pdf
URL failed: http://dx.doi.org/10.1145/570645.570659
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-campus.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-campus.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-campus-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-campus-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-campus-tr2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-campus-tr2.pdf
URL failed: http://dx.doi.org/10.1109/COMSNETS.2012.6151387
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/fazio-sampling.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././fazio-sampling.pdf
URL failed: http://dx.doi.org/10.1145/1998412.1998416
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/fazio-netsani.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././fazio-netsani.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/fazio-thesis.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././fazio-thesis.pdf
URL failed: http://dx.doi.org/10.1109/INFCOM.2011.5935168
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-crf.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././tan-crf.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-crf-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././tan-crf-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-survey.bib
URL failed: http://dx.doi.org/10.1145/1860039.1860050
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/tan-crf-s3.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././tan-crf-s3.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/yeo-poll-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././yeo-poll-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/henderson-citation-practices.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././henderson-citation-practices.pdf
URL failed: http://dx.doi.org/10.1145/1384609.1384619
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/yeo-crawdad-2007.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././yeo-crawdad-2007.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/yeo-crawdad-mc2r.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././yeo-crawdad-mc2r.pdf
URL failed: http://dx.doi.org/10.1145/1129582.1129588
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/yeo-crawdad-ccr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././yeo-crawdad-ccr.pdf
URL failed: http://dx.doi.org/10.1109/MPRV.2005.75
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-crawdad-workshop05.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-crawdad-workshop05.pdf
URL failed: http://dx.doi.org/10.1109/WCNC.2011.5779252
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-llbc.bib
URL failed: http://www.cs.dartmouth.edu/~dfk/papers/nanda-llbc-corrected.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-combined-tr2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nanda-combined-tr2.pdf
URL failed: http://dx.doi.org/10.1016/j.comcom.2008.01.046
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-jmeshmon.bib
URL failed: http://dx.doi.org/10.1109/ICCCN.2008.ECP.31
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-lbc.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nanda-lbc.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-lbc-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nanda-lbc-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2008-619.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nanda-combined-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nanda-combined-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/newport-axioms.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kumar-fbcast.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kumar-fbcast.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/jiang-msthesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2005-566.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/liu-jdirex.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././liu-jdirex.pdf
URL failed: http://dx.doi.org/10.1145/1023663.1023703
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-compare.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-compare.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-compare-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-compare-tr.pdf
URL failed: http://dx.doi.org/10.1145/1023663.1023679
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-axioms.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-axioms.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-axioms-tr2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-axioms-tr2.pdf
URL failed: http://dx.doi.org/10.1109/PADS.2004.1301280
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/liu-direx.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././liu-direx.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-axioms-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-axioms-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-motivation.bib
URL failed: http://www.cs.dartmouth.edu/~dfk/papers/gray-motivation-tr.pdf
URL failed: http://dx.doi.org/10.1002/spe.449
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-spe.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-spe.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/grimstrup-gmas.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././grimstrup-gmas.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-dwta.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-dwta.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-dwta-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-dwta-tr.pdf
URL failed: http://dx.doi.org/10.1145/506882.506889
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jmodel.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jmodel.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/aslam-position.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././aslam-position.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-scalability.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-scalability.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-scalability-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-scalability-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/grimstrup-gmas-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././grimstrup-gmas-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-motivation-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-motivation-tr.pdf
URL failed: http://dx.doi.org/10.1145/346855.346868
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-model.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-model.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-model-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-model-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-model-tr2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-model-tr2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/brewington-IR.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././brewington-IR.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-bmobile.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-future.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-future.pdf
URL failed: http://dx.doi.org/10.1145/311124.311130
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-future2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-future2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-security-book.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-security-book.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-bookchap.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-bookchap.pdf
URL failed: http://dx.doi.org/10.1109/AISPAS.1997.581620
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-mobile.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-mobile.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/hirschl-agdb.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././hirschl-agdb.pdf
URL failed: http://dx.doi.org/10.1109/4236.612217
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jmobile.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jmobile.pdf
URL failed: http://dx.doi.org/10.1145/267658.267721
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/rus-autonomous2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././rus-autonomous2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/rus-autonomous3.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././rus-autonomous3.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/rus-autonomous4.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/gray-mobile-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././gray-mobile-tr.pdf
URL failed: http://dx.doi.org/10.1145/504450.504458
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-agents.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-agents.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nog-rpc-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nog-rpc-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/rus-autonomous.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././rus-autonomous.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotay-agents.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotay-agents.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-jgame.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-jgame.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-game-book.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-game-book.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-info.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-info.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2001-408.pdf
URL failed: http://dx.doi.org/10.1145/336595.337525
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-game.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-game.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-risk.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-risk.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-game-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-game-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-lottery.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-lottery-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-lottery-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-position.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-position.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-demand.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-demand.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-demand-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-demand-tr.pdf
URL failed: http://dx.doi.org/10.1145/280765.280801
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-market.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-market.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/bredin-market-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././bredin-market-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-restruct.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././oldfield-restruct.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR2003-459.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-emulab-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././oldfield-emulab-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-framework.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././oldfield-framework.pdf
URL failed: http://dx.doi.org/10.1109/CCGRID.2001.923193
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-armada.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././oldfield-armada.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/carter-vesta.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././carter-vesta.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/khanna-group.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././khanna-group.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-jgalley.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-jgalley.pdf
URL failed: http://dx.doi.org/10.1145/232302.232314
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-flexibility.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-flexibility.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-flexibility2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-flexibility2.pdf
URL failed: http://dx.doi.org/10.1145/237578.237639
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-galley.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-galley.pdf
URL failed: http://dx.doi.org/10.1145/236017.236038
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-galley-perf.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-galley-perf.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-jgalley-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-jgalley-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-strided2-book.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-thesis.bib
URL failed: http://www.cs.dartmouth.edu/reports/TR96-300.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-explore.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-explore.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-strided2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-strided2-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-strided2-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-explore-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-explore-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-strided.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-strided.pdf
URL failed: http://dx.doi.org/10.1109/71.539739
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-workload.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-workload.pdf
URL failed: http://dx.doi.org/10.1109/IPPS.1995.395928
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ap-workload.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././ap-workload.pdf
URL failed: http://dx.doi.org/10.1109/88.384584
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jworkload.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jworkload.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nieuwejaar-workload-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nieuwejaar-workload-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ap-workload-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././ap-workload-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ellis-chicken-egg.bib
URL failed: http://dx.doi.org/10.1109/SUPERC.1994.344328
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-workload.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-workload.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-workload-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-workload-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-bdiskdir.bib
URL failed: http://dx.doi.org/10.1145/244764.244766
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jdiskdir.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jdiskdir.pdf
URL failed: http://dx.doi.org/10.1145/236017.236034
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ap-enwrich.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././ap-enwrich.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-tuning.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-tuning.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ap-enwrich-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././ap-enwrich-tr.pdf
URL failed: http://dx.doi.org/10.1109/SPDP.1995.530723
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-expand.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-expand.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-expand-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-expand-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-int-ddio.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-int-ddio.pdf
URL failed: http://dx.doi.org/10.1109/HPDC.1995.518706
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-lu.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-lu.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-lu-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-lu-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-diskdir.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-diskdir.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-diskdir-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-diskdir-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-diskdir2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-diskdir2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-bpractical.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jpractical.bib
URL failed: http://www.springerlink.com/content/p30l390211r7327k/fulltext.pdf
URL failed: http://dx.doi.org/10.1006/jpdc.1993.1012
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jwriteback.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jwriteback.pdf
URL failed: http://dx.doi.org/10.1109/PDIS.1991.183101
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-practical.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-practical.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-thesis.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-thesis.pdf
URL failed: http://dx.doi.org/10.1109/SPDP.1991.218296
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-writeback.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-writeback.pdf
URL failed: http://dx.doi.org/10.1109/71.80133
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-prefetch.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ellis-prefetch.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-umiacs.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-umiacs.slides.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-umiacs.slides.mov
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ellis-prefetchTR.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././ellis-prefetchTR.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-encyc2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-encyc2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-bapp-pario.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-encyc1.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-encyc1.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/oldfield-app-pario.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././oldfield-app-pario.pdf
URL failed: http://dx.doi.org/10.1145/242224.242488
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/choudhary-sdcr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-app-pario.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-app-pario.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-pioarch.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-pioarch.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/reed-panel.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././reed-panel.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-iobib.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-diskmodel.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-diskmodel.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cormen-integrate.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cormen-integrate.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/cormen-integrate-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././cormen-integrate-tr.pdf
URL failed: http://dx.doi.org/10.1109/PDIS.1993.253093
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-fsint2.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-fsint2.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-throughput.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-throughput.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-fsint.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-fsint.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-fsint2p.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-fsint2p.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-pan.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-pan.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/ellis-numatic.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jaddrtrace.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jaddrtrace.pdf
URL failed: http://dx.doi.org/10.1145/183019.183036
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-addrtrace.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-addrtrace.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-addrtrace-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-addrtrace-tr.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-jdapple.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-jdapple.pdf
URL failed: http://dx.doi.org/10.1145/199688.199730
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-dapple.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-dapple.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/johnson-freshmen.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././johnson-freshmen.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-dapple-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-dapple-tr.pdf
URL failed: http://dx.doi.org/10.1145/169070.169105
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/astrachan-contest.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././astrachan-contest.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/astrachan-contest-tr.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././astrachan-contest-tr.pdf
URL failed: http://dx.doi.org/10.1117/12.555797
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-ists.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-ists.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-privacy.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-privacy.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-review-brawer.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/nog-networks.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././nog-networks.pdf
URL failed: http://dx.doi.org/10.1109/ICDCS.1989.37968
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-pools.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-pools.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-pools.slides.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-pools.slides.mov
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-bfplus.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-bfplus.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/kotz-poolsTR.bib
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/././kotz-poolsTR.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/papers/bibtex/sullivan-prism.bib
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sullivan-prism.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-poolsTR.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-bfplus.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-pools.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nog-networks.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-review-brawer.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-privacy.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-ists.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/astrachan-contest-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/astrachan-contest.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-dapple-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/johnson-freshmen.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-dapple.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jdapple.html
http://old-www.cs.dartmouth.edu/~dfk/ILI/dapple/
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-addrtrace-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-addrtrace.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jaddrtrace.html
http://old-www.cs.dartmouth.edu/~dfk/sasos/
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ellis-numatic.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-pan.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-fsint2p.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-fsint.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-throughput.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-fsint2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cormen-integrate-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cormen-integrate.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-diskmodel.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-iobib.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/reed-panel.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-pioarch.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-app-pario.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/choudhary-sdcr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-app-pario.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-encyc1.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-bapp-pario.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-encyc2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ellis-prefetchTR.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-umiacs.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ellis-prefetch.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-prefetch.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-writeback.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-practical.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jwriteback.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jpractical.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-bpractical.html
http://old-www.cs.dartmouth.edu/~dfk/RAPID-Transit.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-diskdir2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-diskdir-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-diskdir.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-lu-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-lu.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-int-ddio.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-expand-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-expand.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ap-enwrich-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-tuning.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ap-enwrich.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jdiskdir.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-bdiskdir.html
http://old-www.cs.dartmouth.edu/~dfk/STARFISH/
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-workload-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-workload.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ellis-chicken-egg.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ap-workload-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-workload-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jworkload.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/ap-workload.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-workload.html
http://old-www.cs.dartmouth.edu/~dfk/charisma/
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-strided.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-explore-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-strided2-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-strided2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-explore.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-strided2-book.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-jgalley-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-galley-perf.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-galley.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-flexibility2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-flexibility.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nieuwejaar-jgalley.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/khanna-group.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/carter-vesta.html
http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-armada.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-framework.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-emulab-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/oldfield-restruct.html
http://old-www.cs.dartmouth.edu/~dfk/armada/
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-market-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-market.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-demand-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-demand.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-position.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-lottery-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-lottery.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-game-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-risk.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-game.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-info.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-game-book.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bredin-jgame.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotay-agents.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/rus-autonomous.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nog-rpc-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-agents.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-mobile-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/rus-autonomous4.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/rus-autonomous3.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/rus-autonomous2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jmobile.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/hirschl-agdb.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-mobile.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-bookchap.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-security-book.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-future2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-future.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-bmobile.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/brewington-IR.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-model-tr2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-model-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-model.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-motivation-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/grimstrup-gmas-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-scalability-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-scalability.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-position.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jmodel.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-dwta-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-dwta.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/grimstrup-gmas.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-spe.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-motivation.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-axioms-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/liu-direx.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-axioms-tr2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-axioms.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-compare-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/gray-compare.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/liu-jdirex.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/jiang-msthesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kumar-fbcast.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/newport-axioms.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-combined-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-lbc-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-lbc.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-jmeshmon.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-combined-tr2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/nanda-llbc.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-crawdad-workshop05.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/yeo-crawdad-ccr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/yeo-crawdad-mc2r.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/yeo-crawdad-2007.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-citation-practices.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/yeo-poll-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-crf-s3.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-survey.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-crf-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-crf.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/fazio-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/fazio-netsani.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/fazio-sampling.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-campus-tr2.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-campus-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-campus.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-problems.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-voice-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-voice.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-traces.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-jcampus.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-esm.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-social-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/blinn-hotspot.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-measuring.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/henderson-jvoice.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-dartmouth-campus-20090909.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/baek-survey-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/deshpande-sampling.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/deshpande-coordinated.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sheng-spoofing.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sheng-map.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/deshpande-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/deshpande-refocusing.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bratus-streaming-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bratus-fingerprint-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bratus-fingerprint.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/bratus-dist-cset.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-saluki.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-models.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/arackaparambil-clock-skew-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/arackaparambil-clock-skew.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/tan-dist.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mills-tettey-mvoip.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-predict-tr-old.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-predict-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-predict-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-predict.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-reserv-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-reserv.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-jpredict.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-dtn.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/song-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-hotspots.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-classify-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-classify.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-wardriving.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-mobility.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kim-jclassify.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-snowflake.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-snowflake2-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-calculus-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-spki-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-spki.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-restricted.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/howell-end-to-end.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-toolkit-p.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-toolkit-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-toolkit.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-kerf-WIP.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/aslam-kerf-news.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-survey-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-solar-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-solar.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-pervasive-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-pervasive.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-abstraction-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-abstraction.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-naming.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/wang-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/wang-meeting-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/wang-meeting.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-pack-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-fusenet.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-dependency-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-dependency.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-pack.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-bnaming.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/li-wwasn07.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mingli-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/li-quality.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/li-jfilter.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-jsolar.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/li-ijcnds.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-aclprop-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-csa-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-jcsa.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-csa.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-scalability.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/minami-handbook.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kapadia-walls.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/johnson-metrosec-challenges-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/anthony-pervasive.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/shin-senseright-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kapadia-anonysense.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-anonysense.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/shin-deamon.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kapadia-metrosec-challenges.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/peebles-anonytl.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/shin-anonysense.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/shin-anonytiles.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sriram-ecg.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sriram-challenges.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-mhealth-spimacs.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/chen-mpcs.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-healthsec10.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-healthsec10.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-healthsec10.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sorber-pnt-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-healthsec11.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-hns-w.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-hns-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-healthsec11.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-mHealth-threats.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-same-body.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sorber-pnt.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/sorber-amulet.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/smithayer-bp.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-provenance-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-msthesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-fitbit.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-j-same-body.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-impedance.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-biometrics-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/avancha-survey.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-nethealth13.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kini-compliance-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/anthony-sith3.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-mobisys-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/prasad-bfitbit.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/peters-emg-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/murthy-thesis.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/murthy-bp.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/molina-markham-wmmadd.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mm-amulet-poster.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-zebra14.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-zebra-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/mare-hns-j.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/liang-healthtech14.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-wearable.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/cornelius-voice-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-frontiers.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/pierson-wanda-tr.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/pierson-wanda.html
http://old-www.cs.dartmouth.edu/~dfk/papers/abstracts/kotz-agenda.html
http://old-www.cs.dartmouth.edu/~dfk/papers/search.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index-c.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index-a.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index-t.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/ACM.html
http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/
http://old-www.cs.dartmouth.edu/~cs50/
http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
http://old-www.cs.dartmouth.edu/~cs50/
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
URL failed: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
http://old-www.cs.dartmouth.edu/~dfk/seatpack/
http://old-www.cs.dartmouth.edu/~dfk/kids.html
http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
http://old-www.cs.dartmouth.edu/~dfk/teaching.html
http://old-www.cs.dartmouth.edu/~dfk/people.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
http://old-www.cs.dartmouth.edu/
http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
http://old-www.cs.dartmouth.edu/~cs50/
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~cs50/

[flume:tse] 109) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page -1
maxDepth cannot be less than zero or greater than 10.

[flume:tse] 110) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 11
maxDepth cannot be less than zero or greater than 10.

[flume:tse] 111) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html pages 2
pageDirectory is either not writable or does not exist!

[flume:tse] 112) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html pages 
crawler.c works by passing 3 arguments: seedURL, pageDirectory, and maxDepth.

[flume:tse] 113) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.html pages 2 2
crawler.c works by passing 3 arguments: seedURL, pageDirectory, and maxDepth.

[flume:tse] 114) ./crawler http://old-www.cs.dartmouth.edu/~cs50/index.htmlhtml page 2
there was an error retrieving the webpage!

[flume:tse] 115) valgrind crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 2
==16293== Memcheck, a memory error detector
==16293== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==16293== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==16293== Command: crawler http://old-www.cs.dartmouth.edu/~cs50/index.html page 2
==16293== 
http://old-www.cs.dartmouth.edu/~cs50/index.html
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
URL failed: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
URL failed: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
URL failed: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
URL failed: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
http://old-www.cs.dartmouth.edu/~dfk/seatpack/
http://old-www.cs.dartmouth.edu/~dfk/kids.html
http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
http://old-www.cs.dartmouth.edu/~dfk/teaching.html
http://old-www.cs.dartmouth.edu/~dfk/people.html
http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
http://old-www.cs.dartmouth.edu/
http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
http://old-www.cs.dartmouth.edu/~cs50/
URL failed: http://old-www.cs.dartmouth.edu/~cs50/Schedule.pdf
http://old-www.cs.dartmouth.edu/~dfk/
http://old-www.cs.dartmouth.edu/~cs50/
==16293== 
==16293== HEAP SUMMARY:
==16293==     in use at exit: 64 bytes in 2 blocks
==16293==   total heap usage: 68,726 allocs, 68,724 frees, 6,023,708 bytes allocated
==16293== 
==16293== LEAK SUMMARY:
==16293==    definitely lost: 0 bytes in 0 blocks
==16293==    indirectly lost: 0 bytes in 0 blocks
==16293==      possibly lost: 0 bytes in 0 blocks
==16293==    still reachable: 64 bytes in 2 blocks
==16293==         suppressed: 0 bytes in 0 blocks
==16293== Rerun with --leak-check=full to see details of leaked memory
==16293== 
==16293== For counts of detected and suppressed errors, rerun with: -v
==16293== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

[flume:tse] 116) logout
Connection to flume.cs.dartmouth.edu closed.
ivybridge:~ georgehito$ 

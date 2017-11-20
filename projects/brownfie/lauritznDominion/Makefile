CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard assertTrue unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 randomtestcard1 randomtestcard2 randomadventurer

clean:
ifeq ($(OS),Windows_NT)
	del /s *.o *.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
else
	rm -f *.o *.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
endif

assertTrue: assertTrue.h assertTrue.c
	gcc -c assertTrue.c -g $(CFLAGS)

unittest1: unittest1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c rngs.o assertTrue.o -o unittest1  -lm -g

unittest2: unittest2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c rngs.o assertTrue.o -o unittest2  -lm -g

unittest3: unittest3.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c rngs.o assertTrue.o -o unittest3  -lm -g

unittest4: unittest4.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c rngs.o assertTrue.o -o unittest4  -lm -g

cardtest1: cardtest1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c rngs.o assertTrue.o -o cardtest1  -lm -g

cardtest2: cardtest2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c rngs.o assertTrue.o -o cardtest2  -lm -g

randomtestcard1: randomtestcard1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard1.c rngs.o assertTrue.o -o randomtestcard1  -lm -g

randomtestcard2: randomtestcard2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard2.c rngs.o assertTrue.o -o randomtestcard2  -lm -g

randomadventurer: randomadventurer.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomadventurer.c rngs.o assertTrue.o -o randomadventurer  -lm -g

randomtestcard1.out: randomtestcard1 
	./randomtestcard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2 
	./randomtestcard2 &> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomadventurer.out: randomadventurer 
	./randomadventurer &> randomadventurer.out
	gcov dominion.c >> randomadventurer.out
	cat dominion.c.gcov >> randomadventurer.out

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

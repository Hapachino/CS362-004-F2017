/***********************************
* Random Card Test 1: smithy
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define FILE "randomtestcard2.c"
#define TEST "smithy"
#define CARD smithy
#define TEST_NUM 10000
#define MAX_ACTIONS 100

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int newCards = 0;
	int discarded = 1;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room };

	// test variables
	int pass = 0,
		fail = 0;

	int error = 0;

	printf("%s: \n", FILE);
	printf("Testing: %s \n\n", TEST);

	// ----------- TEST --------------
	int i;

	for (i = 0; i < TEST_NUM; ++i) {
		// initialize gameState
		int seed = rand();
		int player = rand() % numPlayers;
		struct gameState G;
		initializeGame(numPlayers, k, seed, &G);

		// randomize gamateState variables
		G.deckCount[player] = rand() % MAX_DECK;
		G.discardCount[player] = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;
		G.numActions = rand() % MAX_ACTIONS;

		// initialize error count to 0 for test case
		error = 0;

		// add card to hand
		G.hand[0][0] = CARD;

		// record old values
		int oldActions = G.numActions,
			oldDeck = G.deckCount[player],
			oldDiscard = G.discardCount[player],
			oldCards = G.handCount[player];

		cardEffect(CARD, choice1, choice2, choice3, &G, handpos, &bonus);

		// check for errors
		error = isError(G.handCount[player] == oldCards + 2)
			+ isError(oldDeck + oldDiscard + oldCards == G.deckCount[player] + G.discardCount[player] + G.handCount[player]);

		// only print result if error found
		if (error) {
			printf("TEST CASE %d ERROR REPORT:\n", i + 1);

			// seed
			printf("Seed: %d\n", seed);

			if (isError(G.handCount[player] == oldCards + 2)) {
				printf("Hand: %d %d\n", oldCards, G.handCount[player]);
			}

			if (isError(oldDeck + oldDiscard + oldCards == G.deckCount[player] + G.discardCount[player] + G.handCount[player])) {
				printf("All Cards: %d %d\n", oldDeck + oldDiscard + oldCards, G.deckCount[player] + G.discardCount[player] + G.handCount[player]);

			}
			++fail;
		} else {
			++pass;
		}
		printf("\n");
	}

	// print out test suite results
	printf("\nTest Cases: %d  Pass: %d  Fail: %d  Fail Rate: %d%\n\n", TEST_NUM, pass, fail, fail / TEST_NUM * 100);

	return 0;
}
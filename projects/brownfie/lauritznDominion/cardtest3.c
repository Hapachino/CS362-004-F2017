/***********************************
* Card Test 1: steward
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TEST "steward"

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int seed = 99;

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, preG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room };

	initializeGame(numPlayers, k, seed, &G);

	printf("cardtest3.c: \n");
	printf("Testing: %s \n\n", TEST);

	// ----------- TEST 1: gameState is updated accordingly --------------
	printf("TEST 1: gameState is updated accordingly \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	G.hand[0][0] = steward;

	int oldCards = G.handCount[0],
		oldDiscard = G.discardCount[0];

	cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);

	// handCount (+2), decksize (-1), discard pile (+1)
	assertTrue(TEST, "returned correct handcount\n", G.handCount[0] == oldCards + 2);
	assertTrue(TEST, "correctly discared to own discard pile\n", G.discardCount[0] == oldDiscard + 1);


	// to pause screen
	getchar();

	return 0;
}
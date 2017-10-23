/***********************************
* Unit Test 1: numHandCards()
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TEST "numHandCards()"

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int seed = 99;
	struct gameState G, preG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("unittest1.c: \n");
	printf("Testing: %s \n\n", TEST);

	// ----------- TEST 1: handcount and gameState --------------
	printf("TEST 1: Test handcount and gameState are correct \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	// assert handcount is correct
	assertTrue(TEST, "returned correct handcount\n", numHandCards(&G) == preG.handCount[preG.whoseTurn]);

	// assert gameState is correct
	assertTrue(TEST, "returned correct gameState\n", !memcmp(&preG, &G, sizeof(struct gameState)));

	// assert handcount is correct after manually adjusting
	int preHandcount = G.handCount[G.whoseTurn]++;
	assertTrue(TEST, "returned correct handcount after manually adjusting\n", numHandCards(&G) == preHandcount + 1);

	printf("\n");

	return 0;
}
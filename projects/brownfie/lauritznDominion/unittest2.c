/***********************************
* Unit Test 2: supplyCount()
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TEST "supplyCount()"

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int seed = 99;
	struct gameState G, preG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("unittest2.c: \n");
	printf("Testing: %s \n\n", TEST);


	// ----------- TEST 1: supplyCount and gameState --------------
	printf("TEST 1: Test supplyCount and gameState are correct \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	// assert supplyCount is correct
	assertTrue(TEST, "returned correct supplyCount\n", supplyCount(adventurer, &G) == preG.supplyCount[adventurer]);

	// assert gameState is correct
	assertTrue(TEST, "returned correct gameState\n", !memcmp(&preG, &G, sizeof(struct gameState)));

	// assert supplyCount is correct after manual adjustment
	int preSupplyCount = G.supplyCount[adventurer]--;
	assertTrue(TEST, "returned correct supplyCount after manually adjusting\n", supplyCount(adventurer, &G) == preSupplyCount - 1);


	printf("\n");


	return 0;
}
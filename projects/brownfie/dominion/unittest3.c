/***********************************
* Unit Test 3: updateCoins()
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TEST "updateCoins()"

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int seed = 99;
	struct gameState G, preG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("unittest3.c: \n");
	printf("Testing: %s \n\n", TEST);


	// ----------- TEST 1: Compare coins and gameState before/after updateCoins() --------------
	printf("\nTEST 1: Compare coins and gameState before/after updateCoins() \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	int i, j, newCoins;

	for (i = 0; i < numPlayers; ++i) {
		// assert updated coins is correct

		G.whoseTurn = preG.whoseTurn = i;

		updateCoins(i, &G, i);
		newCoins = G.coins;

		printf("Using updateCoins on Player %d \n", i);

		assertTrue(TEST, "returned correct coins \n", newCoins == preG.coins + i);
		preG.coins = preG.coins + i;
		assertTrue(TEST, "returned correct gamestate \n", !memcmp(&preG, &G, sizeof(struct gameState)));
	}

	// ----------- TEST 2: Compare coins before/after updateCoins() with inputs --------------
	printf("\nTEST 2: Compare coins and gameState before/after updateCoins() with inputs \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	int newHand[5] = { gold, silver, copper, adventurer, smithy };

	for (i = 0; i < numPlayers; ++i) {
		// assert updated coins is correct

		G.whoseTurn = preG.whoseTurn = i;

		G.handCount[i] = 5;
		for (j = 0; j < G.handCount[i]; ++j) {
			G.hand[i][j] = newHand[j];
		}

		updateCoins(i, &G, i);
		newCoins = G.coins;

		assertTrue(TEST, "returned correct coins \n", newCoins == 6 + i);
	}
	

	printf("\n");


	return 0;
}
/***********************************
* Unit Test 4: isGameOver()
***********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assertTrue.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TEST "isGameOver()"

int main() {
	// setup gameState parameters
	int numPlayers = 2;
	int seed = 99;
	struct gameState G, preG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("unittest4.c: \n");
	printf("Testing: %s \n\n", TEST);


	// ----------- TEST 1: Game is over when no provinces and maintains gamestate--------------
	printf("\nTEST 1: Game is over when no provinces \n\n");

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	G.supplyCount[province] = 0;

	assertTrue(TEST, "returns game over when no provinces \n", isGameOver(&G));

	preG.supplyCount[province] = 0;
	assertTrue(TEST, "returned correct gamestate \n", !memcmp(&preG, &G, sizeof(struct gameState)));


	// ----------- TEST 2: Game is not over when less than 3 supply piles run out and maintains gamestate--------------
	printf("\nTEST 2: Game is not over when less than 3 supply piles run out \n\n");

	initializeGame(numPlayers, k, seed, &G);

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	G.supplyCount[adventurer] = 0;
	G.supplyCount[smithy] = 0;

	assertTrue(TEST, "returns game over when no provinces \n", !isGameOver(&G));

	preG.supplyCount[adventurer] = 0;
	preG.supplyCount[smithy] = 0;
	assertTrue(TEST, "returned correct gamestate \n", !memcmp(&preG, &G, sizeof(struct gameState)));

	// ----------- TEST 3: Game is over when 3 supply piles run out and maintains gamestate--------------
	printf("\nTEST 3: Game is over when 3 supply piles run out \n\n");

	initializeGame(numPlayers, k, seed, &G);

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	G.supplyCount[adventurer] = 0;
	G.supplyCount[smithy] = 0;
	G.supplyCount[village] = 0;

	assertTrue(TEST, "returns game over when no provinces \n", isGameOver(&G));

	preG.supplyCount[adventurer] = 0;
	preG.supplyCount[smithy] = 0;
	preG.supplyCount[village] = 0;

	assertTrue(TEST, "returned correct gamestate \n", !memcmp(&preG, &G, sizeof(struct gameState)));


	// ----------- TEST 4: Game is over when over 3 supply piles run out and maintains gamestate--------------
	printf("\nTEST 3: Game is over when over 3 supply piles run out \n\n");

	initializeGame(numPlayers, k, seed, &G);

	// copy the game state to a test case
	memcpy(&preG, &G, sizeof(struct gameState));

	G.supplyCount[adventurer] = 0;
	G.supplyCount[smithy] = 0;
	G.supplyCount[village] = 0;
	G.supplyCount[steward] = 0;

	assertTrue(TEST, "returns game over when no provinces \n", isGameOver(&G));

	preG.supplyCount[adventurer] = 0;
	preG.supplyCount[smithy] = 0;
	preG.supplyCount[village] = 0;
	preG.supplyCount[steward] = 0;

	assertTrue(TEST, "returned correct gamestate \n", !memcmp(&preG, &G, sizeof(struct gameState)));

	printf("\n");


	return 0;
}
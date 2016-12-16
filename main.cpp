/*
	By Matheus Wisniewski
	December 2016
*/

#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "BlackJackGame.h"

using namespace testing;
using namespace std;

#define NUMBER_OF_DECKS 5
#define PERCENTAGE_LIMIT_OF_DECK_SIZE_FOR_RESHUFFLE 50

int main(int argc, char* argv[]) {

	InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	system("cls");

	BlackJackGame *game = new BlackJackGame(NUMBER_OF_DECKS, PERCENTAGE_LIMIT_OF_DECK_SIZE_FOR_RESHUFFLE);

	game->play();

	delete game;

	return 0;
}
/*
	By Matheus Wisniewski
	December 2016
*/

#include "BlackJackController_CLI.h"

#include "BlackJackGame.h"

BlackJackController_CLI::BlackJackController_CLI(BlackJackGame *theGame) :
	BlackJackController(theGame)
{
}


BlackJackController_CLI::~BlackJackController_CLI()
{
}

void BlackJackController_CLI::getUserInputForDecision()
{
	int intDecision = 0;

	cin >> intDecision;

	game->setPlayerDecision(static_cast<EPlayerOptions>(intDecision));
}

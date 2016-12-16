/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include "EPlayerOptions.h"

class BlackJackGame;

class BlackJackController
{
public:
	BlackJackController(BlackJackGame *theGame);
	~BlackJackController();

	virtual void getUserInputForDecision() = 0;

protected:
	BlackJackGame *game;
};


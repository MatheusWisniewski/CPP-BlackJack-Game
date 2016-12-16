/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <string>

#include "BlackJackHelper.h"

class BlackJackGame;

using namespace std;

class BlackJackUI
{
public:
	BlackJackUI(BlackJackGame *theGame);
	~BlackJackUI();

	virtual void clearScreen() = 0;

	virtual void showDealersVisibleCard() = 0;
	virtual void showDealersFinalHand() = 0;
	virtual void showPlayersHand() = 0;

	virtual void displayText(string text) = 0;
	virtual void displayCurrentResults() = 0;
	virtual void displayPlayerOptions() = 0;
	virtual void displayBustStatistics() = 0;
	virtual void displayDeckInfo() = 0;

protected:
	BlackJackGame* game;
};


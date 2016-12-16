/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <iostream>
#include "BlackJackUI.h"


using namespace std;

class BlackJackUI_CLI : public BlackJackUI
{
public:
	BlackJackUI_CLI(BlackJackGame* theGame);
	~BlackJackUI_CLI();

	virtual void clearScreen();

	virtual void showDealersVisibleCard();
	virtual void showDealersFinalHand();
	virtual void showPlayersHand();

	virtual void displayText(string text);
	virtual void displayCurrentResults();
	virtual void displayPlayerOptions();
	virtual void displayBustStatistics();
	virtual void displayDeckInfo();
};


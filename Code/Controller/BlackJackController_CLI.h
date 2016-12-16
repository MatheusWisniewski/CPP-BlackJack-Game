/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <iostream>
#include "BlackJackController.h"

using namespace std;

class BlackJackController_CLI : public BlackJackController
{
public:
	BlackJackController_CLI(BlackJackGame *theGame);
	~BlackJackController_CLI();

	virtual void getUserInputForDecision();
};


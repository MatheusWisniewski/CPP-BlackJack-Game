/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <gtest\gtest.h>
#include <gmock\gmock.h>

#include "BlackJackHelper.h"
#include "BlackJackGame.h"
#include "Card.h"

using namespace testing;
using namespace std;

class TestFixture : public Test {

public:

	BlackJackGame *game;

	void SetUp() override {
		game = new BlackJackGame(1);
	}

	void TearDown() override {
		delete game;
	}
};

class TestFixtureWithAccessToPrivateMembers1 : public Test {

public:

	BlackJackGame *game;

	void SetUp() override {
		game = new BlackJackGame(1);
		game->clearDecks();
		game->createUnshuffledDeck();
	}

	void TearDown() override {
		delete game;
	}
};

class TestFixtureWithAccessToPrivateMembers2 : public Test {

public:

	BlackJackGame *game;
	int equalCount = 0;

	void SetUp() override {
		game = new BlackJackGame(1);
		game->clearDecks();
		game->createUnshuffledDeck();

		CardDeck unshuffledDeck;

		unshuffledDeck = game->getDeck();

		game->shuffleDecks();

		for (int i = 0; i < unshuffledDeck.size(); i++)
		{
			if (unshuffledDeck[i].value == game->getDeck()[i].value && unshuffledDeck[i].suit == game->getDeck()[i].suit)
				equalCount++;
		}
	}

	void TearDown() override {
		delete game;
	}
};

class TestFixtureWithAccessToPrivateMembers3 : public Test {

public:

	BlackJackGame *game;

	void SetUp() override {
		game = new BlackJackGame(1);
		game->clearDecks();
		game->createUnshuffledDeck();
		game->shuffleDecks();
		game->startRound();
	}

	void TearDown() override {
		delete game;
	}
};
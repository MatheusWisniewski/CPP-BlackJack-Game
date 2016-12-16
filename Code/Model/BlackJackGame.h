/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <iostream>		// std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <vector>		// std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "Card.h"
#include "BlackJackHelper.h"
#include "EPlayerOptions.h"

#include "BlackJackUI_CLI.h"
#include "BlackJackController_CLI.h"

//#include "BlackJackTests.h"

using namespace std;

class BlackJackGame
{
public:

	friend class TestFixtureWithAccessToPrivateMembers1;
	friend class TestFixtureWithAccessToPrivateMembers2;
	friend class TestFixtureWithAccessToPrivateMembers3;

	BlackJackGame(int aNumberOfDecks = 5, int aLimitPercentageForReshuffle = 50);
	~BlackJackGame();

	void play();

	int getWins() const { return wins; }
	int getLosses() const { return losses; }
	int getPushes() const { return pushes; }
	int getTotalRounds() const { return totalRounds; }

	int getNumberOfDecks() const { return numberOfDecks; }
	int getPercentageLimitForReshuffle() const { return percentageLimitOfDeckSizeForReshuffle; }

	void setPlayerDecision(EPlayerOptions decision) { playerDecision = decision; }
	EPlayerOptions getDecision() const { return playerDecision; }

	CardDeck getDeck() const { return deck; }
	CardHand getDealersHand() const { return dealersHand; }
	Card getDealersVisibleCard() const { return dealersHand[0]; }
	CardHand getPlayersHand() const { return playersHand; }

private:

	BlackJackUI *gameUI;
	BlackJackController *gameController;

	CardDeck deck;
	CardHand dealersHand;
	CardHand playersHand;

	int numberOfDecks;
	int percentageLimitOfDeckSizeForReshuffle;
	int wins;
	int losses;
	int pushes;
	int totalRounds;
	bool roundEnded;
	EPlayerOptions playerDecision;

	void addWin() { wins++; totalRounds++; }
	void addLoss() { losses++; totalRounds++; }
	void addTie() { pushes++; totalRounds++; }

	void startRound();
	void endRound() { roundEnded = true; }
	bool roundHasEnded() const { return roundEnded; }

	void clearDecks();
	void createUnshuffledDeck();
	void addNewDecks();
	void shuffleDecks();

	void hit(CardHand &hand);

	array<char*, 13> values = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	array<char, 4> suits = { 'D', 'S', 'H', 'C' };
};


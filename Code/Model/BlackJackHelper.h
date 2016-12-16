/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <string>
#include <vector>
#include <map>

#include "Card.h"

using namespace std;

class BlackJackHelper
{
public:

	static int cards2points(string cardsString);
	static int cards2points(CardHand hand);

	static bool bust(string cardsString);
	static bool bust(CardHand hand);

	static bool dealerHasToCall(string cardsString);
	static bool dealerHasToCall(CardHand hand);

	static bool canSplit(string cardsString);
	static bool canSplit(CardHand hand);

	static int countNumberOfCards(string cardsString);
	static int countNumberOfCards(CardHand hand);

	static int countNumberOfAces(string cardsString);
	static int countNumberOfAces(CardHand hand);

	static string cardHand2string(CardHand hand);

	static float chanceOfBustForPlayer(CardHand hand, CardDeck deck);
	static bool dealerWillStatisticallyBustOrLoseToPlayersHand(CardHand playersHand, Card dealersVisibleCard, CardDeck deck);
	static float averageCardPointsFromDeck(CardDeck deck);

	static bool playerWins(CardHand playersHand, CardHand dealersHand);
	static bool playerLoses(CardHand playersHand, CardHand dealersHand);
	static bool playerHasBlackJack(CardHand playersHand);
};


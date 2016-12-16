/*
	By Matheus Wisniewski
	December 2016
*/

#include "BlackJackHelper.h"

int BlackJackHelper::cards2points(string cardsString)
{
	int points = 0;
	int numberOfAces = countNumberOfAces(cardsString);

	for (int i = 0; i < cardsString.length(); i++)
	{
		if (isdigit(cardsString[i])) 
		{
			if (cardsString[i] == '1' && i <= cardsString.length() - 1 && cardsString[i + 1] == '0')
				points += 10;
			else
				points += cardsString[i] - '0';
		}
		else if (cardsString[i] == 'A')
		{
		}
		else
		{
			points += 10;
		}
	}

	for (int i = 0; i < numberOfAces; i++)
	{
		if (points <= 11 - numberOfAces)
			points += 11;
		else
			points += 1;
	}

	return points;
}

int BlackJackHelper::cards2points(CardHand hand)
{
	return cards2points(cardHand2string(hand));
}

bool BlackJackHelper::bust(string cardsString)
{
	if (cards2points(cardsString) <= 21)
		return false;
	else
		return true;
}

bool BlackJackHelper::bust(CardHand hand)
{
	return bust(cardHand2string(hand));
}

bool BlackJackHelper::dealerHasToCall(string cardsString)
{
	if (cards2points(cardsString) <= 16)
		return true;
	else
		return false;
}

bool BlackJackHelper::dealerHasToCall(CardHand hand)
{
	return dealerHasToCall(cardHand2string(hand));
}

int BlackJackHelper::countNumberOfCards(string cardsString)
{
	int count = 0;

	for (int i = 0; i < cardsString.length(); i++)
	{
		if (cardsString[i] == '1' && i <= cardsString.length() - 1 && cardsString[i + 1] == '0')
			i++;
			
		count++;
	}

	return count;
}

int BlackJackHelper::countNumberOfCards(CardHand hand)
{
	return countNumberOfCards(cardHand2string(hand));
}

int BlackJackHelper::countNumberOfAces(string cardsString)
{
	int count = 0;

	for (int i = 0; i < cardsString.length(); i++)
	{
		if (cardsString[i] == 'A')
			count++;
	}

	return count;
}

int BlackJackHelper::countNumberOfAces(CardHand hand)
{
	return countNumberOfAces(cardHand2string(hand));
}

bool BlackJackHelper::canSplit(string cardsString)
{
	if (countNumberOfCards(cardsString) == 2)
	{
		if (cardsString.length() == 4)
			return true;
		
		if (cardsString.length() == 2 && (cardsString[0] == cardsString[1]))
			return true;
	}

	return false;
}

bool BlackJackHelper::canSplit(CardHand hand)
{
	return canSplit(cardHand2string(hand));
}

string BlackJackHelper::cardHand2string(CardHand hand)
{
	string CardString = "";

	for (Card& Card : hand) 
		CardString += Card.value;

	return CardString;
}

float BlackJackHelper::chanceOfBustForPlayer(CardHand hand, CardDeck deck)
{
	int pointsInHand = cards2points(hand);

	if (countNumberOfAces(hand) > 0)
	{
		string nonAcecardsString = "";

		for (Card& Card : hand)
			if (Card.value[0] != 'A')
				nonAcecardsString += Card.value;

		if (cards2points(nonAcecardsString) < 11)
			pointsInHand -= 10;
	}
		
	int numberOfCardsThatWillBust = 0;

	for (Card& Card : deck)
	{
		if (Card.value[0] != 'A' && pointsInHand + cards2points(Card.value) > 21)
			numberOfCardsThatWillBust++;
	}

	return (float)numberOfCardsThatWillBust /deck.size();
}

bool BlackJackHelper::dealerWillStatisticallyBustOrLoseToPlayersHand(CardHand playersHand, Card dealersVisibleCard, CardDeck deck)
{
	float expectedDealerFinalPoints = cards2points(dealersVisibleCard.value) + averageCardPointsFromDeck(deck);

	if (expectedDealerFinalPoints <= 16)
		expectedDealerFinalPoints += averageCardPointsFromDeck(deck);

	if (expectedDealerFinalPoints > 21)
		return true;

	if (cards2points(dealersVisibleCard.value) + 2 * averageCardPointsFromDeck(deck) >= 17 && cards2points(playersHand))
		return true;

	return false;
}

float BlackJackHelper::averageCardPointsFromDeck(CardDeck deck) {

	int sum = 0;

	for (Card& Card : deck)
	{
		if (Card.value[0] == 'A')
			sum += 1;
		else
			sum += cards2points(Card.value);
	}

	return (float)sum / deck.size();
}

bool BlackJackHelper::playerWins(CardHand playersHand, CardHand dealersHand)
{
	if (bust(dealersHand) || (!bust(playersHand) && cards2points(dealersHand) < cards2points(playersHand)))
		return true;

	return false;
}

bool BlackJackHelper::playerLoses(CardHand playersHand, CardHand dealersHand)
{
	if (bust(playersHand) || cards2points(dealersHand) > cards2points(playersHand))
		return true;

	return false;
}

bool BlackJackHelper::playerHasBlackJack(CardHand playersHand)
{
	if (BlackJackHelper::cards2points(playersHand) == 21 && BlackJackHelper::countNumberOfCards(playersHand) == 2)
		return true;

	return false;
}



/*
	By Matheus Wisniewski
	December 2016
*/

#pragma once

#include <vector>
#include <array>

struct Card {
	char* value;
	char suit;
};

typedef std::vector<Card> CardDeck;
typedef std::vector<Card> CardHand;

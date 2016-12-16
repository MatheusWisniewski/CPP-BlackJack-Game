/*
	By Matheus Wisniewski
	December 2016
*/

#include "BlackJackTests.h"

TEST_F(TestFixture, SimplePointTests) {

	ASSERT_THAT(BlackJackHelper::cards2points("A"), Eq(11));
	ASSERT_THAT(BlackJackHelper::cards2points("2"), Eq(2));
	ASSERT_THAT(BlackJackHelper::cards2points("10"), Eq(10));
	ASSERT_THAT(BlackJackHelper::cards2points("J"), Eq(10));
	ASSERT_THAT(BlackJackHelper::cards2points("Q"), Eq(10));
	ASSERT_THAT(BlackJackHelper::cards2points("K"), Eq(10));

	ASSERT_THAT(BlackJackHelper::cards2points("A2"), Eq(13));
	ASSERT_THAT(BlackJackHelper::cards2points("AA"), Eq(12));
	ASSERT_THAT(BlackJackHelper::cards2points("AJ"), Eq(21));
	ASSERT_THAT(BlackJackHelper::cards2points("KK"), Eq(20));
	ASSERT_THAT(BlackJackHelper::cards2points("JQ"), Eq(20));
	ASSERT_THAT(BlackJackHelper::cards2points("A10"), Eq(21));
	ASSERT_THAT(BlackJackHelper::cards2points("10A"), Eq(21));

	ASSERT_THAT(BlackJackHelper::cards2points("567"), Eq(18));
	ASSERT_THAT(BlackJackHelper::cards2points("AA2"), Eq(14));
	ASSERT_THAT(BlackJackHelper::cards2points("2AA"), Eq(14));
	ASSERT_THAT(BlackJackHelper::cards2points("A2A"), Eq(14));
	ASSERT_THAT(BlackJackHelper::cards2points("A1010"), Eq(21));
	ASSERT_THAT(BlackJackHelper::cards2points("1010A"), Eq(21));
	ASSERT_THAT(BlackJackHelper::cards2points("10A10"), Eq(21));
	ASSERT_THAT(BlackJackHelper::cards2points("AJA"), Eq(12));
	ASSERT_THAT(BlackJackHelper::cards2points("JAQ"), Eq(21));

	ASSERT_THAT(BlackJackHelper::cards2points("JJ2"), Eq(22));
	ASSERT_THAT(BlackJackHelper::cards2points("A2QK"), Eq(23));
	ASSERT_THAT(BlackJackHelper::cards2points("10JQ"), Eq(30));

	ASSERT_THAT(BlackJackHelper::cards2points("AAAAAAAAAAA"), Eq(21));
}

TEST_F(TestFixture, BustOrNot) {

	ASSERT_THAT(BlackJackHelper::bust("106"), Eq(false));
	ASSERT_THAT(BlackJackHelper::bust("JJA"), Eq(false));

	ASSERT_THAT(BlackJackHelper::bust("JJ2"), Eq(true));
	ASSERT_THAT(BlackJackHelper::bust("8910"), Eq(true));
}

TEST_F(TestFixture, DealerCallOrNot) {

	ASSERT_THAT(BlackJackHelper::dealerHasToCall("106"), Eq(true));
	ASSERT_THAT(BlackJackHelper::dealerHasToCall("88"), Eq(true));
	ASSERT_THAT(BlackJackHelper::dealerHasToCall("98"), Eq(false));
	ASSERT_THAT(BlackJackHelper::dealerHasToCall("JJ"), Eq(false));
}

TEST_F(TestFixture, NumberOfCards) {

	ASSERT_THAT(BlackJackHelper::countNumberOfCards("AA"), Eq(2));
	ASSERT_THAT(BlackJackHelper::countNumberOfCards("1010"), Eq(2));

	ASSERT_THAT(BlackJackHelper::countNumberOfCards("JJ2"), Eq(3));
	ASSERT_THAT(BlackJackHelper::countNumberOfCards("A2QK"), Eq(4));
	ASSERT_THAT(BlackJackHelper::countNumberOfCards("10JQ"), Eq(3));
}

TEST_F(TestFixture, CanSplit) {

	ASSERT_THAT(BlackJackHelper::canSplit("AA"), Eq(true));
	ASSERT_THAT(BlackJackHelper::canSplit("22"), Eq(true));
	ASSERT_THAT(BlackJackHelper::canSplit("1010"), Eq(true));
	ASSERT_THAT(BlackJackHelper::canSplit("JJ"), Eq(true));

	ASSERT_THAT(BlackJackHelper::canSplit("JQ"), Eq(false));
	ASSERT_THAT(BlackJackHelper::canSplit("12"), Eq(false));
	ASSERT_THAT(BlackJackHelper::canSplit("109"), Eq(false));
	ASSERT_THAT(BlackJackHelper::canSplit("AK"), Eq(false));
}

TEST_F(TestFixtureWithAccessToPrivateMembers1, GenerateUnshuffledDeck) {

	ASSERT_THAT(game->getDeck()[0].value, Eq("A"));
	ASSERT_THAT(game->getDeck()[0].suit, Eq('D'));

	ASSERT_THAT(game->getDeck()[51].value, Eq("K"));
	ASSERT_THAT(game->getDeck()[51].suit, Eq('C'));
}

TEST_F(TestFixtureWithAccessToPrivateMembers2, TestShuffle) {

	ASSERT_THAT(equalCount, Lt(52));
}

TEST_F(TestFixture, CardHand2StringTest) {

	CardHand hand;

	Card Card;

	Card.value = "A";
	Card.suit = 'D';

	hand.push_back(Card);

	Card.value = "10";
	Card.suit = 'S';

	hand.push_back(Card);

	ASSERT_THAT(BlackJackHelper::cardHand2string(hand), Eq(string("A10")));
}

TEST_F(TestFixtureWithAccessToPrivateMembers3, StartTest) {

	ASSERT_THAT(BlackJackHelper::countNumberOfCards(game->getDealersHand()), Eq(2));
	ASSERT_THAT(BlackJackHelper::countNumberOfCards(game->getPlayersHand()), Eq(2));
}

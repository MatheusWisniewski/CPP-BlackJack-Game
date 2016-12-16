/*
	By Matheus Wisniewski
	December 2016
*/

#include "BlackJackUI_CLI.h"

#include "BlackJackGame.h"

BlackJackUI_CLI::BlackJackUI_CLI(BlackJackGame *theGame) :
	BlackJackUI(theGame)
{
}


BlackJackUI_CLI::~BlackJackUI_CLI()
{
}

void BlackJackUI_CLI::clearScreen()
{
	system("cls");
}

void BlackJackUI_CLI::showDealersVisibleCard()
{
	cout << endl << '\t' << "Dealer's hand" << endl << endl;
	cout << '\t' << game->getDealersVisibleCard().value << ' ' << game->getDealersVisibleCard().suit << endl << endl;
}

void BlackJackUI_CLI::showDealersFinalHand()
{
	cout << endl << '\t' << "Dealer's hand : points = " << BlackJackHelper::cards2points(game->getDealersHand()) << endl << endl;
	for (Card& card : game->getDealersHand())
		cout << '\t' << card.value << ' ' << card.suit << endl << endl;
}

void BlackJackUI_CLI::showPlayersHand()
{
	cout << endl << '\t' << "Player's hand : points = " << BlackJackHelper::cards2points(game->getPlayersHand()) << endl << endl;
	for (Card& card : game->getPlayersHand())
		cout << '\t' << card.value << ' ' << card.suit << endl << endl;
}

void BlackJackUI_CLI::displayText(string text)
{
	cout << endl << '\t' << text << endl << endl;
	system("pause");
}

void BlackJackUI_CLI::displayCurrentResults()
{
	cout << endl;
	cout << endl << '\t' << "W = " << game->getWins() << " (" << game->getWins()*100.0 / game->getTotalRounds() << "%)" << endl;
	cout << endl << '\t' << "L = " << game->getLosses() << " (" << game->getLosses()*100.0 / game->getTotalRounds() << "%)" << endl;
	cout << endl << '\t' << "P = " << game->getPushes() << " (" << game->getPushes()*100.0 / game->getTotalRounds() << "%)" << endl;
	cout << endl;
	system("pause");
}

void BlackJackUI_CLI::displayPlayerOptions()
{
	cout << endl << '\t' << "Hit (1) / Pass (2)" << endl << endl;
}

void BlackJackUI_CLI::displayBustStatistics()
{
	cout << endl << '\t' << "[chance of bust = " << round(BlackJackHelper::chanceOfBustForPlayer(game->getPlayersHand(), game->getDeck())*100.0) << "%, average Card on deck = " << BlackJackHelper::averageCardPointsFromDeck(game->getDeck()) << "]" << endl;
}

void BlackJackUI_CLI::displayDeckInfo()
{
	cout << endl << '\t' << "[deck = " << game->getDeck().size() << " Cards, reshuffle in " << game->getDeck().size() - ((float)game->getPercentageLimitForReshuffle() / 100.0) * 52 * game->getNumberOfDecks() << "]" << endl << endl;
}

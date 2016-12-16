/*  
	By Matheus Wisniewski
	December 2016
*/

#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int aNumberOfDecks, int aLimitPercentageForReshuffle) :
	numberOfDecks(aNumberOfDecks),
	percentageLimitOfDeckSizeForReshuffle(aLimitPercentageForReshuffle),
	wins(0),
	losses(0),
	pushes(0),
	totalRounds(0),
	roundEnded(false)
{
	gameUI = new BlackJackUI_CLI(this);
	gameController = new BlackJackController_CLI(this);
}


BlackJackGame::~BlackJackGame()
{
	delete gameController;
	delete gameUI;
}

void BlackJackGame::createUnshuffledDeck()
{
	Card aCard;

	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < suits.size(); j++)
		{
			aCard.value = values[i];
			aCard.suit = suits[j];
			deck.push_back(aCard);
		}
	}
}

void BlackJackGame::addNewDecks()
{
	for (int i = 0; i < this->numberOfDecks; i++)
		createUnshuffledDeck();
}

void BlackJackGame::clearDecks()
{
	deck.clear();
}

void BlackJackGame::shuffleDecks()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

void BlackJackGame::startRound()
{
	roundEnded = false;
	playerDecision = EPlayerOptions::None;

	dealersHand.clear();
	playersHand.clear();

	hit(dealersHand);
	hit(dealersHand);

	hit(playersHand);
	hit(playersHand);
}

void BlackJackGame::hit(CardHand &hand)
{
	if (deck.size() == 0 || ((float)deck.size() / (numberOfDecks * 52)) * 100 < percentageLimitOfDeckSizeForReshuffle)
	{
		clearDecks();
		addNewDecks();
		shuffleDecks();
	}

	hand.push_back(deck[deck.size() - 1]);

	deck.pop_back();
}

void BlackJackGame::play()
{
	addNewDecks();
	shuffleDecks();
	startRound();

	while (1)
	{
		gameUI->clearScreen();

		if (roundHasEnded())
			gameUI->showDealersFinalHand();
		else
			gameUI->showDealersVisibleCard();

		gameUI->showPlayersHand();

		if (roundHasEnded())
		{
			if (BlackJackHelper::playerWins(playersHand, dealersHand))
			{
				gameUI->displayText("You win!!!");
				addWin();
			}
			else if (BlackJackHelper::playerLoses(playersHand, dealersHand))
			{
				gameUI->displayText("You lose.");
				addLoss();
			}
			else
			{
				gameUI->displayText("Push.");
				addTie();
			}

			gameUI->displayCurrentResults();
			startRound();
		}
		else
		{
			if (BlackJackHelper::playerHasBlackJack(playersHand))
			{
				gameUI->displayText("BLACKJACK!!!");
				endRound();
			}
			else if (BlackJackHelper::bust(playersHand))
			{
				gameUI->displayText("You busted.");
				endRound();
			}
			else
			{
				if (BlackJackHelper::cards2points(playersHand) == 21)
					setPlayerDecision(EPlayerOptions::Stand);
				else
				{
					//gameUI->displayBustStatistics();
					//gameUI->displayDeckInfo();
					gameUI->displayPlayerOptions();

					gameController->getUserInputForDecision();
				}

				switch (getDecision())
				{
				case EPlayerOptions::Hit:
					hit(playersHand);

					break;

				case EPlayerOptions::Stand:
					endRound();

					while (BlackJackHelper::dealerHasToCall(dealersHand))
						hit(dealersHand);

					break;

				default:
					break;
				}
			}
		}
	}
}

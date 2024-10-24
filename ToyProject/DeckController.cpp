#include "stdafx.h"
#include "DeckController.h"

void DeckController::Init()
{
	for (int i = 0; i < 5; i++) {
		deckTemplate.push_back(Cards::Bash);
		deckTemplate.push_back(Cards::Defend);
		deckTemplate.push_back(Cards::Inflame);
		deckTemplate.push_back(Cards::Strike);
	}
	deck.clear();
	deck = std::deque<Cards>(deckTemplate.begin(), deckTemplate.end());
	std::random_device rd;
	std::mt19937 g(rd()); 

	std::shuffle(deck.begin(), deck.end(), g);

}

void DeckController::reset()
{
	deck.clear();
	deck = std::deque<Cards>(deckTemplate.begin(), deckTemplate.end());
	std::random_shuffle(deck.begin(), deck.end());
	graveSize = 0;
}

void DeckController::useCard(int amout)
{
	graveSize += amout;
}

int DeckController::getDeckSize()
{
	return deck.size();
}

int DeckController::getGraveSize()
{
	return graveSize;
}

Cards DeckController::drawCard()
{
	if (deck.empty()) {
		reset();
	}
	Cards drawCard = deck.front();
	deck.pop_front();
	return drawCard;
}


std::deque<Cards> DeckController::drawCards()
{
	std::deque<Cards> hand;
	for (int i = 0; i < 5; i++) {
		Cards drawCard = deck.front();
		hand.push_back(drawCard);
		deck.pop_front();
	}
	return hand;
}


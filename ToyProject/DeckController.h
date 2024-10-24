#pragma once

class DeckController : public Singleton<DeckController>
{
	friend class Singleton<DeckController>;
private:
	std::deque<Cards> deck;
	std::deque<Cards> deckTemplate;

	DeckController() = default;
	~DeckController() = default;

	DeckController(const DeckController&) = delete;
	DeckController& operator=(const DeckController&) = delete;

	int graveSize;
public:
	void Init();
	void reset();
	void useCard(int amout);
	int getDeckSize();
	int getGraveSize();
	Cards drawCard();
	std::deque<Cards> drawCards();
};

#define DECK_CTRL (DeckController::Instance())
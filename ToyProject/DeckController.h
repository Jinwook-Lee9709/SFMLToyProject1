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

public:
	void Init();
	void reset();
	int getDeckSize();
	Cards drawCard();
	std::deque<Cards> drawCards();
};

#define DECK_CTRL (DeckController::Instance())
#include "Scene.h"
#pragma once
class Player;
class Enemy;
class Card;

class SceneBattle : public Scene
{
protected:
	Turn turn;
	int selectedCard;
	sf::RenderWindow* window;
	float cardVelocity = 100.f;
	float elapsedTime = 0;
public:
	SceneBattle();
	~SceneBattle();

	virtual void Init(sf::RenderWindow& window) override;
	virtual void Enter() override;
	virtual void Exit() override;

	
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void PlayerAction(Player& player, Enemy& enemy, Card& card);

};


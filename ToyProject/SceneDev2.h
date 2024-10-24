#pragma once
#include "Scene.h"
class SceneDev2 : public Scene
{
protected:
	sf::RenderWindow* window;
	sf::Texture texcool;
	sf::Sprite spritecool;
	sf::Text messageText;
	sf::Texture texplaybutton;
	sf::Sprite spriteplaybutton;
	sf::Texture texout;
	sf::Sprite spriteout;

public:
	SceneDev2();
	~SceneDev2() = default;

	virtual void Init(sf::RenderWindow& window) override;
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	
}
;


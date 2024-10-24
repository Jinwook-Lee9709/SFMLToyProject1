#pragma once
#include "Scene.h"
class SceneDev1 : public Scene
{
protected:
	sf::Texture texcancel;
	sf::Texture texDeck;
	sf::Texture texGrave;
	sf::Texture texplayback;
	

	sf::Sprite spritecancel;
	sf::Sprite spriteDeck;
	sf::Sprite spriteGrave;
	sf::Sprite spriteplayback;

public:
	SceneDev1();
	~SceneDev1() = default;

	virtual void Init(sf::RenderWindow& window) override;
	virtual void Enter() override;
	virtual void Exit() override;


	virtual void Update(float dt) override;
	//오브젝트 그리기
	virtual void Draw(sf::RenderWindow& window) override
	{
		window.clear();

		
		Scene::Draw(window);
		window.draw(spritecancel);
		window.draw(spriteDeck);
		window.draw(spriteGrave);
		window.draw(spriteplayback);
		


		window.display();
	}

};


#pragma once
#include "GameObject.h"
class CardPile :
    public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Text stack;
	std::string textureId;
public:
	CardPile(const std::string& texId, const std::string& name);
	~CardPile();

	virtual void SetPosition(const sf::Vector2f& pos) { sprite.setPosition(pos); }

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		origin = newOrigin;
		originPreset = Origins::Custom;
	}
	virtual void SetScale(sf::Vector2f size);
	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};


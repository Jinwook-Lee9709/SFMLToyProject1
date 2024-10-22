#pragma once
#include "stdafx.h"
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;
	float velocity = 100.f;
public:
	SpriteGo(const std::string& texId, const std::string& name);
	~SpriteGo() = default;

	SpriteGo(const std::string& texId);

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};


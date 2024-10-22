#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
private:
    sf::Sprite sprite;
	std::string textureId;
    int hp, atk, def, shield;
	float velocity = 0.f;
public:
	Player(const std::string& texId);
	~Player() = default;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;

	void Hit(int dmg);
	void Heal(int hp);
	void BufAtk(int atk);
	void BufDef(int def);
	void GetShield(int shield);
	
	


};


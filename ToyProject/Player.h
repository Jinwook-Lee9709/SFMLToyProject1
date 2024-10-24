#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
private:
    sf::Sprite sprite;
	sf::Sprite spriteShield;
	sf::Sprite spriteBuf;
	sf::RectangleShape hpBar;
	sf::Text hpText;
	sf::Text shieldText;
	sf::Text costText;
	sf::Text bufText;
	std::string textureId;
    int maxHp, maxCost, hp, atk, def, shield, cost, hand;
public:
	Player(const std::string& texId);
	~Player() = default;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;

	int GetCost();
	int GetAtk();
	int GetHp() { return hp; }
	void UseCost(Cards card);
	void RestoreCost();
	void Hit(int dmg);
	void Heal(int hp);
	void BufAtk(int atk);
	void BufDef(int def);
	void GetShield(int shield);

	bool CheckPos(sf::Vector2f pos);
	
	


};


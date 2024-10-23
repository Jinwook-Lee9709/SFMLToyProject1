#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
private:
    sf::Sprite sprite;
	sf::RectangleShape hpBar;
	sf::Text hpText;
	std::string textureId;
    int maxHp, hp, atk, def, shield, ap, hand;
public:
	Player(const std::string& texId);
	~Player() = default;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;

	int GetAp();
	int GetAtk();
	void SetAp(int ap);
	void Hit(int dmg);
	void Heal(int hp);
	void BufAtk(int atk);
	void BufDef(int def);
	void GetShield(int shield);

	bool CheckPos(sf::Vector2f pos);
	
	


};


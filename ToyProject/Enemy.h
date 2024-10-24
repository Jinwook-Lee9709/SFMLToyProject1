#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
private:
	sf::Sprite sprite;
	sf::Sprite spriteShield;
	sf::Sprite spriteDebuf;
	sf::RectangleShape hpBar;
	sf::Text hpText;
	sf::Text shieldText;
	sf::Text debufText;
	std::string textureId;
	Monsters mType;
	int maxHp, hp, atk, def, shield, vulnerable;
public:
	Enemy(const std::string& texId);
	~Enemy() = default;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;

	int GetAtk();
	int GetVulnerable();
	int GetHp() { return hp; }


	void SetStat(Monsters mType);
	void Hit(int dmg);
	void HitVulnerable(int stack);
	void Heal(int hp);
	void BufAtk(int atk);
	void BufDef(int def);
	void ChargeShield(int shield);
	void DecreaseVulnerable();




	bool CheckPos(sf::Vector2f pos);



};


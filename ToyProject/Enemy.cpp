#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(const std::string& texId)
	:GameObject(texId), textureId(texId), maxHp(50), hp(50), atk(0), def(0), shield(0)
{
	if (texId == "graphics/Wolf.png");
	mType = Monsters::Wolf;
	name = "Wolf";
	if (texId == "graphics/Tree.png");
	mType = Monsters::Tree;
	name = "Tree";
	if (texId == "graphics/Golem.png");{}
	mType = Monsters::Golem;
	name = "Golem";
}

void Enemy::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Enemy::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Enemy::Reset()
{
	SetStat(mType);
	sprite.setTexture(RES_MGR(sf::Texture).Get(textureId));
	SetOrigin(originPreset);

	hpBar.setSize(sf::Vector2f(200.f, 20.f));
	hpBar.setFillColor(sf::Color(114, 47, 55, 200));
	hpBar.setPosition(sprite.getPosition().x - hpBar.getLocalBounds().width * 0.5f, sprite.getPosition().y);

	hpText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	hpText.setCharacterSize(12);	
	hpText.setOrigin(hpText.getLocalBounds().width * 0.5f,
					hpText.getLocalBounds().height * 0.5f);
	hpText.setPosition(hpBar.getPosition() + sf::Vector2f(80.f, 2.f));
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
	hpText.setFillColor(sf::Color::White);

	

}

void Enemy::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Enemy::Update(float dt)
{
	hpBar.setScale((float)hp / (float)maxHp, 1.0f);
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hpBar);
	window.draw(hpText);
}

void Enemy::SetStat(Monsters mType)
{
	switch (mType) {
	case Monsters::Wolf:
	{
		maxHp = 40;
		hp = maxHp;
		atk = 6;
		def = 0;
	}
	case Monsters::Tree:
	{
		maxHp = 60;
		hp = maxHp;
		atk = 5;
		def = 0;
	}
	case Monsters::Golem:
	{
		maxHp = 100;
		hp = maxHp;
		atk = 8;
		def = 0;
	}
	}
}

void Enemy::Hit(int dmg)
{
	this->shield -= dmg;
	if (shield < 0) {
		hp = hp + shield;
		shield = 0;
	}
	if (hp < 0) {
		hp = 0;
	}
	
}

void Enemy::Heal(int hp)
{
	if (this->hp + hp <= maxHp) {
		this->hp += hp;
	}
	else {
		this->hp = maxHp;
	}
		

}

void Enemy::BufAtk(int atk)
{
	this->atk += atk;
}

void Enemy::BufDef(int def)
{
	this->def += def;
}

void Enemy::GetShield(int shield)
{
	this->shield += shield;
}

bool Enemy::CheckPos(sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

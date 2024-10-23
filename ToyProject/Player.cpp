#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& texId)
	:GameObject("Player"), textureId(texId), maxHp(50), hp(50), atk(0), def(0), shield(0), ap(3), hand(5)
{

}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Player::Reset()
{
	sprite.setTexture(RES_MGR(sf::Texture).Get(textureId));
	SetOrigin(originPreset);

	hpBar.setSize(sf::Vector2f(200.f, 20.f));
	hpBar.setFillColor(sf::Color(114, 47, 55, 200));
	hpBar.setPosition(sprite.getPosition().x - 50, sprite.getPosition().y);

	hpText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	hpText.setCharacterSize(12);	
	hpText.setOrigin(hpText.getLocalBounds().width * 0.5f,
					hpText.getLocalBounds().height * 0.5f);
	hpText.setPosition(hpBar.getPosition() + sf::Vector2f(80.f, 2.f));
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
	hpText.setFillColor(sf::Color::White);

	

}

void Player::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
	sprite.getTextureRect().contains(10,20);
}

void Player::Update(float dt)
{
	hpBar.setScale((float)hp / (float)maxHp, 1.0f);
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hpBar);
	window.draw(hpText);
}

int Player::GetAp()
{
	return ap;
}

int Player::GetAtk()
{
	return atk;
}

void Player::SetAp(int ap)
{
	this->ap = ap;
}

void Player::Hit(int dmg)
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

void Player::Heal(int hp)
{
	if (this->hp + hp <= maxHp) {
		this->hp += hp;
	}
	else {
		this->hp = maxHp;
	}
		

}

void Player::BufAtk(int atk)
{
	this->atk += atk;
}

void Player::BufDef(int def)
{
	this->def += def;
}

void Player::GetShield(int shield)
{
	this->shield += shield;
}

bool Player::CheckPos(sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

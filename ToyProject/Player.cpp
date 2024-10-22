#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& texId)
	:GameObject("Player"), textureId(texId), hp(50), atk(0), def(0), shield(0), ap(3), hand(5)
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
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Player::Update(float dt)
{
	sf::Vector2f playerpos = sprite.getPosition();
	velocity += 0.1f * dt;
	playerpos = { playerpos.x, playerpos.y + velocity};
	sprite.setPosition(playerpos);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

int Player::GetAp()
{
	return ap;
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
	
}

void Player::Heal(int hp)
{
	this->hp += hp;
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

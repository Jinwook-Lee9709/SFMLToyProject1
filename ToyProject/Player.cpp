#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& texId)
	:GameObject("Player"), textureId(texId), maxHp(50), maxCost(3), hp(50), atk(0), def(0), shield(0), cost(3), hand(5)
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

	spriteShield.setTexture(RES_MGR(sf::Texture).Get("graphics/Shield.png"));
	spriteShield.setScale(0.1f, 0.1f);
	spriteShield.setPosition(hpBar.getPosition());
	spriteShield.setOrigin(spriteShield.getLocalBounds().width,
						spriteShield.getLocalBounds().height * 0.5);
	spriteBuf.setTexture(RES_MGR(sf::Texture).Get("graphics/Buf.png"));
	spriteBuf.setScale(0.1f, 0.1f);
	spriteBuf.setPosition(hpBar.getPosition() + sf::Vector2f(40.f, -30.f));
	spriteBuf.setOrigin(spriteBuf.getLocalBounds().width,
		spriteBuf.getLocalBounds().height * 0.5);

	hpText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	hpText.setCharacterSize(12);	
	hpText.setOrigin(hpText.getLocalBounds().width * 0.5f,
					hpText.getLocalBounds().height * 0.5f);
	hpText.setPosition(hpBar.getPosition() + sf::Vector2f(80.f, 2.f));
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
	hpText.setFillColor(sf::Color::White);

	shieldText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	shieldText.setCharacterSize(15);
	shieldText.setOrigin(shieldText.getLocalBounds().width * 0.5f,
						shieldText.getLocalBounds().height * 0.5f);
	shieldText.setPosition(spriteShield.getPosition() - sf::Vector2f(30.f, 10.f));
	shieldText.setString(std::to_string(shield));
	shieldText.setFillColor(sf::Color::Black);

	costText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	costText.setCharacterSize(20);
	costText.setOrigin(hpText.getLocalBounds().width * 0.5f,
					costText.getLocalBounds().height * 0.5f);
	costText.setPosition(hpBar.getPosition() - sf::Vector2f(126.f, 13.f));
	costText.setString(std::to_string(cost) + "/" + std::to_string(maxCost));
	costText.setFillColor(sf::Color::Black);
	
	bufText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	bufText.setCharacterSize(20);
	bufText.setOrigin(0.f, 0.f);
	bufText.setPosition(spriteBuf.getPosition() - sf::Vector2f(10.f, -5.f));
	bufText.setString(std::to_string(atk));
	bufText.setFillColor(sf::Color::Black);

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
	costText.setString(std::to_string(cost) + "/" + std::to_string(maxCost));
	bufText.setString(std::to_string(atk));
	shieldText.setString(std::to_string(shield));
	if (shield == 0) {
		spriteShield.setColor(sf::Color::Transparent);
		shieldText.setFillColor(sf::Color::Transparent);
		hpBar.setFillColor(sf::Color(114, 47, 55, 200));
	}
	else {
		spriteShield.setColor(sf::Color::White);
		shieldText.setFillColor(sf::Color::Black);
		hpBar.setFillColor(sf::Color(80, 80, 80, 200));
	}
	if (atk == 0) {
		spriteBuf.setColor(sf::Color::Transparent);
		bufText.setFillColor(sf::Color::Transparent);
	}
	else {
		spriteBuf.setColor(sf::Color::White);
		bufText.setFillColor(sf::Color::White);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hpBar);
	window.draw(hpText);
	window.draw(costText);
	window.draw(spriteShield);
	window.draw(shieldText);
	window.draw(spriteBuf);
	window.draw(bufText);
}

int Player::GetCost()
{
	return cost;
}

int Player::GetAtk()
{
	return atk;
}

void Player::UseCost(Cards card)
{
	switch (card) {
		case Cards::Bash: {
			cost -= 2;
			break;
		}
		case Cards::Defend: {
			cost -= 1;
			break;
		}
		case Cards::Inflame: {
			cost -= 1;
			break;
		}
		case Cards::Strike: {
			cost -= 1;
			break;
		}
	}
}

void Player::RestoreCost()
{
	cost = maxCost;
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

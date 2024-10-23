#include "stdafx.h"
#include "Card.h"

Card::Card(const std::string& texId)
	:GameObject("Player"), textureId(texId), select(false)
{

}

void Card::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Card::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Card::Reset()
{
	DECK_CTRL.Init();
	Cards hand = DECK_CTRL.drawCard();
	type = hand;
	switch(type){
		case Cards::Bash :{
			textureId = "graphics/Bash.png";
			break;
		}
		case Cards::Defend :{
			textureId = "graphics/Defend.png";
			break;
		}
		case Cards::Inflame : {
			textureId = "graphics/Inflame.png";
			break;
		}
		case Cards::Strike : {
			textureId = "graphics/Strike.png";
			break;
		}
	}
	InitCard();
}

void Card::InitCard()
{
	sprite.setTexture(RES_MGR(sf::Texture).Get(textureId));
	SetOrigin(originPreset);

	cardText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	cardText.setCharacterSize(12);
	cardText.setString(Utils::makeCardText(type, 0));
	cardText.setOrigin(cardText.getLocalBounds().width * 0.5f,
		cardText.getLocalBounds().height * 0.5f);
	cardText.setPosition(sprite.getPosition() - sf::Vector2f(0.f, sprite.getLocalBounds().height * 0.08f));
	cardText.setFillColor(sf::Color::White);
}

void Card::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Card::SetScale(sf::Vector2f size)
{
	sprite.setScale(size);
}

void Card::SetName(std::string name)
{
	this->name = name;
}

void Card::Update(float dt)
{
	if (select == true) {
		sprite.setColor(sf::Color(74, 255, 226, 200));
	}
	else {
		sprite.setColor(sf::Color::White);
	}
	
}

void Card::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(cardText);
}

void Card::selected()
{
	this->select = true;
}

void Card::unSelected()
{
	this->select = false;
}

void Card::UpdateCard(int atk)
{
	cardText.setString(Utils::makeCardText(type, atk));
}

Cards Card::getType()
{
	return type;
}

bool Card::CheckPos(sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

void Card::SetCardType(Cards type)
{
	this->type = type;
}


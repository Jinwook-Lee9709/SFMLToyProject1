#include "stdafx.h"
#include "CardPile.h"

CardPile::CardPile(const std::string& texId, const std::string& name)
	:GameObject(name), textureId(texId)
{
}

CardPile::~CardPile()
{
}


void CardPile::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void CardPile::SetScale(sf::Vector2f size)
{
	sprite.setScale(size);
}

void CardPile::Init()
{
	stack.setString(std::to_string(DeckController::Instance().getDeckSize()));
}

void CardPile::Release()
{
}

void CardPile::Reset()
{
	sprite.setTexture(RES_MGR(sf::Texture).Get(textureId));
	stack.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	stack.setCharacterSize(40);
	stack.setPosition(sprite.getPosition() + sf::Vector2f(-28.f, -25.f));
	if (this->name == "Deck") {
		stack.setString(std::to_string(DECK_CTRL.getDeckSize()));
	}
	else if (this->name == "Grave") {
		stack.setString(std::to_string(DECK_CTRL.getGraveSize()));
	}
	stack.setFillColor(sf::Color::Black);
	stack.setOutlineColor(sf::Color::White);
	stack.setOutlineThickness(5);
	SetOrigin(originPreset);
}

void CardPile::Update(float dt)
{
	if (this->name == "Deck") {
		stack.setString(std::to_string(DECK_CTRL.getDeckSize()));
	}
	else if (this->name == "Grave") {
		stack.setString(std::to_string(DECK_CTRL.getGraveSize()));
	}
	
}

void CardPile::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(stack);
}

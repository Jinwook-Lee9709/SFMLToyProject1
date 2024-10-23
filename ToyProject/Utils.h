#pragma once
class Utils
{
public:

	// Origin
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& text, Origins preset);
	static sf::String makeCardText(Cards card, int atk);

};


#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& font, const std::string& str)
	:GameObject(str), font(font)
{
}


TextGo::TextGo(const std::string& font)
	:font(font)
{

}

void TextGo::SetText(const std::string& str)
{
	text.setString(str);
}

void TextGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, originPreset);
}

void TextGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	text.setOrigin(origin);
}

void TextGo::Reset()
{
	text.setFont(RES_MGR(sf::Font).Get(font));
	SetOrigin(originPreset);
}

void TextGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void TextGo::Draw(sf::RenderWindow& window)
{

	GameObject::Draw(window);
	
	window.draw(text);
}

void TextGo::SetSize(int size)
{
	text.setCharacterSize(size);
}

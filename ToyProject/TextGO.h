#pragma once
#include "stdafx.h"

class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string font;
public:
	TextGo(const std::string& font, const std::string& str);
	~TextGo() = default;

	TextGo(const std::string& font);

	virtual void SetText(const std::string& str);

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos)override;
	void Draw(sf::RenderWindow& window)override;


};


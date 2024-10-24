#pragma once
#include "GameObject.h"
class Card :
    public GameObject
{
private:
	sf::Sprite sprite;
	sf::Text cardText;
	std::string textureId;
	bool select;
	Cards type;
public:
	Card(const std::string& texId);
	~Card() = default;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void Reset() override;
	void InitCard();
	void SetPosition(const sf::Vector2f& pos) override;
	
	void SetScale(sf::Vector2f size);
	void SetName(std::string name);
	void Update(float dt);
	void Draw(sf::RenderWindow& window) override;
	

	void selected();
	void unSelected();
	void UpdateCard(int atk);
	Cards getType();
	bool CheckPos(sf::Vector2f pos);
	sf::Vector2f GetPosition();

	void SetCardType(Cards type);
};


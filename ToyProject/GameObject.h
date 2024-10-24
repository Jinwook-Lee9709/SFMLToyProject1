#pragma once
#include "stdafx.h"
class GameObject
{
protected:
	std::string name;
	bool active = true; //determine object run Update, Draw
	sf::Vector2f position;
	Origins originPreset;
	sf::Vector2f origin;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();

	const std::string& GetName() const { return name; }
	void SetName(const std::string& n) { name = n; }


	bool IsActive() const { return active; }
	void SetActive(bool a) { active = a; }

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		origin = newOrigin;
		originPreset = Origins::Custom;
	}
	virtual void SetScale(sf::Vector2f size);
	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

};


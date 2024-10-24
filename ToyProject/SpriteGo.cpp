#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	:GameObject(name), textureId(texId)
{
}

SpriteGo::SpriteGo(const std::string& texId)
	:textureId(texId)
{
}

void SpriteGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void SpriteGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void SpriteGo::Reset()
{
	auto& texResMgr = ResourceManager<sf::Texture>::Instance();
	sprite.setTexture(texResMgr.Get(textureId));
	SetOrigin(originPreset);
}

void SpriteGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void SpriteGo::SetScale(const sf::Vector2f& size)
{
	GameObject::SetScale(size);
	sprite.setScale(size);
}





void SpriteGo::Update(float dt)
{
	
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

bool SpriteGo::CheckPos(sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

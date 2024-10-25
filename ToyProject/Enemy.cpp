#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(const std::string& texId)
	:GameObject(texId), textureId(texId), maxHp(50), hp(50), atk(0), def(0), shield(5), vulnerable(0)
{
	if (texId == "graphics/Wolf.png");
	mType = Monsters::Wolf;
	name = "Wolf";
	if (texId == "graphics/Tree.png");
	mType = Monsters::Tree;
	name = "Tree";
	if (texId == "graphics/Golem.png");{}
	mType = Monsters::Golem;
	name = "Golem";
}

void Enemy::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Enemy::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Enemy::Reset()
{
	SetStat(mType);
	sprite.setTexture(RES_MGR(sf::Texture).Get(textureId));
	SetOrigin(originPreset);

	hpBar.setSize(sf::Vector2f(200.f, 20.f));
	hpBar.setFillColor(sf::Color(114, 47, 55, 200));
	hpBar.setPosition(sprite.getPosition().x - hpBar.getLocalBounds().width * 0.5f, sprite.getPosition().y);

	spriteShield.setTexture(RES_MGR(sf::Texture).Get("graphics/Shield.png"));
	spriteShield.setScale(0.1f, 0.1f);
	spriteShield.setPosition(hpBar.getPosition());
	spriteShield.setOrigin(spriteShield.getLocalBounds().width,
		spriteShield.getLocalBounds().height * 0.5);
	
	spriteDebuf.setTexture(RES_MGR(sf::Texture).Get("graphics/Debuf.png"));
	spriteDebuf.setScale(0.08f, 0.08f);
	spriteDebuf.setPosition(hpBar.getPosition() + sf::Vector2f(31.f, -30.f));
	spriteDebuf.setOrigin(spriteDebuf.getLocalBounds().width,
		spriteDebuf.getLocalBounds().height * 0.5);

	hpText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	hpText.setCharacterSize(12);	
	//hpText.setOrigin(hpText.getLocalBounds().width * 0.5f,
	//				hpText.getLocalBounds().height * 0.5f);
	hpText.setPosition(hpBar.getPosition() + sf::Vector2f(80.f, 2.f));
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
	hpText.setFillColor(sf::Color::White);

	shieldText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	shieldText.setCharacterSize(15);
	//shieldText.setOrigin(shieldText.getLocalBounds().width * 0.5f,
	//shieldText.getLocalBounds().height * 0.5f);
	shieldText.setPosition(spriteShield.getPosition() - sf::Vector2f(25.f, 10.f));
	shieldText.setString(std::to_string(shield));
	shieldText.setOrigin(shieldText.getLocalBounds().width * 0.5f, 0.f);
	shieldText.setFillColor(sf::Color::Black);

	debufText.setFont(RES_MGR(sf::Font).Get("fonts/Sansation.ttf"));
	debufText.setCharacterSize(15);
	/*debufText.setOrigin(debufText.getLocalBounds().width * 0.5f,
		debufText.getLocalBounds().height * 0.5f);*/
	debufText.setPosition(spriteDebuf.getPosition() - sf::Vector2f(30.f, 10.f));
	debufText.setString(std::to_string(vulnerable));
	debufText.setFillColor(sf::Color::Black);
}

void Enemy::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Enemy::Update(float dt)
{
	hpBar.setScale((float)hp / (float)maxHp, 1.0f);
	hpText.setString(std::to_string(hp) + "/" + std::to_string(maxHp));
	shieldText.setString(std::to_string(shield));
	debufText.setString(std::to_string(vulnerable));
	shieldText.setOrigin(shieldText.getLocalBounds().width * 0.5f, 0.f);
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
	if (vulnerable == 0) {
		spriteDebuf.setColor(sf::Color::Transparent);
		debufText.setFillColor(sf::Color::Transparent);
	}
	else {
		spriteDebuf.setColor(sf::Color::White);
		debufText.setFillColor(sf::Color::Black);
	}

}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hpBar);
	window.draw(hpText);
	window.draw(spriteShield);
	window.draw(shieldText);
	window.draw(spriteDebuf);
	window.draw(debufText);
}

void Enemy::SetStat(Monsters mType)
{
	vulnerable = 0;
	switch (mType) {
	case Monsters::Wolf:
	{
		maxHp = 40;
		hp = maxHp;
		atk = 6;
		def = 0;
	}
	case Monsters::Tree:
	{
		maxHp = 60;
		hp = maxHp;
		atk = 5;
		def = 0;
	}
	case Monsters::Golem:
	{
		maxHp = 100;
		hp = maxHp;
		atk = 8;
		def = 0;
	}
	}
}

void Enemy::Hit(int dmg)
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
void Enemy::HitVulnerable(int stack){
	vulnerable += stack;
}


void Enemy::Heal(int hp)
{
	if (this->hp + hp <= maxHp) {
		this->hp += hp;
	}
	else {
		this->hp = maxHp;
	}
		

}

void Enemy::BufAtk(int atk)
{
	this->atk += atk;
}

void Enemy::BufDef(int def)
{
	this->def += def;
}

int Enemy::GetAtk()
{
	return atk;
}

int Enemy::GetVulnerable()
{
	return vulnerable;
}

void Enemy::ChargeShield(int shield)
{
	this->shield += shield;
}

void Enemy::DecreaseVulnerable()
{ 
	if (vulnerable > 0) {
		--vulnerable;
	}
}

bool Enemy::CheckPos(sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

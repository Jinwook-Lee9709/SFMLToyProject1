#pragma once
class Animation : public Singleton<Animation>
{
	friend class Singleton<Animation>;
private:
	sf::Sprite spriteAttack;
	sf::Sprite spriteMAttack;
	sf::Sprite spriteBuf;
	sf::IntRect rectSourceSpriteAttack;
	sf::IntRect rectSourceSpriteBuf;
	int cnt;
	bool atk, atkF,mAtk, mAtkF, buf, bufF;
	float elapsedTime;
public:
	Animation();
	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void Attack(float dt);
	void mAttack(float dt);
	void Buf(float dt);

	void triggerAttack();
	void triggerMAttack();
	void triggerBuf();

};


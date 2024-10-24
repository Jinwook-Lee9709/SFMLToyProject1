#include "stdafx.h"
#include "Animation.h"



Animation::Animation()
{
}

void Animation::Init()
{
    cnt = 0;
    rectSourceSpriteAttack.left = 0;
    rectSourceSpriteAttack.top = 0;
    rectSourceSpriteAttack.width = 190;
    rectSourceSpriteAttack.height = 190;
    rectSourceSpriteBuf.left = 0;
    rectSourceSpriteBuf.top = 0;
    rectSourceSpriteBuf.width = 235;
    rectSourceSpriteBuf.height = 220;
	spriteAttack.setTexture(RES_MGR(sf::Texture).Get("graphics/Slash.png"));
    spriteMAttack.setTexture(RES_MGR(sf::Texture).Get("graphics/Slash.png"));
    spriteBuf.setTexture(RES_MGR(sf::Texture).Get("graphics/Aura.png"));
	spriteAttack.setTextureRect(rectSourceSpriteAttack);
    spriteMAttack.setTextureRect(rectSourceSpriteAttack);
    spriteBuf.setTextureRect(rectSourceSpriteAttack);
    spriteAttack.setPosition(FRAMEWORK.GetWindow().getSize().x * 0.65f, FRAMEWORK.GetWindow().getSize().y * 0.6f);
    spriteMAttack.setPosition(FRAMEWORK.GetWindow().getSize().x * 0.4f, FRAMEWORK.GetWindow().getSize().y * 0.2f);
    spriteBuf.setPosition(FRAMEWORK.GetWindow().getSize().x * 0.15f, FRAMEWORK.GetWindow().getSize().y * 0.20f);
    spriteAttack.setRotation(-90);
    spriteAttack.setScale( 2.f, 2.f );
    spriteMAttack.setRotation(90);
    spriteMAttack.setScale(2.f, 2.f);
    spriteBuf.setScale(1.8f, 1.8f);
   

}
void Animation::Update(float dt) {
    Attack(dt);
    mAttack(dt);
    Buf(dt);
}
void Animation::Attack(float dt)
{
    if (atk == true) {
        atkF = true;
        if (elapsedTime > 0.1f) {
            if (rectSourceSpriteAttack.left == 380)
                rectSourceSpriteAttack.left = 0;
            else
                rectSourceSpriteAttack.left += 190;

            spriteAttack.setTextureRect(rectSourceSpriteAttack);
            elapsedTime = 0;
            cnt++;
        }
        if (cnt == 3) {
            elapsedTime = 0;
            cnt = 0;
            atk = false;
            atkF = false;
        }
        elapsedTime += dt;
   }
  
}
void Animation::mAttack(float dt)
{
    if (mAtk == true) {
        mAtkF = true;
        if (elapsedTime > 0.1f) {
            if (rectSourceSpriteAttack.left == 380)
                rectSourceSpriteAttack.left = 0;
            else
                rectSourceSpriteAttack.left += 190;

            spriteMAttack.setTextureRect(rectSourceSpriteAttack);
            elapsedTime = 0;
            cnt++;
        }
        if (cnt == 3) {
            elapsedTime = 0;
            cnt = 0;
            mAtk = false;
            mAtkF = false;
        }
        elapsedTime += dt;
    }

}

void Animation::Buf(float dt)
{
    if (buf == true) {
        bufF = true;
        if (elapsedTime > 0.1f) {
            if (rectSourceSpriteBuf.left == 705)
                rectSourceSpriteBuf.left = 0;
            else
                rectSourceSpriteBuf.left += 235;

            spriteBuf.setTextureRect(rectSourceSpriteBuf);
            elapsedTime = 0;
            cnt++;
        }
        if (cnt == 4) {
            elapsedTime = 0;
            cnt = 0;
            buf = false;
            bufF = false;
        }
        elapsedTime += dt;
    }
}

void Animation::triggerAttack()
{
    atk = true;
}

void Animation::triggerMAttack()
{
    mAtk = true;
}

void Animation::triggerBuf()
{
    buf = true;
}

void Animation::Draw(sf::RenderWindow& window)
{
    if (atkF) {
        window.draw(spriteAttack);
    }
    if (mAtkF) {
        window.draw(spriteMAttack);
    }
    if (bufF) {
        window.draw(spriteBuf);
    }
        
}

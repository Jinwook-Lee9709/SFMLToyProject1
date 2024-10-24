#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{

}
// �����Ҷ� ������Ʈ �ʱ�ȭ�ϱ�
void SceneDev1::Init(sf::RenderWindow& window)
{

	RES_MGR(sf::Texture).Load("graphics/Deck.png");
	RES_MGR(sf::Texture).Load("graphics/Grave.png");
	RES_MGR(sf::Texture).Load("graphics/cancel.png");
	RES_MGR(sf::Texture).Load("graphics/playback.png");

	
	spritecancel.setTexture(RES_MGR(sf::Texture).Get("graphics/cancel.png"));
	spriteDeck.setTexture(RES_MGR(sf::Texture).Get("graphics/Deck.png"));
	spriteGrave.setTexture(RES_MGR(sf::Texture).Get("graphics/Grave.png"));
	spriteplayback.setTexture(RES_MGR(sf::Texture).Get("graphics/playback.png"));
	Scene::Init(window);
}
//���ҽ� �ε�
void SceneDev1::Enter()
{
	std::cout << "SceneDev1:: Enter()" << std::endl;

	/*RES_MGR(sf::Texture).Load("graphics/background.png");*/
	
	Scene::Enter();
}
//���ҽ� �����ϱ�
void SceneDev1::Exit()
{
	std::cout << "SceneDev1:: Exit()" << std::endl;

	Scene::Exit();

	//RES_MGR(sf::Texture).UnLoad("graphics/background.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Deck.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Grave.png");
	RES_MGR(sf::Texture).UnLoad("graphics/cancel.png");
	RES_MGR(sf::Texture).UnLoad("graphics/playback.png");
}
//������Ʈ ������Ʈ�ϱ�
void SceneDev1::Update(float dt)
{

	/*SCENE_MGR.ChangeScene(SceneIds::Battle);*/
	Scene::Update(dt);
}

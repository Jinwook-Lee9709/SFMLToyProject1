#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{

}

void SceneDev1::Init(sf::RenderWindow& window)
{
	std::cout << "SceneDev1:: Init()" << std::endl;

	auto* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 /2 , 1080 / 2 });
	auto* obj2 = AddGo(new TextGo("fonts/Sansation.ttf"));
	obj2->SetOrigin(Origins::TC);
	obj2->SetPosition({ 1920 / 2, 20 });
	obj2->SetText("SceneDev1");
	Scene::Init(window);
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1:: Enter()" << std::endl;

	RES_MGR(sf::Texture).Load("graphics/background.png");
	RES_MGR(sf::Font).Load("fonts/Sansation.ttf");

	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1:: Exit()" << std::endl;

	Scene::Exit();

	RES_MGR(sf::Texture).UnLoad("graphics/background.png");
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}



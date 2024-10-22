#include "stdafx.h"
#include "SceneBattle.h"
#include "Player.h"
#include "TextGo.h"

SceneBattle::SceneBattle()
	:Scene(SceneIds::Battle)
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Init()
{
	auto* obj = AddGo(new Player("graphics/Ironclad.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });
	Scene::Init();
}

void SceneBattle::Enter()
{
	RES_MGR(sf::Texture).Load("graphics/Ironclad.png");
	
	Scene::Enter();
}

void SceneBattle::Exit()
{
	RES_MGR(sf::Texture).UnLoad("graphics/Ironcladpng");
}

void SceneBattle::Update(float dt)
{
	//�Է´�� / �÷��̾��� ���� / �� �� ���� / �� �ൿ����
	Scene::Update(dt);
}

void SceneBattle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

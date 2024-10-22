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
	auto* obj = AddGo(new Player("graphics/player.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });
	Scene::Init();
}

void SceneBattle::Enter()
{
	RES_MGR(sf::Texture).Load("graphics/player.png");
	
	Scene::Enter();
}

void SceneBattle::Exit()
{
	RES_MGR(sf::Texture).UnLoad("graphics/player.png");
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

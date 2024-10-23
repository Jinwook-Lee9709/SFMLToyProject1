#include "stdafx.h"
#include "SceneManager.h"
#include "SceneDev1.h"
#include "SceneBattle.h"

void SceneManager::Init(sf::RenderWindow& window)
{
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneBattle());
	for (auto scene : scenes)
	{
		scene->Init(window);
	}
	currentScene = startScene;
	scenes[(int)currentScene]->Enter();

}


void SceneManager::Release()
{
	for (auto scene : scenes) {
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneManager::ChangeScene(SceneIds id)
{
	scenes[(int)currentScene]->Exit();
	currentScene = id;
	scenes[(int)currentScene]->Enter();
}

void SceneManager::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}

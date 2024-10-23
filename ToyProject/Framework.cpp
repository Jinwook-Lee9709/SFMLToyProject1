#include "stdafx.h"
#include "SpriteGo.h"


void Framework::Init(int width, int height, const std::string& name)
{
	window.create(sf::VideoMode(width, height), name);

    SCENE_MGR.Init(window);
}

void Framework::Do()
{
  

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        realDeltaTime = deltaTime;
        deltaTime *= timeScale;

        realTime += realDeltaTime;
        time += deltaTime;
        
        InputManager::Clear();
        //Evenet Loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            InputManager::UpdateEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update
        SCENE_MGR.Update(deltaTime);
        //Draw
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
}

void Framework::Release()
{
    SCENE_MGR.Release();
}

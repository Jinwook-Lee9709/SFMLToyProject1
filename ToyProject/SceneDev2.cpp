#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::Dev2)
{
}


void SceneDev2::Init(sf::RenderWindow& window)
{
	this->window = &window;

	std::cout << "SceneDev2:: Init()" << std::endl;

	RES_MGR(sf::Texture).Load("graphics/cool.png");
	spritecool.setTexture(RES_MGR(sf::Texture).Get("graphics/cool.png"));
	RES_MGR(sf::Font).Load("fonts/KOMIKAP_.ttf");
	RES_MGR(sf::Texture).Load("graphics/playbutton.png");
	spriteplaybutton.setTexture(RES_MGR(sf::Texture).Get("graphics/playbutton.png"));
	RES_MGR(sf::Texture).Load("graphics/out.png");
	spriteout.setTexture(RES_MGR(sf::Texture).Get("graphics/out.png"));
}

void SceneDev2::Enter()
{
	messageText.setFont(RES_MGR(sf::Font).Get("fonts/KOMIKAP_.ttf"));
	messageText.setCharacterSize(150);
	messageText.setString("Slay the Spire");
	messageText.setFillColor(sf::Color::Black);
	messageText.setPosition(200, 100);
	spriteplaybutton.setPosition(100, 450);
	spriteout.setScale(1.0f,0.8f);
	spriteout.setPosition(1000, 500);
}

void SceneDev2::Exit()
{
	RES_MGR(sf::Texture).UnLoad("graphics/cool.png");
	RES_MGR(sf::Texture).UnLoad("graphics/playbutton.png");
	RES_MGR(sf::Texture).UnLoad("graphics/out.png");
}

void SceneDev2::Update(float dt)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
		sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
		
		if (spriteplaybutton.getGlobalBounds().contains(worldPos))
		{
	
			SCENE_MGR.ChangeScene(SceneIds::Battle);
		}
		if (spriteout.getGlobalBounds().contains(worldPos))
		{
		
			window->close();
		}
	}
	Scene::Update(dt);
}

void SceneDev2::Draw(sf::RenderWindow& window)
{	
	window.draw(spritecool);
	window.draw(messageText);
	window.draw(spriteout);
	window.draw(spriteplaybutton);
}

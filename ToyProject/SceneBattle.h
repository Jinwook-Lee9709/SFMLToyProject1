#include "Scene.h"

#pragma once
class SceneBattle : public Scene
{
protected:

public:
	SceneBattle();
	~SceneBattle();

	virtual void Init() override;
	virtual void Enter() override;
	virtual void Exit() override;


	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};


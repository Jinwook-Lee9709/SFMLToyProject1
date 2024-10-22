#pragma once
#include "Scene.h"
class SceneDev1 : public Scene
{
protected:
	
public:
	SceneDev1();
	~SceneDev1() = default;;

	virtual void Init() override;
	virtual void Enter() override;
	virtual void Exit() override;


	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};


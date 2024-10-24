#pragma once
class Scene
{
protected:
	SceneIds id;
	std::list<GameObject*> gameObjects;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init(sf::RenderWindow& window);
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	template<typename T>
	T* AddGo(T* obj);
	virtual void RemoveGo(GameObject* obj);

	virtual GameObject* FindGo(const std::string& name);
	virtual int FindGoAll(const std::string& name, std::list<GameObject*>& list);
	
};

template<typename T>
inline T* Scene::AddGo(T* obj)
{
	if (std::find(gameObjects.begin(), gameObjects.end(), obj) == gameObjects.end())
	{
		gameObjects.push_back(obj);
	}
	return (obj);
}
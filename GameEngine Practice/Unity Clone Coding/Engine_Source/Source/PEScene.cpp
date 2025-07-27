#include "PEScene.h"

namespace PracticeEngine {
	Scene::Scene() : mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize() 
	{
	
	}
	void Scene::Update() 
	{
		for (GameObject* g : mGameObjects) g->Update();
	}
	void Scene::LateUpdate() 
	{
		for (GameObject* g : mGameObjects) g->LateUpdate();
	}
	void Scene::Render(HDC hdc) 
	{
		for (GameObject* g : mGameObjects) g->Render(hdc);
	}

	void Scene::AddGameObject(GameObject* go) 
	{
		mGameObjects.push_back(go); // 게임오브젝트 대입
	}
}

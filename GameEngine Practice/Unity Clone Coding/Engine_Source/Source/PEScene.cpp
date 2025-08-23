#include "PEScene.h"
#include "PELayer.h"
#include "PEGameObject.h"
#include "PECollisionManager.h"

namespace PracticeEngine {
	Scene::Scene() : mLayers{}
	{
		createLayers();
		
	}
	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize() 
	{
		for (Layer* l : mLayers) {
			if (l == nullptr) continue;
			l->Initialize();
		}
	}
	void Scene::Update() 
	{
		for (Layer* l : mLayers) {
			if (l == nullptr) continue;
			l->Update();
		}
	}
	void Scene::LateUpdate() 
	{
		for (Layer* l : mLayers) {
			if (l == nullptr) continue;
			l->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc) 
	{
		for (Layer* l : mLayers) {
			if (l == nullptr) continue;
			l->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}

	void Scene::AddGameObject(GameObject* go, eLayerType layer) {
		mLayers[(UINT)layer]->AddGameObject(go);
	}

	void Scene::EraseGameObject(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)eLayerType::Max);

		for (size_t i = 0; i < (UINT)eLayerType::Max; i++) {
			mLayers.at(i) = new Layer();
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}
}

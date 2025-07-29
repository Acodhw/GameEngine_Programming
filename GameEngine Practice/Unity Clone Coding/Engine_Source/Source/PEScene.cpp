#include "PEScene.h"

namespace PracticeEngine {
	Scene::Scene() : mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);

		for (size_t i = 0; i < (UINT)eLayerType::Max; i++) {
			mLayers.at(i) = new Layer();
		}
	}
	Scene::~Scene()
	{

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

	}

	void Scene::AddGameObject(GameObject* go, eLayerType layer) {
		mLayers[(UINT)layer]->AddGameObject(go);
	}
}

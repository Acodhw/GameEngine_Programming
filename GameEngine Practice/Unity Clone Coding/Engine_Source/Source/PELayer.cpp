#include "PELayer.h"

namespace PracticeEngine
{
	Layer::Layer() :layer(eLayerType::None), mGameObjects{} 
	{
	}
	Layer::~Layer() {
	}

	void Layer::Initialize() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			g->Initialize();
		}
	}
	void Layer::Update() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			g->Update();
		}
	}
	void Layer::LateUpdate() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			g->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc) {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			g->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* go)
	{
		if (go == nullptr) return;
		mGameObjects.push_back(go); // 게임오브젝트 대입
	}
}
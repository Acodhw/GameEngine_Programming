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
			GameObject::eState state = g->state;
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) continue;
			g->Initialize();
		}
	}
	void Layer::Update() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			GameObject::eState state = g->state;
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) continue;
			g->Update();
		}
	}
	void Layer::LateUpdate() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			GameObject::eState state = g->state;
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) continue;
			g->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc) {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			GameObject::eState state = g->state;
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) continue;
			g->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* go)
	{
		if (go == nullptr) return;
		mGameObjects.push_back(go); // 게임오브젝트 대입
	}

	void Layer::Destroy()
	{
		GameObjectIter iter = mGameObjects.begin();

		while(iter != mGameObjects.end())
		{
			GameObject::eState active = (*iter)->state;
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}
}
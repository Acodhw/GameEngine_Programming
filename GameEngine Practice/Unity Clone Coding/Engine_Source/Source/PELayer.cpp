#include "PELayer.h"
#include <algorithm>

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
	void Layer::Render() {
		for (GameObject* g : mGameObjects) {
			if (g == nullptr) continue;
			GameObject::eState state = g->state;
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) continue;
			g->Render();
		}
	}

	void Layer::AddGameObject(GameObject* go)
	{
		if (go == nullptr) return;
		mGameObjects.push_back(go); // ���ӿ�����Ʈ ����
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

	void Layer::EraseGameObject(GameObject* eraseGameObj)
	{
		// std::erase() iter�־��༭ �ش� ���ͷ��̿� ���� ��ü ����
		std::erase_if(mGameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
	}

	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			GameObject::eState active = gameObj->state;
			if (active == GameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs)
	{
		for (GameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}
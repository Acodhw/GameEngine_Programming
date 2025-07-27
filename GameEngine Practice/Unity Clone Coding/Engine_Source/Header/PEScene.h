#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* go);

	private:
		std::vector<GameObject*> mGameObjects; // 씬에 배치된 오브젝트들
	};
}


#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	// 게임의 오브젝트가 담긴 장면을 제공하는 클래스
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// 씬에 게임오브젝트를 배치합니다
		void AddGameObject(GameObject* go);

	private:
		std::vector<GameObject*> mGameObjects; // 씬에 배치된 오브젝트들
	};
}


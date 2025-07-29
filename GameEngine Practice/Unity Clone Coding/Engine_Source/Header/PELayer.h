#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		// 레이어에 게임오브젝트를 배치합니다
		void AddGameObject(GameObject* go);
	private:
		eLayerType layer; // 레이어
		std::vector<GameObject*> mGameObjects; // 같은 레이어의 오브젝트들
	};

}
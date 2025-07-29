#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"
#include "PELayer.h"

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

		//씬이 작동될 때 실행되는 함수
		virtual void OnEnter();
		//씬에서 나가는 순간 실행되는 함수
		virtual void OnExit();

		// 레이어에 게임오브젝트를 배치합니다
		void AddGameObject(GameObject* go, eLayerType layer);
		Layer* GetLayer(const eLayerType layer) { return mLayers[(UINT)layer]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers; // 씬에 배치된 레이어들
	};
}


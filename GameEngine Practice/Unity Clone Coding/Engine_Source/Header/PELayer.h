#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine
{
	// 오브젝트의 생성 순서를 나타내는 레이어
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		// 레이어에 게임오브젝트를 배치합니다
		void AddGameObject(GameObject* go);
		// 레이어 속의 게임 오브젝트를 제거합니다.
		void EraseGameObject(GameObject* eraseGameObj);
		// 레이어의 게임 오브젝트 리스트를 가져옵니다
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseDeadGameObject();
	private:
		eLayerType layer; // 레이어
		std::vector<GameObject*> mGameObjects; // 같은 레이어의 오브젝트들
	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}
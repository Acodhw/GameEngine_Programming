#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine
{
	// ������Ʈ�� ���� ������ ��Ÿ���� ���̾�
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

		// ���̾ ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go);
		// ���̾� ���� ���� ������Ʈ�� �����մϴ�.
		void EraseGameObject(GameObject* eraseGameObj);
		// ���̾��� ���� ������Ʈ ����Ʈ�� �����ɴϴ�
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseDeadGameObject();
	private:
		eLayerType layer; // ���̾�
		std::vector<GameObject*> mGameObjects; // ���� ���̾��� ������Ʈ��
	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}
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

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		// ���̾ ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go);

		// ���̾��� ���� ������Ʈ ����Ʈ�� �����ɴϴ�
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }
	private:
		eLayerType layer; // ���̾�
		std::vector<GameObject*> mGameObjects; // ���� ���̾��� ������Ʈ��
	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}
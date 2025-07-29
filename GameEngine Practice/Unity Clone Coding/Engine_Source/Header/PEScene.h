#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	// ������ ������Ʈ�� ��� ����� �����ϴ� Ŭ����
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// ���� ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go);

	private:
		std::vector<GameObject*> mGameObjects; // ���� ��ġ�� ������Ʈ��
	};
}


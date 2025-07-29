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

		// ���̾ ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go);
	private:
		eLayerType layer; // ���̾�
		std::vector<GameObject*> mGameObjects; // ���� ���̾��� ������Ʈ��
	};

}
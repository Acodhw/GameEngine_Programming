#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"
#include "PELayer.h"

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

		//���� �۵��� �� ����Ǵ� �Լ�
		virtual void OnEnter();
		//������ ������ ���� ����Ǵ� �Լ�
		virtual void OnExit();

		// ���̾ ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go, eLayerType layer);
		Layer* GetLayer(const eLayerType layer) { return mLayers[(UINT)layer]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers; // ���� ��ġ�� ���̾��
	};
}


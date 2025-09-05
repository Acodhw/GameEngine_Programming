#pragma once
#include "PEEntity.h"
#include "PEGameObject.h"
#include "PELayer.h"

namespace PracticeEngine {
	class Layer;
	// ������ ������Ʈ�� ��� ����� �����ϴ� Ŭ����
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//���� �۵��� �� ����Ǵ� �Լ�
		virtual void OnEnter();
		//������ ������ ���� ����Ǵ� �Լ�
		virtual void OnExit();
		virtual void Destroy();

		// ���̾ ���ӿ�����Ʈ�� ��ġ�մϴ�
		void AddGameObject(GameObject* go, eLayerType layer);
		// ���� ������Ʈ�� ����
		void EraseGameObject(GameObject* gameObj);
		// ���̾ ���մϴ�
		Layer* GetLayer(const eLayerType layer) { return mLayers[(UINT)layer]; }


	private:
		// ���̾ �����մϴ�
		void createLayers();

	private:
		std::vector<Layer*> mLayers; // ���� ��ġ�� ���̾��
	};
}


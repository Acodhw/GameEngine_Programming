#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"

namespace PracticeEngine {
	class GameObject;
	// ������Ʈ�� ������ ��� �Ӽ����� �����ϴ� Ŭ����
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// �ش� ������Ʈ�� Ư�� ������Ʈ���� �����մϴ�.
		void SetOwner(GameObject* owner) { mOwner = owner; };
		// ������Ʈ�� ������ �ִ� ������Ʈ�� �����ɴϴ�
		GameObject* GetOwner() { return mOwner; }
	private:
		GameObject* mOwner; // ������Ʈ�� ������ �ִ� ������Ʈ
	};
}


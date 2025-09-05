#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"

namespace PracticeEngine {
	class GameObject;
	// ������Ʈ�� ������ ��� �Ӽ����� �����ϴ� Ŭ����
	class Component : public Entity
	{
	public:
		Component(eComponentType ctype);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		// �ش� ������Ʈ�� Ư�� ������Ʈ���� �����մϴ�.
		void SetOwner(GameObject* owner) { mOwner = owner; };
		// ������Ʈ�� ������ �ִ� ������Ʈ�� �����ɴϴ�
		GameObject* GetOwner() const { return mOwner; }
		// ������Ʈ Ÿ���� �����ɴϴ�
		eComponentType GetType() const { return mC_Type; }
	private:
		GameObject* mOwner; // ������Ʈ�� ������ �ִ� ������Ʈ
		eComponentType mC_Type; // �ش� ������Ʈ�� Ÿ���Դϴ�.
	};
}


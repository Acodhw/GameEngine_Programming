#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine
{
	//���� �� ���� ������Ʈ�� ������ ��� Ŭ����
	class GameObject
	{
	public:
		enum eState {
			Active,
			Paused,
			Dead,
			End,
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// �ش� ������Ʈ�� ������Ʈ�� �߰��մϴ�
		template<typename T>
		T* AddComponent() { 
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			mComponents.push_back(comp);
			return comp;
		}

		// �ش� ������Ʈ�� ������ ������Ʈ ���ø����� �־��� ������Ʈ�� �޾ƿɴϴ�
		template <typename T>
		T* GetComponent() 
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		} 

		// ������Ʈ�� Ȱ�� ���¸� �����մϴ�
		void SetActive(bool power) {
			mState = power ? eState::Active : eState::Paused;
		}

		// ������Ʈ�� Ȱ�� ���¸� �����ɴϴ�
		const eState& state = mState;

		// ������Ʈ�� ���Դϴ�(��� �Ҵ����� �����)
		void Death() { mState = eState::Dead; }
	private:
		// ���� ������Ʈ�� �⺻ Transform ������Ʈ�� �����մϴ�
		void initializeTransform();
		

	private:
		eState mState; // ������Ʈ�� Ȱ�� ����
		std::vector<Component*> mComponents; //�� ���� ������Ʈ�� ������ �ִ� ������Ʈ ����Ʈ
	};
}
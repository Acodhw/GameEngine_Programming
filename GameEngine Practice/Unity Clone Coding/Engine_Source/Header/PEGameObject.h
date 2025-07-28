#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine
{
	//Actor : ���� �� ���� ������Ʈ�� ������ ��� Ŭ����
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		template<typename T>
		T* AddComponent() { 
			T* comp = new T();
			comp->SetOwner(this);
			mComponents.push_back(comp);
			return comp;
		}

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

	private:
		std::vector<Component*> mComponents; // ������Ʈ : ���� �Ӽ����� �θ�Ŭ����
	};
}
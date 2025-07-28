#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine
{
	//Actor : 게임 내 여러 오브젝트의 정보를 담는 클래스
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
		std::vector<Component*> mComponents; // 컴포넌트 : 하위 속성들의 부모클래스
	};
}
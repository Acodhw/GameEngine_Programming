#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine
{
	//게임 내 여러 오브젝트의 정보를 담는 클래스
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

		// 해당 오브젝트에 컴포넌트를 추가합니다
		template<typename T>
		T* AddComponent() { 
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			mComponents.push_back(comp);
			return comp;
		}

		// 해당 오브젝트가 가지는 컴포넌트 템플릿으로 주어진 컴포넌트를 받아옵니다
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

		// 오브젝트의 활성 상태를 지정합니다
		void SetActive(bool power) {
			mState = power ? eState::Active : eState::Paused;
		}

		// 오브젝트의 활성 상태를 가져옵니다
		const eState& state = mState;

		// 오브젝트를 죽입니다(사용 불능으로 만들기)
		void Death() { mState = eState::Dead; }
	private:
		// 게임 오브젝트의 기본 Transform 컴포넌트를 대입합니다
		void initializeTransform();
		

	private:
		eState mState; // 오브젝트의 활성 상태
		std::vector<Component*> mComponents; //이 게임 오브젝트가 가지고 있는 컴포넌트 리스트
	};
}
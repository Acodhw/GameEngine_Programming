#pragma once
#include "CommonInclude.h"
#include "PEEntity.h"

namespace PracticeEngine {
	class GameObject;
	// 오브젝트가 가지는 기능 속성들을 지정하는 클래스
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		// 해당 컴포넌트를 특정 오브젝트에게 대입합니다.
		void SetOwner(GameObject* owner) { mOwner = owner; };
		// 컴포넌트를 가지고 있는 오브젝트를 가져옵니다
		GameObject* GetOwner() { return mOwner; }
	private:
		GameObject* mOwner; // 컴포넌트를 가지고 있는 오브젝트
	};
}


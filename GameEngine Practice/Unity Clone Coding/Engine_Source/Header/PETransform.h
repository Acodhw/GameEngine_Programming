#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine {
	using namespace Math;
	// 오브젝트의 위치, 크기, 회전을 지정하는 컴포넌트
	class Transform : public Component
	{
	public :
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// 포지션을 지정합니다
		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		// 포지션을 가져옵니다
		Vector2 GetPosition() { return mPosition; }
	private:
		Vector2 mPosition;
	};
}


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
		void Render() override;

		// 포지션을 지정합니다
		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		// 회전을 지정합니다	
		void SetRot(float rot) { mRotation = rot; }
		// 크기를 지정합니다
		void SetScl(Vector2 scl) { mScale.x = scl.x; mScale.y = scl.y; }
		// 포지션을 가져옵니다
		Vector2 GetPosition() { return mPosition; }
		// 회전 정보를 가져옵니다
		float GetRotation() { return mRotation; }
		// 크기 정보를 가져옵니다
		Vector2 GetScale() { return mScale; }
	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}


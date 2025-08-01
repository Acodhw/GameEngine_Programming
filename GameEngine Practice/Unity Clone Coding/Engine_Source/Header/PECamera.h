#pragma once
#include "PEComponent.h"

namespace PracticeEngine {

	using namespace Math;

    class Camera : public Component
    {
	public:
		// 카메라 위치에 따른 위치를 지정합니다
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; }
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		// 카메라의 타겟을 정합니다
		void SetTarger(GameObject* g) { mTarget = g; }	
		const Vector2& Resolution = mResolution; // 카메라의 해상도
	private:
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;

		GameObject* mTarget;
    };
}

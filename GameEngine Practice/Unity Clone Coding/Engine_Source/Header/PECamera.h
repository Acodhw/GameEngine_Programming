#pragma once
#include "PEComponent.h"

namespace PracticeEngine {

	using namespace Math;

    class Camera : public Component
    {
	public:
		// ī�޶� ��ġ�� ���� ��ġ�� �����մϴ�
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; }
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		// ī�޶��� Ÿ���� ���մϴ�
		void SetTarger(GameObject* g) { mTarget = g; }	
		const Vector2& Resolution = mResolution; // ī�޶��� �ػ�
	private:
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;

		GameObject* mTarget;
    };
}

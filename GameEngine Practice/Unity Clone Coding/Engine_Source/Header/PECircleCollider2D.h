#pragma once
#include "PECollider.h"

namespace PracticeEngine {
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetRadius(float r) { mRadius = r; }
		const float& radius = mRadius;

	private:
		float mRadius;
	};
}


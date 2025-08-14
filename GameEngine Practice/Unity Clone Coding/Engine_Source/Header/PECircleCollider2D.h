#pragma once
#include "PECollider.h"

namespace PracticeEngine {
    class CircleCollider2D : public Collider
    {
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetRadius(float r) { mRadius = r; }
		const float& radius = mRadius;

	private:
		float mRadius;
    };
}


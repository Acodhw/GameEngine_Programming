#pragma once

namespace PracticeEngine {
	namespace Math {
		// X, Y로 이뤄진 벡터 정보를 담습니다
		struct Vector2 {
			float x;
			float y;

			Vector2()
				: x(0.0f)
				, y(0.0f)
			{

			}

			Vector2(float _x, float _y)
				: x(_x)
				, y(_y)
			{

			}
		};
	}
}
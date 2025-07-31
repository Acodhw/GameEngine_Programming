#pragma once

namespace PracticeEngine {
	namespace Math {
		// X, Y로 이뤄진 벡터 정보를 담습니다
		struct Vector2 {
			static Vector2 One; // 모든 방향이 1인 벡터
			static Vector2 Zero; // 모든 방향이 0인 벡터
			static Vector2 Left; // 왼쪽 방향 벡터
			static Vector2 Right; // 오른쪽 방향 벡터
			static Vector2 Up; // 위 방향 벡터
			static Vector2 Down; // 아래 방향 벡터

			float x;
			float y;

			Vector2()
				: x(0.0f)
				, y(0.0f)
			{}
			Vector2(float _x, float _y)
				: x(_x), y(_y)
			{}

			bool operator==(const Vector2& vec) {
				return(x == vec.x && y == vec.y);
			}
			Vector2& operator=(const Vector2& vec) {
				x = vec.x; y = vec.y;
				return *this;
			}
			Vector2 operator+(const Vector2& vec) {
				Vector2 tmp(x + vec.x, y + vec.y);
				return tmp;
			}
			Vector2 operator-(const Vector2& vec) {
				Vector2 tmp(x - vec.x, y - vec.y);
				return tmp;
			}
			Vector2 operator*(float n) {
				Vector2 tmp(x * n, y * n);
				return tmp;
			}
			Vector2 operator/(float n) {
				Vector2 tmp(x / n, y / n);
				return tmp;
			}

			Vector2& operator+=(const Vector2& vec) {
				(*this) = (*this) + vec;
				return (*this);
			}
			Vector2& operator-=(const Vector2& vec) {
				(*this) = (*this) - vec;
				return (*this);
			}
			Vector2& operator*=(float n) {
				(*this) = (*this) * n;
				return (*this);
			}
			Vector2& operator/=(float n) {
				(*this) = (*this) / n;
				return (*this);
			}
		};
		 
	}

}
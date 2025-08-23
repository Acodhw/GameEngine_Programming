#pragma once
#include <cmath>
#define PI 3.141592653589793238462643383279


namespace PracticeEngine::Math {
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
		{
		}
		Vector2(float _x, float _y)
			: x(_x), y(_y)
		{
		}

		bool operator==(const Vector2& vec) {
			return(x == vec.x && y == vec.y);
		}
		bool operator!=(const Vector2& vec) {
			return(x != vec.x || y != vec.y);
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
		Vector2 operator*(const Vector2& vec)
		{
			return Vector2(x * vec.x, y * vec.y);
		}
		Vector2 operator*(float n) {
			Vector2 tmp(x * n, y * n);
			return tmp;
		}
		Vector2 operator/(float n) {
			Vector2 tmp(x / n, y / n);
			return tmp;
		}

		Vector2 operator-() {
			return Vector2(-x, -y);
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
	
		// 벡터를 초기화합니다
		void Clear() { x = 0; y = 0; }
		// 벡터의 길이를 구합니다
		float Length() {
			return sqrtf(x * x + y * y);
		}
		// 벡터를 정규화시킵니다
		Vector2 Normalize() {
			float len = Length();
			x /= len;
			y /= len;
			return *this;
		}

		// 두 벡터의 내적을 구합니다
		static float Dot(Vector2& v1, Vector2& v2) {
			return v1.x * v2.x + v1.y * v2.y;
		}

		// 두 벡터의 외적의 크기를 구합니다
		static float Cross(Vector2& v1, Vector2& v2) {
			return v1.x * v2.y + v1.y * v2.x;
		}

		// 벡터를 회전시킵니다.
		static Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180.f) * PI;
			vector.Normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

			return Vector2(x, y);
		}
	};

	
}
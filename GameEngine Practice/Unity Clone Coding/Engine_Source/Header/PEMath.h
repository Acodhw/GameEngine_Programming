#pragma once
#include <cmath>
#define PI 3.141592653589793238462643383279


namespace PracticeEngine::Math {
	// X, Y�� �̷��� ���� ������ ����ϴ�
	struct Vector2 {
		static Vector2 One; // ��� ������ 1�� ����
		static Vector2 Zero; // ��� ������ 0�� ����
		static Vector2 Left; // ���� ���� ����
		static Vector2 Right; // ������ ���� ����
		static Vector2 Up; // �� ���� ����
		static Vector2 Down; // �Ʒ� ���� ����

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
	
		// ���͸� �ʱ�ȭ�մϴ�
		void Clear() { x = 0; y = 0; }
		// ������ ���̸� ���մϴ�
		float Length() {
			return sqrtf(x * x + y * y);
		}
		// ���͸� ����ȭ��ŵ�ϴ�
		Vector2 Normalize() {
			float len = Length();
			x /= len;
			y /= len;
			return *this;
		}

		// �� ������ ������ ���մϴ�
		static float Dot(Vector2& v1, Vector2& v2) {
			return v1.x * v2.x + v1.y * v2.y;
		}

		// �� ������ ������ ũ�⸦ ���մϴ�
		static float Cross(Vector2& v1, Vector2& v2) {
			return v1.x * v2.y + v1.y * v2.x;
		}

		// ���͸� ȸ����ŵ�ϴ�.
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
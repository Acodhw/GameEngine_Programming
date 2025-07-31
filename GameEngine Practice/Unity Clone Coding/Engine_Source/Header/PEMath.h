#pragma once

namespace PracticeEngine {
	namespace Math {
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
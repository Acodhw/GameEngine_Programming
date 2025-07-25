#pragma once
#include "CommonInclude.h"


namespace PracticeEngine
{
	enum class eKeyState {
		Down, 
		Pressed,
		Up,
		None
	}; // 키 활성화 상태를 열거형 저장

	enum class eKeyCode {
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	}; // 키 코드를 열거형 저장

	class Input
	{
	public:
		struct Key {
			eKeyState state; // 키 활성화 상태
			eKeyCode keyCode; // 키 코드
			bool bPressed; // 눌렸는지 확인
		}; // 현재 키 정보를 가지는 구조체의 정보를 제공

		static void Initailze();
		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; }
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; }

		//static : 한 번만 정의되며, 이후 여러 객체 정의에도 불구하고 공유됨

	private:
		static std::vector<Key> mKeys;
	};

}
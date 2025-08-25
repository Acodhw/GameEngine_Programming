#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	// 키 상태
	enum class eKeyState {
		Down, 
		Pressed,
		Up,
		None
	}; // 키 활성화 상태를 열거형 저장

	// 지정된 키
	enum class eKeyCode {
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		LButton, RButton, MButton,
		End,
	}; // 키 코드를 열거형 저장
	// 게임의 입력 상태를 지정하는 클래스
	class Input
	{
	public:
		// 키의 정보
		struct Key {
			eKeyState state; // 키 활성화 상태
			eKeyCode keyCode; // 키 코드
			bool bPressed; // 눌렸는지 확인
		}; // 현재 키 정보를 가지는 구조체의 정보를 제공

		static void Initailze();
		static void Update();

		// 키가 눌린 순간에 True를 리턴합니다
		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; }
		// 키가 떼진 순간에 True를 리턴합니다
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; }
		// 키가 눌리고 있으면 True를 리턴합니다
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; }
		// 마우스 포인터 위치 지정
		static Math::Vector2 GetMousePosition() { return mMousePosition; }


		//static : 한 번만 정의되며, 이후 여러 객체 정의에도 불구하고 공유됨
	private:
		// 키 생성
		static void createKeys();
		// 키 정보 업데이트
		static void updateKeys();
		// 키 정보 업데이트
		static void updateKey(Input::Key& key);
		// 키가 눌렸는지
		static bool isKeyDown(eKeyCode code);
		// 키 눌림 상태 업데이트
		static void updateKeyDown(Input::Key& key);
		// 키 떼진 상태 업데이트
		static void updateKeyUp(Input::Key& key);
		// 윈도우 내에서 마우스포인터 위치를 지정
		static void getMousePositionByWindow();
		// 키 초기화
		static void clearKeys();

	private:
		static std::vector<Key> mKeys; // 키의 정보
		static Math::Vector2 mMousePosition; // 마우스 포인터 위치
	};

}
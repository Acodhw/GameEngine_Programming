#include "PEInput.h"

namespace PracticeEngine
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailze()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed) mKeys[i].state = eKeyState::Pressed; // 이전에 눌려있었다 = 눌린 상태
				else mKeys[i].state = eKeyState::Down; // 이전에 안눌려있었다 = 누르고 있는 중
				mKeys[i].bPressed = true;
			}
			else {
				if (mKeys[i].bPressed) mKeys[i].state = eKeyState::Up; // 이전에 눌려 있었다 = 키를 빼는 상태
				else mKeys[i].state = eKeyState::None; // 이전에 안눌려있었다 = 안누르고 있음
				mKeys[i].bPressed = false;
			}
		}
	}
}
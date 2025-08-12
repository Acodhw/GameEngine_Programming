#include "PEInput.h"
#include "PETime.h"
#include "PEApplication.h"

extern PracticeEngine::Application application;

namespace PracticeEngine
{
	std::vector<Input::Key> Input::mKeys = {};
	Math::Vector2 Input::mMousePosition = Math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON
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
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}


	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHWND(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}
	void Input::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}
}
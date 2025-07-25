#include "PEGameObject.h"

namespace PracticeEngine
{
	GameObject::GameObject() : mx(0), my(0)
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update() {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mx -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mx += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			my -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			my += 0.01f;
		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {
		HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // 브러쉬 생성(어떤 브러쉬가 그림이 그려질지)
		HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc에게 브러쉬 대입 이후 오래된(이전에) 브러쉬 리턴


		Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my); // 사각형 그리는 함수

		(HBRUSH)SelectObject(hdc, oldbr); // 오래된 브러쉬로 돌려놓기
		DeleteObject(br); // 생성된 브러쉬를 제거

		// DC = 화면 출력에 필요한 모든 데이터를 가지는 구조체
		// GDI 모듈에 의해 관리
	}

}

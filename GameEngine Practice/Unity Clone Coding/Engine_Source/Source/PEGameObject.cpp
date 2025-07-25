#include "PEGameObject.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine
{
	GameObject::GameObject() : mx(0), my(0)
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update() {
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left)) {
			mx -= speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right)) {
			mx += speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up)) {
			my -= speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down)) {
			my += speed * Time::DeltaTime;
		} // 키 처리
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) { // 게임 오브젝트가 할당된 렌더링을 처리
		HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // 브러쉬 생성(어떤 브러쉬가 그림이 그려질지)
		HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc에게 브러쉬 대입 이후 오래된(이전에) 브러쉬 리턴


		Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my); // 사각형 그리는 함수

		(HBRUSH)SelectObject(hdc, oldbr); // 오래된 브러쉬로 돌려놓기
		DeleteObject(br); // 생성된 브러쉬를 제거

		// DC = 화면 출력에 필요한 모든 데이터를 가지는 구조체
		// GDI 모듈에 의해 관리
	}

}

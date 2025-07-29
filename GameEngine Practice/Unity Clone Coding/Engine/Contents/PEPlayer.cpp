#include "PEPlayer.h"
#include "PETransform.h"
#include "PEMath.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
		Math::Vector2 v = GetComponent<Transform>()->GetPosition();
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up)) {
			v.y -= Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down)) {
			v.y += Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left)) {
			v.x -= Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right)) {
			v.x += Speed * Time::DeltaTime;
		}
		GetComponent<Transform>()->SetPos(v);
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
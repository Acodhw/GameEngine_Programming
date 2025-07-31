#include "PEPlayerScript.h"
#include "PESpriteObj.h"
#include "PETransform.h"
#include "PEMath.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine {
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		Math::Vector2 v = GetOwner()->GetComponent<Transform>()->GetPosition();
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up)) {
			if (v.y >= 32) v.y -= Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down)) {
			if (v.y <= 1040 - 32)v.y += Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left)) {
			if (v.x >= 32)v.x -= Speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right)) {
			if (v.x <= 1500 - 32)v.x += Speed * Time::DeltaTime;
		}
		GetOwner()->GetComponent<Transform>()->SetPos(v);
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}
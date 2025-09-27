#include "PECameraScript.h"
#include "PECameraScript.h"
#include "PEInput.h"
#include "PETransform.h"
#include "PETime.h"
#include "PEGameObject.h"
#include "PEAnimator.h"
#include "PEObject.h"
#include "PEResources.h"

namespace PracticeEngine {
	CameraScript::CameraScript()
	{
	}

	CameraScript::~CameraScript()
	{
	}

	void CameraScript::Initialize()
	{
	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::A))
			pos += 20.0f * -tr->Right() * Time::DeltaTime;
		if (Input::GetKey(eKeyCode::W))
			pos += 20.0f * tr->Foward() * Time::DeltaTime;
		if (Input::GetKey(eKeyCode::D))
			pos += 20.0f * tr->Right() * Time::DeltaTime;
		if (Input::GetKey(eKeyCode::S))
			pos += 20.0f * -tr->Foward() * Time::DeltaTime;
		if (Input::GetKey(eKeyCode::E))
			pos += 20.0f * tr->Up() * Time::DeltaTime;
		if (Input::GetKey(eKeyCode::Q))
			pos += 20.0f * -tr->Up() * Time::DeltaTime;

		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{
	}

	void CameraScript::Render()
	{
	}
}
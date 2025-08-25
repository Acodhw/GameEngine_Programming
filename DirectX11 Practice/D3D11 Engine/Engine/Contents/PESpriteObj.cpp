#include "PESpriteObj.h"
#include "PETransform.h"
#include "PEMath.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine
{
	void SpriteObj::Initialize()
	{
		GameObject::Initialize();
	}

	void SpriteObj::Update()
	{
		GameObject::Update();
	}

	void SpriteObj::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void SpriteObj::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
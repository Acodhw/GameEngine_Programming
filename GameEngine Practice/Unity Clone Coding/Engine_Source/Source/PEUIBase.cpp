#include "PEUIBase.h"


namespace PracticeEngine {

	UIBase::UIBase(eUIType type)
		: mType(type)
		, mbMouseOn(false)		
	{
	}

	UIBase::~UIBase()
	{
	}

	void UIBase::Initialize()
	{
	}

	void UIBase::Active()
	{
	}

	void UIBase::InActive()
	{
	}

	void UIBase::Update()
	{
	}

	void UIBase::LateUpdate()
	{
	}

	void UIBase::Render()
	{
	}

	void UIBase::UIClear()
	{
	}

	void UIBase::OnInit()
	{
	}

	void UIBase::OnActive()
	{
	}

	void UIBase::OnInActive()
	{
	}

	void UIBase::OnUpdate()
	{
	}

	void UIBase::OnLateUpdate() {}
	void UIBase::OnRender() {}

	void UIBase::OnClear()
	{
	}
}
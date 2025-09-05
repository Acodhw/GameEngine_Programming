#include "PEUIHUD.h"
#include "PEResources.h"

namespace PracticeEngine {
	UIHUD::UIHUD()
		: UIBase(eUIType::Slider)
		, mTexture(nullptr)
	{
	}

	UIHUD::~UIHUD()
	{
	}

	void UIHUD::OnInit()
	{
		//mTexture = Resources::Find<Graphics::Texture>(L"HPBAR");
	}

	void UIHUD::OnActive()
	{
	}

	void UIHUD::OnInActive()
	{
	}

	void UIHUD::OnUpdate()
	{
	}

	void UIHUD::OnLateUpdate()
	{
	}

	void UIHUD::OnRender()
	{
		//TransparentBlt(hdc
		//	, 0, 0
		//	, mTexture->width
		//	, mTexture->height
		//	, mTexture->GetHdc()
		//	, 0, 0
		//	, mTexture->width / 2.0f
		//	, mTexture->height
		//	, RGB(255, 0, 255));
	}

	void UIHUD::OnClear()
	{
		//delete p;
	}
}
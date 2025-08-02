#pragma once
#include "PETexture.h"
#include "PEResources.h"

namespace PracticeEngine
{
	void LoadResources() {	
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<Graphics::Texture>(L"PL", L"..\\Resources\\Player_idle.png");
		Resources::Load<Graphics::Texture>(L"PL_S", L"..\\Resources\\Player_idle-Sheet.png");
		Resources::Load<Graphics::Texture>(L"PL_A", L"..\\Resources\\Player_idle-Sheet_Aplha.bmp");
	}
}
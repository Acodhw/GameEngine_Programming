#pragma once
#include "PETexture.h"
#include "PEResources.h"

namespace PracticeEngine
{
	void LoadResources() {	
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<Graphics::Texture>(L"PL", L"..\\Resources\\Player_idle.png");
	}
}
#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"
#include "PEConstantBuffer.h"


using namespace PracticeEngine::Math;
using namespace PracticeEngine::Graphics;

namespace PracticeEngine::Renderer {
	// 렌더 관련한 기능을 담음
	extern Camera* mainCamera; // 씬의 메인카메라를 지정합니다

	extern Graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	void Initialize();
	void Release();
}
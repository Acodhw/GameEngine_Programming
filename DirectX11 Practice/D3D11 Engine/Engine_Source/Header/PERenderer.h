#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"
#include "PEConstantBuffer.h"
#include "PERenderTarget.h"


using namespace PracticeEngine::Math;
using namespace PracticeEngine::Graphics;

namespace PracticeEngine::Renderer {
	// 렌더 관련한 기능을 담음
	extern Camera* mainCamera; // 씬의 메인카메라를 지정합니다
	extern GameObject* selectedObject;
	extern ConstantBuffer* constantBuffers[static_cast<UINT>(eCBType::End)];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[static_cast<UINT>(eSamplerType::End)];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[static_cast<UINT>(eRasterizerState::End)];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[static_cast<UINT>(eBlendState::End)];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[static_cast<UINT>(eDepthStencilState::End)];

	extern RenderTarget* FrameBuffer;

	void Initialize();
	void Release();
}
#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"
#include "PEResources.h"
#include "PEShader.h"
#include "PEVertexBuffer.h"
#include "PEIndexBuffer.h"
#include "PEConstantBuffer.h"


using namespace PracticeEngine::Math;
using namespace PracticeEngine::Graphics;

namespace PracticeEngine::Renderer {
	// 렌더 관련한 기능을 담음
	extern Camera* mainCamera; // 씬의 메인카메라를 지정합니다
	extern std::vector<Graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern Graphics::VertexBuffer vertexBuffer;
	extern Graphics::IndexBuffer indexBuffer;
	extern Graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}
#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"
#include "PEResources.h"
#include "PEShader.h"
#include "PEConstantBuffer.h"
#include "PEMesh.h"


using namespace PracticeEngine::Math;
using namespace PracticeEngine::Graphics;

namespace PracticeEngine::Renderer {
	// ���� ������ ����� ����
	extern Camera* mainCamera; // ���� ����ī�޶� �����մϴ�
	extern std::vector<Graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern Mesh* mesh;
	extern Graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}
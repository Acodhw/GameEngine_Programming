#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Renderer {
	// 렌더 관련한 기능을 담음
	extern Camera* mainCamera; // 씬의 메인카메라를 지정합니다

	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[3];
	extern std::vector<UINT> indices;

	extern ID3D11Buffer* vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3DBlob* vsBlob;
	extern ID3D11VertexShader* vsShader;

	extern ID3DBlob* psBlob;
	extern ID3D11PixelShader* psShader;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}
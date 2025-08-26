#pragma once
#include "PECamera.h"
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Renderer {
	// ���� ������ ����� ����
	extern Camera* mainCamera; // ���� ����ī�޶� �����մϴ�

	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[3];
	extern ID3D11Buffer* vertexBuffer;

	extern ID3DBlob* vsBlob;
	extern ID3D11VertexShader* vsShader;

	extern ID3DBlob* psBlob;
	extern ID3D11PixelShader* psShader;
	extern ID3D11InputLayout* inputLayouts;

}
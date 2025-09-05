#include "PERenderer.h"


namespace PracticeEngine::Renderer {
	Camera* mainCamera = nullptr;
	std::vector<Graphics::Vertex> vertexes = {};
	std::vector<UINT> indices;

	Graphics::VertexBuffer vertexBuffer;
	Graphics::IndexBuffer indexBuffer;
	Graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End] = {};

	ID3D11Buffer* constantBuffer = nullptr;
	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
		Renderer::vertexes.resize(3);
		Renderer::vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		Renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Renderer::vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		Renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		Renderer::vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		Renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
	}

	void LoadShaders()
	{
		PracticeEngine::Resources::Load<Graphics::Shader>(L"TriangleShader", L"..\\Shader_SOURCE\\Triangle");
	}

	void LoadConstantBuffers()
	{
		constantBuffers[(UINT)eCBType::Transform].Create(eCBType::Transform, sizeof(Vector4));

	}

	void Initialize()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}

	void Release()
	{
		inputLayouts->Release();
	}
}
#pragma once
#include "PEResource.h"
#include "PEVertexBuffer.h"
#include "PEIndexBuffer.h"
#include "PEInputLayout.h"

namespace PracticeEngine {
	class Mesh : public Resource
	{
	public:
		struct MeshData
		{
			MeshData();
			~MeshData();

			D3D11_PRIMITIVE_TOPOLOGY mTopology;
			std::vector<Graphics::Vertex> vertices;
			std::vector<UINT> indices;
		};

		Mesh();
		~Mesh();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;


		bool CreateVB(const std::vector<Graphics::Vertex>& vertices);
		bool CreateIB(const std::vector<UINT>& indices);
		void SetVertexBufferParams(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength);
		void Bind();

		UINT GetIndexCount() const { return mIB.GetIndexCount(); }

	private:
		Graphics::InputLayout mInputLayout;
		Graphics::VertexBuffer mVB;
		Graphics::IndexBuffer mIB;

		MeshData mData;
	};
}


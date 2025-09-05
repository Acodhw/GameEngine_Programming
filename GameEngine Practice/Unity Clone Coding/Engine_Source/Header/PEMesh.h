#pragma once
#include "PEResource.h"
#include "PEVertexBuffer.h"
#include "PEIndexBuffer.h"

namespace PracticeEngine {
	class Mesh : public Resource
	{
	public:
		struct Data
		{
			Data();
			~Data();

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
		void Bind();

	private:
		Graphics::VertexBuffer mVB;
		Graphics::IndexBuffer mIB;

		Data mData;
	};
}


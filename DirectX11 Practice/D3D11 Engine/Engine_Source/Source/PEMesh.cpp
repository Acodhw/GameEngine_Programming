#include "PEMesh.h"
namespace PracticeEngine {
	Mesh::Data::Data()
		: mTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
		, vertices{}
		, indices{}
	{

	}

	Mesh::Data::~Data()
	{
	}

	Mesh::Mesh()
		: Resource(eResourceType::Mesh)
	{

	}

	Mesh::~Mesh()
	{

	}

	HRESULT Mesh::Save(const std::wstring& path)
	{
		return S_OK;
	}

	HRESULT Mesh::Load(const std::wstring& path)
	{

		return S_OK;
	}

	bool Mesh::CreateVB(const std::vector<Graphics::Vertex>& vertices)
	{
		mData.vertices = vertices;
		return mVB.Create(vertices);
	}

	bool Mesh::CreateIB(const std::vector<UINT>& indices)
	{
		mData.indices = indices;
		return mIB.Create(indices);
	}

	void Mesh::Bind()
	{
		mVB.Bind();
		mIB.Bind();

		Graphics::GetDevice()->BindPrimitiveTopology(mData.mTopology);
	}
}
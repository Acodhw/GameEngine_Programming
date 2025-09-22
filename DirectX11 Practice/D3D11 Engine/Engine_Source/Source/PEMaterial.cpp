#include "PEMaterial.h"

namespace PracticeEngine {

	Material::Material()
		: Resource(eResourceType::Material)
		, mMode(Graphics::eRenderingMode::Opaque)
	{

	}

	Material::~Material()
	{
	}

	HRESULT Material::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Material::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Material::Bind()
	{
		//mTexture->Bind(eShaderStage::All, 0);
		if (mShader)
			mShader->Bind();

		if (mAlbedoTexture)
			mAlbedoTexture->Bind(Graphics::eShaderStage::PS, (UINT)Graphics::eTextureType::Albedo);
	}

	void Material::BindShader()
	{
		if (mShader)
			mShader->Bind();
	}

	void Material::BindTextures()
	{
		if (mAlbedoTexture)
			mAlbedoTexture->Bind(Graphics::eShaderStage::PS, (UINT)Graphics::eTextureType::Albedo);
	}
}
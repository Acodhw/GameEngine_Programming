#pragma once
#include "PEResource.h"
#include "PETexture.h"
#include "PEShader.h"

namespace PracticeEngine {
	class Material : public Resource
	{
	public:
		struct Data //Texture names
		{
			std::wstring albedo; //diffuse
		};

		Material();
		virtual ~Material();

		HRESULT Save(const std::wstring& path) override;
		HRESULT Load(const std::wstring& path) override;

		void Bind();
		void BindShader();
		void BindTextures();

		void SetShader(Graphics::Shader* shader) { mShader = shader; }

		void SetAlbedoTexture(Graphics::Texture* texture)
		{
			mAlbedoTexture = texture;
			mData.albedo = texture->GetName();
		}

	private:
		Graphics::eRenderingMode mMode;
		Data mData;

		Graphics::Texture* mAlbedoTexture;
		Graphics::Shader* mShader;
	};
}


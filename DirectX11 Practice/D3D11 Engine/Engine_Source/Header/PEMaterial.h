#pragma once
#include "PEResource.h"
#include "PETexture.h"
#include "PEShader.h"

namespace PracticeEngine {
	class Material : public Resource
	{
	public:
		struct Data
		{

			std::wstring albedo; //difuuse
		};

		Material();
		virtual ~Material();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind();
		void BindShader();
		void BindTextures();

		void SetShader(Graphics::Shader* shader) { mShader = shader; }

	private:
		Graphics::eRenderingMode mMode;
		Material::Data mData;

		Graphics::Texture* mAlbedoTexture;
		Graphics::Shader* mShader;
	};
}


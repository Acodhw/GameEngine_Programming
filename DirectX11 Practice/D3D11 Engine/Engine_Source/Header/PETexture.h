#pragma once
#include <DirectXTex.h>
#include <DirectXTex.inl>

#include "PEGraphicsDevice_DX11.h"
#include "PEResource.h"

namespace PracticeEngine::Graphics {

	// 텍스쳐 리소스 클래스
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind(eShaderStage stage, UINT startSlot);

		//std::wstring 

	private:
		ScratchImage mImage;

		D3D11_TEXTURE2D_DESC mDesc;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRTV;
	};

}

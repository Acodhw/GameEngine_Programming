#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#include "CommonInclude.h"

namespace PracticeEngine::Graphics {
	class GraphicsDevice_DX11
	{
	public:
		GraphicsDevice_DX11();
		~GraphicsDevice_DX11();

		void Initialize();
		void Draw();
	private:
		// 메모리 해제 자동으로 해주는 comptr
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice; // 물체 그리기 위해 필요한 데이터
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext; // 파이프라인
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mRenderTarget; // 텍스쳐 지정
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView; // 렌더링될 타겟 뷰
		Microsoft::WRL::ComPtr<ID3D11Texture2D>	mDepthStencil; // 깊이 버퍼
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView; // 깊이버퍼에 접근 가능하게 만드는 객체

		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain; // 전면/후면 버퍼 스왑을 해주는 객체
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplers; // 샘플러 = 자연스럽게 그려주는 녀석
	};
}

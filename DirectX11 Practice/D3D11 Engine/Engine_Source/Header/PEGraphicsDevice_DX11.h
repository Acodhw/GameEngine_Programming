#pragma once
#include "PEGraphics.h"

namespace PracticeEngine::Graphics {
	class GraphicsDevice_DX11
	{
	public:
		GraphicsDevice_DX11();
		~GraphicsDevice_DX11();

		bool  CreateDevice();
		bool  CreateSwapchain(DXGI_SWAP_CHAIN_DESC desc);
		bool  GetBuffer(UINT Buffer, REFIID riid, void** ppSurface);
		bool  CreateRenderTargetView(ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, ID3D11RenderTargetView** ppRTView);
		bool  CreateDepthStencilView(ID3D11Resource* pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D11DepthStencilView** ppDepthStencilView);
		bool  CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2D** ppTexture2D);
		bool  CreateVertexShader(const std::wstring& fileName, ID3DBlob** ppCode, ID3D11VertexShader** ppVertexShader);
		bool  CreatePixelShader(const std::wstring& fileName, ID3DBlob** ppCode, ID3D11PixelShader** ppPixelShader);
		bool  CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements
			, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout** ppInputLayout);
		bool CreateBuffer(const D3D11_BUFFER_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Buffer** ppBuffer);
		void SetDataBuffer(ID3D11Buffer* buffer, void* data, UINT size);
		
		void BindPrimitiveTopology(const D3D11_PRIMITIVE_TOPOLOGY topology);
		void BindVS(ID3D11VertexShader* pVertexShader);
		void BindPS(ID3D11PixelShader* pPixelShader);
		void BindVertexBuffer(UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppVertexBuffers, const UINT* pStrides, const UINT* pOffsets);
		void BindIndexBuffer(ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, UINT Offset);
		void BindConstantBuffer(eShaderStage stage, eCBType type, ID3D11Buffer* buffer);

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

	inline GraphicsDevice_DX11*& GetDevice()
	{
		static GraphicsDevice_DX11* device = nullptr;
		return device;
	}
}

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
		// �޸� ���� �ڵ����� ���ִ� comptr
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice; // ��ü �׸��� ���� �ʿ��� ������
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext; // ����������
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mRenderTarget; // �ؽ��� ����
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView; // �������� Ÿ�� ��
		Microsoft::WRL::ComPtr<ID3D11Texture2D>	mDepthStencil; // ���� ����
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView; // ���̹��ۿ� ���� �����ϰ� ����� ��ü

		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain; // ����/�ĸ� ���� ������ ���ִ� ��ü
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplers; // ���÷� = �ڿ������� �׷��ִ� �༮
	};
}

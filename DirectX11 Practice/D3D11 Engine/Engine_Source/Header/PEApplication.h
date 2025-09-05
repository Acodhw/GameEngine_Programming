#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine {
	// ���ø����̼� �⺻ Ŭ����
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwmd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

		void Release();

		void Destroy();

		// �ڵ��� �����ɴϴ�
		HWND GetHWND() const { return mHwmd; }
		// HDC�� �����ɴϴ�
		HDC GetHDC() const { return mHdc; }
		// �ػ󵵸� �����ɴϴ�
		Math::Vector2 GetResolution() const { return Math::Vector2(mWidth, mHeight); }


	private:
		void infoTitle(); // Ÿ��Ʋ�� ���� ǥ��
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();
	private:

		std::unique_ptr<Graphics::GraphicsDevice_DX11> mGraphicDevice; // �׷��� ����̽�

		HWND mHwmd; // �ɹ� ���� �ڵ�
		HDC mHdc; // hdc ������

		HDC mBackHDC; // �ĸ� ���ۿ� ������ HDC
		HBITMAP mBackBuffer; // �׸� �׸� ����

		UINT mWidth;
		UINT mHeight;

		wchar_t* title; // Ÿ��Ʋ ����
		
		//std::vector<Scene*> mScene;
	};
}


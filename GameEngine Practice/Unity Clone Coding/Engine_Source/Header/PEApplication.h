#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"

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

		// HDC�� �����ɴϴ�
		HDC GetHDC() { return mHdc; }
		// �ػ󵵸� �����ɴϴ�
		Math::Vector2 GetResolution() { return Math::Vector2(mWidth, mHeight); }

	private:
		void infoTitle(); // Ÿ��Ʋ�� ���� ǥ��

	private:
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


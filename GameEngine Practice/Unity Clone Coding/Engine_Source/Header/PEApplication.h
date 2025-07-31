#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	// 애플리케이션 기본 클래스
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

		// HDC를 가져옵니다
		HDC GetHDC() { return mHdc; }
		// 해상도를 가져옵니다
		Math::Vector2 GetResolution() { return Math::Vector2(mWidth, mHeight); }

	private:
		void infoTitle(); // 타이틀에 인포 표시

	private:
		HWND mHwmd; // 맴버 변수 핸들
		HDC mHdc; // hdc 가져옴

		HDC mBackHDC; // 후면 버퍼에 적용할 HDC
		HBITMAP mBackBuffer; // 그림 그릴 버퍼

		UINT mWidth;
		UINT mHeight;

		wchar_t* title; // 타이틀 저장
		
		//std::vector<Scene*> mScene;
	};
}


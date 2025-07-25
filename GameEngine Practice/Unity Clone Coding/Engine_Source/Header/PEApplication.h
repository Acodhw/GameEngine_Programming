#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwmd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();
		void InfoTitle(); // 타이틀에 인포 표시

	private:
		HWND mHwmd; // 맴버 변수 핸들
		HDC mHdc; // hdc 가져옴

		// 플레이어
		GameObject mPlayer; // 게임오브젝트 연동
		wchar_t * title; // 타이틀 저장
	};
}


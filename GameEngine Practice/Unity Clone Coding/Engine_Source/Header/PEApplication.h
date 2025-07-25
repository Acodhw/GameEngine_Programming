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

	private:
		HWND mHwmd; // 맴버 변수 핸들
		HDC mHdc; // hdc 가져옴

		// 플레이어
		GameObject mPlayer; // 게임오브젝트 연동
	};
}


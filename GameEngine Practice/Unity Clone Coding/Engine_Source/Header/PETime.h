#pragma once
#include "CommonInclude.h"

namespace PracticeEngine {
	// 게임의 시간 정보를 체크하는 클래스
	class Time
	{
	public:
		static void Initailze();
		static void Update();
		static void Render(HWND hwmd);

		static const float& DeltaTime; // 1프레임당 변하는 시간

	private:
		static LARGE_INTEGER cpuFrequency; //cpu 고유진동수 
		static LARGE_INTEGER prevFrequency; //진동수 변경을 체크하기 위한 진동수
		static LARGE_INTEGER currentFrequency; // 프로그램 시작시 현재 진동수
		static float deltaTime; // 실제 시간 변화율
	};
}


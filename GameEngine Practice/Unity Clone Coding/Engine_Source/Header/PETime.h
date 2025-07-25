#pragma once
#include "CommonInclude.h"

namespace PracticeEngine {

	class Time
	{
	public:
		static void Initailze();
		static void Update();
		static void Render(HWND hwmd);

		static const float& DeltaTime;

	private:
		static LARGE_INTEGER cpuFrequency; //cpu 고유진동수 
		static LARGE_INTEGER prevFrequency; //진동수 변경을 체크하기 위한 진동수
		static LARGE_INTEGER currentFrequency; // 프로그램 시작시 현재 진동수
		static float deltaTime; // 실제 시간 변화율
	};
}


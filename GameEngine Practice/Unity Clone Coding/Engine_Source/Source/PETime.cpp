#include "PETime.h"

namespace PracticeEngine {
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTime = 0.0f;
	const float& Time::DeltaTime = deltaTime;

	void Time::Initailze() {
		// Cpu 고유진동수
		QueryPerformanceFrequency(&cpuFrequency);
		// 프로그램 시작시 현재 진동수
		QueryPerformanceCounter(&prevFrequency);

	}
	void Time::Update() {
		// Cpu 고유진동수
		QueryPerformanceCounter(&currentFrequency);
		//static cast : 타입 변환에 대한 오류를 잡아주는 C++의 함수
		float differenceFrequency = static_cast<float>(currentFrequency.QuadPart - prevFrequency.QuadPart);
		deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);
		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
}
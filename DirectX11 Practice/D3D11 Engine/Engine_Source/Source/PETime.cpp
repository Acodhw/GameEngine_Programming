#include "PETime.h"
#include <WinUser.h>

namespace PracticeEngine {
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTime = 0.0f;
	const float& Time::DeltaTime = deltaTime;

	void Time::Initailze() {
		// Cpu ����������
		QueryPerformanceFrequency(&cpuFrequency);
		// ���α׷� ���۽� ���� ������
		QueryPerformanceCounter(&prevFrequency);

	}
	void Time::Update() {
		// Cpu ����������
		QueryPerformanceCounter(&currentFrequency);
		//static cast : Ÿ�� ��ȯ�� ���� ������ ����ִ� C++�� �Լ�
		float differenceFrequency = static_cast<float>(currentFrequency.QuadPart - prevFrequency.QuadPart);
		deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);
		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
}
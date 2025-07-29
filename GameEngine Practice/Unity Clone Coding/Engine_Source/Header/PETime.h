#pragma once
#include "CommonInclude.h"

namespace PracticeEngine {
	// ������ �ð� ������ üũ�ϴ� Ŭ����
	class Time
	{
	public:
		static void Initailze();
		static void Update();
		static void Render(HWND hwmd);

		static const float& DeltaTime; // 1�����Ӵ� ���ϴ� �ð�

	private:
		static LARGE_INTEGER cpuFrequency; //cpu ���������� 
		static LARGE_INTEGER prevFrequency; //������ ������ üũ�ϱ� ���� ������
		static LARGE_INTEGER currentFrequency; // ���α׷� ���۽� ���� ������
		static float deltaTime; // ���� �ð� ��ȭ��
	};
}


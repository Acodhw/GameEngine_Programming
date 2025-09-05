#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	// �ε����� �������� ���� ��
	class DontDestroyOnLoad :public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//���� �۵��� �� ����Ǵ� �Լ�
		virtual void OnEnter();
		//������ ������ ���� ����Ǵ� �Լ�
		virtual void OnExit();
	private:

	};
}


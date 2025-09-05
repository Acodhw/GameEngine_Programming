#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	// 로딩에도 지워지지 않은 씬
	class DontDestroyOnLoad :public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//씬이 작동될 때 실행되는 함수
		virtual void OnEnter();
		//씬에서 나가는 순간 실행되는 함수
		virtual void OnExit();
	private:

	};
}


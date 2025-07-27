#pragma once
#include "..\\PracticeEngine_SOURCE\\PEScene.h"
#include "..\\PracticeEngine_SOURCE\\CommonInclude.h"

namespace PracticeEngine {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}


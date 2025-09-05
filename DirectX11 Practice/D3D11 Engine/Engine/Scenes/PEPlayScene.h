#pragma once
#include "PEScene.h"
#include "CommonInclude.h"

namespace PracticeEngine {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;
	private:

	};
}


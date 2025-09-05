#pragma once
#include "PEScene.h"
#include "CommonInclude.h"

namespace PracticeEngine {
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;
	private:

	};
}


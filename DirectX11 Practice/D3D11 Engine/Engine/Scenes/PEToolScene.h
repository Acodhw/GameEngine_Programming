#pragma once
#include "PEScene.h"
#include "PETile.h"

namespace PracticeEngine {
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;
		void Save();
		void Load();

	private:
		std::vector<Tile*> mTiles;
	};
}


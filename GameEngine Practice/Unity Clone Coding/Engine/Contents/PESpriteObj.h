#pragma once
#include"PEGameObject.h"

namespace PracticeEngine {

	class SpriteObj : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}


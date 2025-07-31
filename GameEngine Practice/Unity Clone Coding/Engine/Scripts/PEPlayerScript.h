#pragma once
#include "PEScript.h"

namespace PracticeEngine {
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		int Speed = 150;
	};
}


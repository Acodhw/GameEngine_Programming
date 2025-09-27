#pragma once
#include "PEScript.h"
#include "PETransform.h"

namespace PracticeEngine {
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}


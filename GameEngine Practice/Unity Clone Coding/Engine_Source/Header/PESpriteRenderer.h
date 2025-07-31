#pragma once
#include "CommonInclude.h"
#include "PETexture.h"
#include "PEComponent.h"

namespace PracticeEngine {
	// 스프라이트(이미지)를 그리는 컴포넌트
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(Graphics::Texture* tx) { mTexture = tx; }

	private:
		Graphics::Texture* mTexture;
	};
}


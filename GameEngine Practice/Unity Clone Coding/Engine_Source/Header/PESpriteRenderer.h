#pragma once
#include "CommonInclude.h"
#include "PETexture.h"
#include "PEComponent.h"

namespace PracticeEngine {
	// ��������Ʈ(�̹���)�� �׸��� ������Ʈ
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


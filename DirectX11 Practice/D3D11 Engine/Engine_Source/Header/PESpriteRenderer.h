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

		// �ؽ��ĸ� �����մϴ�
		void SetTexture(Graphics::Texture* tx) { mTexture = tx; }
		// �̹��� ũ�⸦ �����մϴ�
		void SetSize(Math::Vector2 size) { mSize = size; }
	private:
		Graphics::Texture* mTexture;
		Math::Vector2 mSize;
	};
}


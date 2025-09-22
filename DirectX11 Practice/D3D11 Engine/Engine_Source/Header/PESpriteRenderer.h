#pragma once
#include "CommonInclude.h"
#include "PETexture.h"
#include "PEComponent.h"
#include "PEMaterial.h"
#include "PEMesh.h"

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
		void Render() override;

		void SetSprite(Graphics::Texture* sprite) { mSprite = sprite; }
		void SetMaterial(Material* material) { mMaterial = material; }

	private:
		Graphics::Texture* mSprite;
		Material* mMaterial;
		Mesh* mMesh;
	};
}


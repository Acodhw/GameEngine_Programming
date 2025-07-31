#include "PESpriteRenderer.h"
#include "PETransform.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	SpriteRenderer::SpriteRenderer()
		: mTexture(nullptr)

	{}
	SpriteRenderer::~SpriteRenderer(){}

	void SpriteRenderer::Initialize() {}
	void SpriteRenderer::Update() {}
	void SpriteRenderer::LateUpdate() {}
	void SpriteRenderer::Render(HDC hdc) {

		if (mTexture == nullptr) {
			MessageBox(nullptr, L"Texture Loading Error!\nTexture is Empty!", L"Error!", MB_OK);
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		switch (mTexture->GetTextureType())
		{
		case Graphics::Texture::eTextureType::BMP:
			TransparentBlt(hdc, pos.x, pos.y, mTexture->width, mTexture->height,
				mTexture->GetHdc(), 0, 0, mTexture->width, mTexture->height, RGB(255, 255, 255));
			break;
		case Graphics::Texture::eTextureType::PNG:			
			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, mTexture->width, mTexture->height));
			break;
		default:
			break;
		}


	}

	
}


#include "PESpriteRenderer.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PERenderer.h"
#include "PECamera.h"

namespace PracticeEngine {
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		,mTexture(nullptr)
		, mSize(Vector2::One)
	{}
	SpriteRenderer::~SpriteRenderer(){}

	void SpriteRenderer::Initialize() {}
	void SpriteRenderer::Update() {}
	void SpriteRenderer::LateUpdate() {}
	void SpriteRenderer::Render(HDC hdc) {

		if (mTexture == nullptr) {
			MessageBoxW(nullptr, L"Texture Loading Error!\nTexture is Empty!", L"Error!", MB_OK);
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scl = tr->GetScale();
		float rot = tr->GetRotation();
		pos = Renderer::mainCamera->CaluatePosition(pos);

		Gdiplus::Graphics graphcis(hdc);
		switch (mTexture->GetTextureType())
		{
		case Graphics::Texture::eTextureType::BMP:
			TransparentBlt(hdc,
				pos.x - mTexture->width / 2, pos.y - mTexture->height / 2,
				mTexture->width * scl.x, mTexture->height * scl.y,
				mTexture->GetHdc(), 0, 0, mTexture->width, mTexture->height, RGB(255, 255, 255));
			break;
		case Graphics::Texture::eTextureType::PNG:
			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x - mTexture->width / 2, pos.y - mTexture->height / 2,
					mTexture->width * scl.x * scl.y, mTexture->height));
			break;
		default:
			break;
		}


	}

	
}


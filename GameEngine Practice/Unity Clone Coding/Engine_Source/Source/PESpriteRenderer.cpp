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
			MessageBox(nullptr, L"Texture Loading Error!\nTexture is Empty!", L"Error!", MB_OK);
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
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, mTexture->width * mSize.x * scl.x
					, mTexture->height * mSize.y * scl.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->width
					, mTexture->height
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x, pos.y
					, mTexture->width * mSize.x * scl.x
					, mTexture->height * mSize.y * scl.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->width
					, mTexture->height
					, RGB(255, 0, 255));
			}
			break;
		case Graphics::Texture::eTextureType::PNG:
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);

			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					, mTexture->width * mSize.x * scl.x
					, mTexture->height * mSize.y * scl.y
				)
				, 0, 0
				, mTexture->width, mTexture->height
				, Gdiplus::UnitPixel
				, nullptr);
			break;
		}
	}

	
}


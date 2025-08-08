#include "PEAnimation.h"
#include "PETime.h"
#include "PEAnimator.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PERenderer.h"
#include "PETexture.h"


namespace PracticeEngine {
	Animation::Animation()
		:Resource(eResourceType::Animaiton)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete) return;

		mTime += Time::DeltaTime;
		if (mAnimationSheet[mIndex].duration < mTime) {
			mTime = 0;
			if (mIndex < mAnimationSheet.size() - 1) mIndex++;
			else mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc) 
	{
		// 알파블랜드 조건 : 해당 이미지에 알파채널(RGBA로 이루워진 이미지)여야한다(jpg같은거 안됨)
		if (mTexture == nullptr)
			return;

		GameObject* g =	mAnimator->GetOwner();
		Transform* tr = g->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scl = tr->GetScale();
		float rot = tr->GetRotation();

		if (Renderer::mainCamera) pos = Renderer::mainCamera->CaluatePosition(pos);

		Graphics::Texture::eTextureType type = mTexture->GetTextureType();

		Sprite spr = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		if (mTexture->GetTextureType() == Graphics::Texture::eTextureType::BMP)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 100;

			AlphaBlend(hdc,
				pos.x - (spr.size.x * scl.x * spr.offset.x),
				pos.y - (spr.size.y * scl.y * spr.offset.y),
				spr.size.x * scl.x,
				spr.size.y * scl.y,
				imgHdc,
				spr.leftTop.x,
				spr.leftTop.y,
				spr.size.x,
				spr.size.y,
				func);
		}

		else if (mTexture->GetTextureType() == Graphics::Texture::eTextureType::PNG)
		{
			Gdiplus::ImageAttributes imgAtt = {};

			imgAtt.SetColorKey(Gdiplus::Color(255, 255, 255), Gdiplus::Color(100, 100, 100));
			
			Gdiplus::Graphics graphcis(hdc);

			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);

			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x - (spr.size.x * scl.x * spr.offset.x),
					pos.y - (spr.size.y * scl.y * spr.offset.y),
					spr.size.x * scl.x,
					spr.size.y * scl.y),
					spr.leftTop.x,
					spr.leftTop.y,
					spr.size.x,
					spr.size.y,
					Gdiplus::Unit::UnitPixel,
					&imgAtt);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name,
		Graphics::Texture* spriteTexture,
		Vector2 leftTop,
		Vector2 size,
		Vector2 offset,
		UINT spriteLength,
		float duration)
	{
		mTexture = spriteTexture;
		int w = spriteTexture->width;
		for (size_t i = 0; i < spriteLength; i++) {
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + ((int)(size.x * i) % w);
			sprite.leftTop.y = leftTop.y + ((int)(size.x * i) / w) * size.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset() 
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}
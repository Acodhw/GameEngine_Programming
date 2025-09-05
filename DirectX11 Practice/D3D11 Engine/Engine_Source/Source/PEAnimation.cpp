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

	void Animation::Render() 
	{
		if (mTexture == nullptr)
			return;
	}

	void Animation::CreateAnimation(const std::wstring& name,
		Graphics::Texture* spriteTexture,
		Vector2 leftTop,
		Vector2 size,
		Vector2 offset,
		UINT spriteLength,
		float duration)
	{
		SetName(name);
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
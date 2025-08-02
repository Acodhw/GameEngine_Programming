#include "PEAnimator.h"


namespace PracticeEngine {
    Animator::Animator()
        : Component(eComponentType::Animator)
        , mAnimations{}
        , mActiveAnimation(nullptr)
        , mbLoop(false)
    {
    }
    Animator::~Animator()
    {
    }
    void Animator::Initialize()
    {
    }
    void Animator::Update()
    {
        if (mActiveAnimation) {
            mActiveAnimation->Update();
            if (mActiveAnimation->IsComplete() && mbLoop) {

                mActiveAnimation->Reset();
            }

        }
    }
    void Animator::LateUpdate()
    {
    }
    void Animator::Render(HDC hdc)
    {
        if (mActiveAnimation)
            mActiveAnimation->Render(hdc);
    }

    void Animator::CreateAnimation(const std::wstring& name,
        Graphics::Texture* spriteTexture, 
        Vector2 leftTop, 
        Vector2 size, 
        Vector2 offset, 
        UINT spriteLength, float duration)
    {
        Animation* anim = nullptr;
        if ((anim = FindAnimation(name)) != nullptr) return;

        anim = new Animation();
        anim->CreateAnimation(name, spriteTexture, leftTop, size, offset, spriteLength, duration);

        anim->SetAnimator(this);
        mAnimations.insert(std::make_pair(name, anim));

    }
    Animation* Animator::FindAnimation(const std::wstring& name)
    {
        auto iter = mAnimations.find(name);
        if (iter == mAnimations.end())
            return nullptr;
       
        return iter->second;
    }

    void Animator::PlayAnimation(const std::wstring& name, bool loop)
    {
        Animation* anim = FindAnimation(name);
        if (anim == nullptr) return;

        mActiveAnimation = anim;
        mActiveAnimation->Reset();
        mbLoop = loop;
    }
}
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

            Events* events = FindEvents(mActiveAnimation->GetName());

            if (mActiveAnimation->IsComplete()) {
                if(events != nullptr) events->CompleteEvent();
                if(mbLoop)
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

        Events* currentEvents = FindEvents(mActiveAnimation->GetName());
        if(currentEvents != nullptr) currentEvents->EndEvent();

        Events* nextEvents = FindEvents(anim->GetName());
        if (nextEvents != nullptr) nextEvents->StartEvent();

        mActiveAnimation = anim;
        mActiveAnimation->Reset();
        mbLoop = loop;
    }

    Animator::Events* Animator::FindEvents(const std::wstring& name)
    {
        auto iter = mEvents.find(name);
        if (iter == mEvents.end())
            return nullptr;

        return iter->second;
    }

    std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
    {
        // TODO: 여기에 return 문을 삽입합니다.
        Events* events = FindEvents(name);
        return events->StartEvent.mEvent;
    }

    std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
    {
        // TODO: 여기에 return 문을 삽입합니다.
        Events* events = FindEvents(name);
        return events->CompleteEvent.mEvent;
    }

    std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
    {
        // TODO: 여기에 return 문을 삽입합니다.
        Events* events = FindEvents(name);
        return events->EndEvent.mEvent;
    }

}
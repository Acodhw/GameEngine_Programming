#include "PEAnimator.h"
#include "PEResources.h"
#include "PETexture.h"

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
    void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
    {
        Animation* anim = nullptr;
        if ((anim = FindAnimation(name)) != nullptr) return;

        int fileCount = 0;
        std::filesystem::path fs(path);
        std::vector<Graphics::Texture*> images = {};

        for (auto& p : std::filesystem::recursive_directory_iterator(fs))
        {
            std::wstring fileName = p.path().filename();
            std::wstring fullName = p.path();

            Graphics::Texture* texture = Resources::Load<Graphics::Texture>(fileName, fullName);
            images.push_back(texture);
            fileCount++;
        }

        UINT sheetWidth = images[0]->width * fileCount;
        UINT sheetHeight = images[0]->height;
        Graphics::Texture* spriteSheet = Graphics::Texture::Create(name, sheetWidth, sheetHeight);

        UINT imageWidth = images[0]->width;
        UINT imageHeight = images[0]->height;
        for (size_t i = 0; i < images.size(); i++)
        {
            BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
                , imageWidth, imageHeight
                , images[i]->GetHdc(), 0, 0, SRCCOPY);
        }

        CreateAnimation(name, spriteSheet
            , Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
            , offset, fileCount, duration);
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
#pragma once
#include "PEResource.h"
#include "PETexture.h"

namespace PracticeEngine {
    // 애니메이션을 지정하는 리소스
    class Animation : public Resource
    {
    public:
        // 텍스쳐 속에 스프라이트 요소
        struct Sprite {
            Vector2 leftTop;
            Vector2 size;
            Vector2 offset;
            float duration;

            Sprite()
                : leftTop(Vector2::Zero)
                , size(Vector2::Zero)
                , offset(Vector2::Zero)
                , duration(0)
            { }
        };
        
        Animation();
        ~Animation();

        HRESULT Load(const std::wstring& path) override;

        void Update();
        void Render();

        // 애니메이션 클립을 지정합니다
        void CreateAnimation(const std::wstring& name,
            Graphics::Texture* spriteTexture,
            Vector2 leftTop,
            Vector2 size,
            Vector2 offset,
            UINT spriteLength,
            float duration);

        // 애니메이션을 리셋합니다
        void Reset();
        // 애니메이션이 끝났는지 확인합니다
        bool IsComplete() const { return mbComplete; }
        // 애니메이터에 애니메이션을 지정합니다
        void SetAnimator(class Animator* animator) { mAnimator = animator; }

    private:
        class Animator* mAnimator;
        Graphics::Texture* mTexture;

        std::vector<Sprite> mAnimationSheet;
        int mIndex;
        float mTime;
        bool mbComplete;
    };
}


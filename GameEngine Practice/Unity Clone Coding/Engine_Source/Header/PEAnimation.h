#pragma once
#include "PEResource.h"
#include "PETexture.h"

namespace PracticeEngine {
    class Animation : public Resource
    {
    public:
        // �ؽ��� �ӿ� ��������Ʈ ���
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
        void Render(HDC hdc);

        // �ִϸ��̼� Ŭ���� �����մϴ�
        void CreateAnimation(const std::wstring& name,
            Graphics::Texture* spriteTexture,
            Vector2 leftTop,
            Vector2 size,
            Vector2 offset,
            UINT spriteLength,
            float duration);

        // �ִϸ��̼��� �����մϴ�
        void Reset();
        // �ִϸ��̼��� �������� Ȯ���մϴ�
        bool IsComplete() { return mbComplete; }
        // �ִϸ����Ϳ� �ִϸ��̼��� �����մϴ�
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


#pragma once
#include "PEComponent.h"
#include "PEAnimation.h"

namespace PracticeEngine{
	

	class Animator : public Component
	{
	public :
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// 애니메이터에 애니메이터를 추가합니다
		void CreateAnimation(const std::wstring& name,
			Graphics::Texture* spriteTexture,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		// 애니메이션 목록에서 애니메이션을 찾습니다
		Animation* FindAnimation(const std::wstring& name);

		// 애니메이션을 재생합니다
		void PlayAnimation(const std::wstring& name, bool loop = true);



	private :
		std::map<std::wstring, Animation*> mAnimations; // 현재 애니메이터에 들어간 목록입니다
		Animation* mActiveAnimation; // 현재 재생중인 애니메이션입니다
		bool mbLoop; // 현재 애니메이션이 루프하는지 여부입니다
	};
}


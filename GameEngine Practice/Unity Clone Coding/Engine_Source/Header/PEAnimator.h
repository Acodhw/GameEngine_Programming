#pragma once
#include "PEComponent.h"
#include "PEAnimation.h"

namespace PracticeEngine{
	

	class Animator : public Component
	{
	public :
		//Event 구조체
		struct Event {

			void operator=(std::function<void()> func) {
				mEvent = func;
			}

			void operator()() {
				if (mEvent) mEvent;
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event StartEvent;
			Event CompleteEvent;
			Event EndEvent;
		};

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

		// 이벤트를 찾습니다
		Events* FindEvents(const std::wstring& name);
		// 애니메이션 시작 이벤트를 가져옵니다
		std::function<void()>& GetStartEvent(const std::wstring& name);
		// 애니메이션 완료 이벤트를 가져옵니다
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		// 트랙에서 제거될 때 이벤트를 가져옵니다
		std::function<void()>& GetEndEvent(const std::wstring& name);

		// 이 애니메이션 이벤트가 완료되었는지
		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private :
		std::map<std::wstring, Animation*> mAnimations; // 현재 애니메이터에 들어간 목록입니다
		Animation* mActiveAnimation; // 현재 재생중인 애니메이션입니다
		bool mbLoop; // 현재 애니메이션이 루프하는지 여부입니다

		// 애니메이션 이벤트들
		std::map<std::wstring, Events*> mEvents;
	};
}


#pragma once
#include "PEComponent.h"
#include "PEAnimation.h"

namespace PracticeEngine{
	

	class Animator : public Component
	{
	public :
		//Event ����ü
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

		// �ִϸ����Ϳ� �ִϸ����͸� �߰��մϴ�
		void CreateAnimation(const std::wstring& name,
			Graphics::Texture* spriteTexture,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		// �ִϸ��̼� ��Ͽ��� �ִϸ��̼��� ã���ϴ�
		Animation* FindAnimation(const std::wstring& name);

		// �ִϸ��̼��� ����մϴ�
		void PlayAnimation(const std::wstring& name, bool loop = true);

		// �̺�Ʈ�� ã���ϴ�
		Events* FindEvents(const std::wstring& name);
		// �ִϸ��̼� ���� �̺�Ʈ�� �����ɴϴ�
		std::function<void()>& GetStartEvent(const std::wstring& name);
		// �ִϸ��̼� �Ϸ� �̺�Ʈ�� �����ɴϴ�
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		// Ʈ������ ���ŵ� �� �̺�Ʈ�� �����ɴϴ�
		std::function<void()>& GetEndEvent(const std::wstring& name);

		// �� �ִϸ��̼� �̺�Ʈ�� �Ϸ�Ǿ�����
		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private :
		std::map<std::wstring, Animation*> mAnimations; // ���� �ִϸ����Ϳ� �� ����Դϴ�
		Animation* mActiveAnimation; // ���� ������� �ִϸ��̼��Դϴ�
		bool mbLoop; // ���� �ִϸ��̼��� �����ϴ��� �����Դϴ�

		// �ִϸ��̼� �̺�Ʈ��
		std::map<std::wstring, Events*> mEvents;
	};
}


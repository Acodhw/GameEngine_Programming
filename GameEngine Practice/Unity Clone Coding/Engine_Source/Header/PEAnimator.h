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



	private :
		std::map<std::wstring, Animation*> mAnimations; // ���� �ִϸ����Ϳ� �� ����Դϴ�
		Animation* mActiveAnimation; // ���� ������� �ִϸ��̼��Դϴ�
		bool mbLoop; // ���� �ִϸ��̼��� �����ϴ��� �����Դϴ�
	};
}


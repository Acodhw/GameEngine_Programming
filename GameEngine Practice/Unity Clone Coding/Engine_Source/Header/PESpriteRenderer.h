#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine {
	// ��������Ʈ(�̹���)�� �׸��� ������Ʈ
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// �׸� �̹����� �ε��մϴ�
		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImage; // �׷��� �̹���
		UINT mWidth; // �̹����� ���� ũ��
		UINT mHeight; // �̹����� ���� ũ��
	};
}


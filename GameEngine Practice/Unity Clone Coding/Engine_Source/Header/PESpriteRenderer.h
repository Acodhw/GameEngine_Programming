#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine {
	// 스프라이트(이미지)를 그리는 컴포넌트
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// 그릴 이미지를 로딩합니다
		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImage; // 그려질 이미지
		UINT mWidth; // 이미지의 가로 크기
		UINT mHeight; // 이미지의 세로 크기
	};
}


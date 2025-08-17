#pragma once
#include "PEResource.h"

namespace PracticeEngine::Graphics {

	// 텍스쳐 리소스 클래스
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			BMP,
			PNG,
			None,
		};

		static Texture* Create(const std::wstring& name, UINT width, UINT height);

		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path) override;

		const UINT& width = mWidth;
		const UINT& height = mHeight;

		void SetWidth(UINT width) { mWidth = width; }
		void SetHeight(UINT height) { mHeight = height; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mT_Type; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() { return mbAlpha; }

	private:
		bool mbAlpha;
		Gdiplus::Image* mImage; // 그려질 이미지
		HBITMAP mBitmap; // 비트맵 파일 가져올때
		HDC mHdc;

		eTextureType mT_Type; // 이미지의 타입

		UINT mWidth; // 이미지의 가로 크기
		UINT mHeight; // 이미지의 세로 크기
	};

}

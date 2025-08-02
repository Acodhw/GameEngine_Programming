#pragma once
#include "PEResource.h"

namespace PracticeEngine {
	namespace Graphics {
		class Texture : public Resource
		{
		public:
			enum class eTextureType
			{
				BMP,
				PNG,
				None,
			};
			Texture();
			~Texture();

			HRESULT Load(const std::wstring& path) override;

			const UINT& width = mWidth;
			const UINT& height = mHeight;

			HDC GetHdc() { return mHdc; }
			eTextureType GetTextureType() { return mT_Type; }
			Gdiplus::Image* GetImage() { return mImage; }

		private:
			Gdiplus::Image* mImage; // 그려질 이미지
			HBITMAP mBitmap; // 비트맵 파일 가져올때
			HDC mHdc;

			eTextureType mT_Type; // 이미지의 타입

			UINT mWidth; // 이미지의 가로 크기
			UINT mHeight; // 이미지의 세로 크기
		};
	}
}


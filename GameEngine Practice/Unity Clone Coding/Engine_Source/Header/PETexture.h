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
			Gdiplus::Image* mImage; // �׷��� �̹���
			HBITMAP mBitmap; // ��Ʈ�� ���� �����ö�
			HDC mHdc;

			eTextureType mT_Type; // �̹����� Ÿ��

			UINT mWidth; // �̹����� ���� ũ��
			UINT mHeight; // �̹����� ���� ũ��
		};
	}
}


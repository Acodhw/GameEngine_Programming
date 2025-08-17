#pragma once
#include "PEResource.h"

namespace PracticeEngine::Graphics {

	// �ؽ��� ���ҽ� Ŭ����
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
		Gdiplus::Image* mImage; // �׷��� �̹���
		HBITMAP mBitmap; // ��Ʈ�� ���� �����ö�
		HDC mHdc;

		eTextureType mT_Type; // �̹����� Ÿ��

		UINT mWidth; // �̹����� ���� ũ��
		UINT mHeight; // �̹����� ���� ũ��
	};

}

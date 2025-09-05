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
		//COLORREF GetPixel(int x, int y);

		const UINT& width = mWidth;
		const UINT& height = mHeight;

		void SetWidth(UINT width) { mWidth = width; }
		void SetHeight(UINT height) { mHeight = height; }
		eTextureType GetTextureType() const { return mT_Type; }


	private:
		bool mbAlpha;


		eTextureType mT_Type; // �̹����� Ÿ��

		UINT mWidth; // �̹����� ���� ũ��
		UINT mHeight; // �̹����� ���� ũ��
	};

}

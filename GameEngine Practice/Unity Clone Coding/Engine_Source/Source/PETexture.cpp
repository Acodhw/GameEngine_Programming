#include "PETexture.h"
#include "PEApplication.h"
#include "PEResources.h"

// extern : 해당 전역변수가 존재함을 알리는 키워드
extern PracticeEngine::Application application;

namespace PracticeEngine::Graphics {

	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image)
			return image;

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHDC();
		HWND hwnd = application.GetHWND();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name + L"Image", image);

		return image;
	}
	Texture::Texture()
		: Resource(eResourceType::Texture)
		, mT_Type(eTextureType::None)
		, mBitmap(nullptr)
		, mImage(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mbAlpha(false)
	{
	}
	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp") {
			mT_Type = eTextureType::BMP;
			/*mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0,
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);*/

			Gdiplus::Bitmap* bitmap = new Gdiplus::Bitmap(path.c_str());
			if (bitmap->GetLastStatus() == Gdiplus::Ok) {
				bitmap->GetHBITMAP(RGB(255, 255, 255), &mBitmap);
			}

			if (mBitmap == nullptr) return E_FAIL;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32) mbAlpha = true;
			else if (info.bmBitsPixel == 24) mbAlpha = false;

			HDC mainDC = application.GetHDC();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png") {
			mT_Type = eTextureType::PNG;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr) return E_FAIL;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}

	COLORREF Texture::GetPixel(int x, int y)
	{
		return ::GetPixel(mHdc, x, y);
	}
}

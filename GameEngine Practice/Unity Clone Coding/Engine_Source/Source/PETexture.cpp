#include "PETexture.h"
#include "PEApplication.h"

// extern : 해당 전역변수가 존재함을 알리는 키워드
extern PracticeEngine::Application application;

namespace PracticeEngine {
	namespace Graphics {
		Texture::Texture()
			: Resource(eResourceType::Texture)
			, mT_Type(eTextureType::None)
			, mBitmap(nullptr)
			, mImage(nullptr)
			, mHdc(nullptr)
			, mWidth(0)
			, mHeight(0)
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
	}
}
#include "PETileMapRenderer.h"
#include "PETransform.h"
#include "PERenderer.h"
#include "PEGameObject.h"

namespace PracticeEngine {

	Vector2 TileMapRenderer::TileSize = Vector2::One;
	Vector2 TileMapRenderer::OriginTileSize = Vector2::One;
	Vector2 TileMapRenderer::SelectedIndex = Vector2(-1.0f, -1.0f);

	TileMapRenderer::TileMapRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
		, mIndex(1, 1)
		, mTileSize(32.0f, 32.0f)
	{
		TileSize = mTileSize * mSize;
		OriginTileSize = mTileSize;
	}
	TileMapRenderer::~TileMapRenderer()
	{
	}
	void TileMapRenderer::Initialize()
	{


	}
	void TileMapRenderer::Update()
	{

	}

	void TileMapRenderer::LateUpdate()
	{
	}

	void TileMapRenderer::Render()
	{
		//if (mTexture == nullptr) {
		//	MessageBox(nullptr, L"Texture Loading Error!\nTexture is Empty!", L"Error!", MB_OK);
		//	assert(false);
		//}

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		//Vector2 scl = tr->GetScale();
		//float rot = tr->GetRotation();
		//pos = Renderer::mainCamera->CaluatePosition(pos);

		//Gdiplus::Graphics graphcis(hdc);

		//switch (mTexture->GetTextureType())
		//{
		//case Graphics::Texture::eTextureType::BMP:
		//	if (mTexture->IsAlpha())
		//	{
		//		BLENDFUNCTION func = {};
		//		func.BlendOp = AC_SRC_OVER;
		//		func.BlendFlags = 0;
		//		func.AlphaFormat = AC_SRC_ALPHA;
		//		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

		//		AlphaBlend(hdc
		//			, pos.x
		//			, pos.y
		//			, mTileSize.x * mSize.x * scl.x
		//			, mTileSize.y * mSize.y * scl.y
		//			, mTexture->GetHdc()
		//			, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
		//			, mTileSize.x
		//			, mTileSize.y
		//			, func);
		//	}
		//	else
		//	{
		//		TransparentBlt(hdc
		//			, pos.x, pos.y
		//			, mTileSize.x * mSize.x * scl.x
		//			, mTileSize.y * mSize.y * scl.y
		//			, mTexture->GetHdc()
		//			, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
		//			, mTileSize.x
		//			, mTileSize.y
		//			, RGB(255, 0, 255));
		//	}
		//	break;
		//case Graphics::Texture::eTextureType::PNG:
		//	Gdiplus::ImageAttributes imgAtt = {};
		//	imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

		//	graphcis.TranslateTransform(pos.x, pos.y);
		//	graphcis.RotateTransform(rot);
		//	graphcis.TranslateTransform(-pos.x, -pos.y);

		//	graphcis.DrawImage(mTexture->GetImage()
		//		, Gdiplus::Rect
		//		(
		//			pos.x, pos.y
		//			, mTileSize.x * mSize.x * scl.x
		//			, mTileSize.y * mSize.y * scl.y
		//		)
		//		, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
		//		, mTileSize.x
		//		, mTileSize.y
		//		, Gdiplus::UnitPixel
		//		, nullptr);
		//	break;
		//}

	}
}
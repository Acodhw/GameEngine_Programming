#include "PEToolScene.h"
#include "PETile.h"
#include "PEObject.h"
#include "PETileMapRenderer.h"
#include "PETexture.h"
#include "PEResources.h"
#include "PECamera.h"
#include "PERenderer.h"
#include "PEInput.h"
#include "PETransform.h"


namespace PracticeEngine {
	ToolScene::ToolScene()
	{
	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::Particle, Vector2(488,338));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::LButton)) {
			Vector2 pos = Input::GetMousePosition();
			if (pos.x >= 0.0f && pos.y >= 0.0f)
			{
				int idx = pos.x / TileMapRenderer::TileSize.x;
				int idy = pos.y / TileMapRenderer::TileSize.y;

				Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
				TileMapRenderer* tr = tile->AddComponent<TileMapRenderer>();
				tr->SetTexture(Resources::Find<Graphics::Texture>(L"TL"));
				tr->SetIndex(TileMapRenderer::SelectedIndex);
				tile->SetPosition(idx, idy);
				mTiles.push_back(tile);
			}
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Load();
		}
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = Renderer::mainCamera->CaluatePosition
			(
				Vector2(TileMapRenderer::TileSize.x * i, 0.0f)
			);
			MoveToEx(hdc, pos.x, 0, NULL);
			LineTo(hdc, pos.x, 5000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = Renderer::mainCamera->CaluatePosition
			(
				Vector2(0.0f, TileMapRenderer::TileSize.y * i)
			);

			MoveToEx(hdc, 0, pos.y, NULL);
			LineTo(hdc, 5000, pos.y);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}

	void ToolScene::Save()
	{
		// open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;
		std::wstring s(szFilePath);
		std::wstring s2(L".tile");
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, (s+s2).c_str(), L"wb");

		for (Tile* tile : mTiles)
		{
			TileMapRenderer* tmr = tile->GetComponent<TileMapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();

			
			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (!feof(pFile))
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			
			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<Graphics::Texture>(L"TL"));
			tmr->SetIndex(Vector2(idxX, idxY));

			tile->SetPosition(posX / TileMapRenderer::OriginTileSize.x, posY / TileMapRenderer::OriginTileSize.y);
			mTiles.push_back(tile);
		}

		fclose(pFile);
	}
}

// ≈∏¿œ∏  º±≈√
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		PracticeEngine::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / PracticeEngine::TileMapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / PracticeEngine::TileMapRenderer::OriginTileSize.y;

		PracticeEngine::TileMapRenderer::SelectedIndex = PracticeEngine::Vector2(idxX, idxY);
	}
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		PracticeEngine::Graphics::Texture* texture
			= PracticeEngine::Resources::Find<PracticeEngine::Graphics::Texture>(L"TL");
		if (texture == nullptr) return 0;
		switch (texture->GetTextureType())
		{
		case PracticeEngine::Graphics::Texture::eTextureType::BMP:
		{
			if (texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, 0, 0
					, texture->width
					, texture->height
					, texture->GetHdc()
					, 0, 0
					, texture->width
					, texture->height
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, 0, 0
					, texture->width
					, texture->height
					, texture->GetHdc()
					, 0, 0
					, texture->width
					, texture->height
					, RGB(255, 0, 255));
			}
		}
		break;
		case PracticeEngine::Graphics::Texture::eTextureType::PNG:
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(texture->GetImage()
				, Gdiplus::Rect
				(
					0, 0
					, texture->width
					, texture->height
				)
				, 0, 0
				, texture->width
				, texture->height
				, Gdiplus::UnitPixel
				, nullptr);
		}
		break;

		}
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}

	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}

	return 0;
}
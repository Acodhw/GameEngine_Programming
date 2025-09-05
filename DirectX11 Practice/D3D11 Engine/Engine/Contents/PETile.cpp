#include "PETile.h"
#include "PETransform.h"
#include "PETileMapRenderer.h"

namespace PracticeEngine {
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Tile::Render()
	{
		GameObject::Render();
	}

	void Tile::SetPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TileMapRenderer::TileSize.x;
		pos.y = y * TileMapRenderer::TileSize.y;
		tr->SetPos(pos);
	}
}
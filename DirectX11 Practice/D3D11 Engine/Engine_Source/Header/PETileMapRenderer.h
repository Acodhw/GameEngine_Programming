#pragma once
#include "PEEntity.h"
#include "PETexture.h"
#include "PEComponent.h"


namespace PracticeEngine {
    class TileMapRenderer :
        public Component
    {
	public:
		TileMapRenderer();
		~TileMapRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render()  override;
		
		void SetTexture(Graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Math::Vector2 size) { mSize = size; }
		void SetIndex(Vector2 index) { mIndex = index; }
		Vector2 GetIndex() const { return mIndex; }

	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;

	private:
		Vector2 mTileSize;
		Graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
    };
}


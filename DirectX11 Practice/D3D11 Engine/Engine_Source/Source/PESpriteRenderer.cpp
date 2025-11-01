#include "PESpriteRenderer.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PERenderer.h"
#include "PECamera.h"
#include "PEResources.h"

namespace PracticeEngine {
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mSprite(nullptr)
		, mMaterial(nullptr)
		, mMesh(nullptr)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
		mMesh = Resources::Find<Mesh>(L"RectMesh");
		mMaterial = Resources::Find<Material>(L"Sprite-Default-Material");
	}

	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::LateUpdate()
	{

	}

	void SpriteRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		if (tr)
			tr->Bind();

		if (mMesh)
			mMesh->Bind();

		if (mMaterial)
			mMaterial->BindShader();

		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Sprite);

		if (mMesh)
			Graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}
}


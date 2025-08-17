#pragma once

namespace PracticeEngine
{
	enum class eComponentType {
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		Collider,
		End
	};
	enum class eLayerType {
		None,
		BackGround,
		Tile,
		//���̾� �߰�
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		//Mesh
		//Shader
		AudioClip,
		Animaiton,
		Prefab,
		End,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}
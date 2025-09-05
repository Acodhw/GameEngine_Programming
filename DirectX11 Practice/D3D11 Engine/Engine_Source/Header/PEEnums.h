#pragma once

namespace PracticeEngine
{
	enum class eComponentType {
		Transform, 
		Collider,
		Rigidbody,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		AudioListener,
		AudioSource,
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
		Shader,
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

	enum class eUIType {
		Slider,
		Button,
		End,
	};
}
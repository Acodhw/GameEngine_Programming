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
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		Mesh,
		Material,
		Animaiton,
		AudioClip,
		Shader,
		
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
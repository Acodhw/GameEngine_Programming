#pragma once

namespace PracticeEngine
{
	enum class eComponentType {
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		End
	};
	enum class eLayerType {
		None,
		BackGround,
		//���̾� �߰�
		Player,
		particle,
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
}
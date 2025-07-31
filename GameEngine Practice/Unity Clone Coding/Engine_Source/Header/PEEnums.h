#pragma once

namespace PracticeEngine
{
	enum class eLayerType {
		None,
		BackGround,
		//레이어 추가
		Player,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		//Mesh
		//Shader
		AudioClip,
		Prefab,
		End,
	};
}
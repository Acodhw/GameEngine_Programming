#pragma once
#include "CommonInclude.h"
#include "PECollider.h"
#include "PEBoxCollider2D.h"
#include "PECircleCollider2D.h"

namespace PracticeEngine {

	union CollisionID {
		struct {
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Clear();

		// 레이어에 따른 충돌 판정을 체크합니다
		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);

	private:
		static std::bitset <(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}


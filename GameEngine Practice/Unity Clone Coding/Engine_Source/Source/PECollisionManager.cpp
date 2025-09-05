#define NOMINMAX
#include "PECollisionManager.h"
#include "PEScene.h"
#include "PESceneManager.h"
#include "PEGameObject.h"
#include "PELayer.h"
#include "PETransform.h"


namespace PracticeEngine{

	std::bitset <(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize() 
	{

	}
	void CollisionManager::Update() 
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision((eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate() 
	{
	
	}

	void CollisionManager::Render() 
	{
	
	}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}

	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0, col = 0;

		if (left <= right) {
			row = (UINT)left; col = (UINT)right;
		}
		else {
			row = (UINT)right; col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision( eLayerType left, eLayerType right) {
		const std::vector<GameObject*>& leftObjs = SceneManager::GetGameObjects(left);//scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rightObjs = SceneManager::GetGameObjects(right); // scene->GetLayer(right)->GetGameObjects();

		for (GameObject* leftObj : leftObjs)
		{
			if (leftObj->IsActive() == false)
				continue;
			Collider* leftCol = leftObj->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* rightObj : rightObjs)
			{
				if (rightObj->IsActive() == false)
					continue;
				Collider* rightCol = rightObj->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
					continue;

				ColliderCollision(leftCol, rightCol);
			}

		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right) 
	{
		// 두 충돌체 번호를 가져온 ID를 확인해서 CollisionID값 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보를 검색한다.
		// 만약에 충돌정보가 없는 상태라면
		// 충돌정보를 생성해준다.

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크를 해준다
		if (Intersect(left, right))
		{
			//최초 충돌할
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//충돌을 하지 않은 상태
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}

	}

	bool CollisionManager::Intersect(Collider* left, Collider* right) {
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->offset;
		Vector2 rightPos = rightTr->GetPosition() + right->offset;

		// size 1,1 일 기본크기가 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		//AABB 충돌
		eColliderType leftType = left->GetColliderType();
		eColliderType rightType = right->GetColliderType();

		if (leftType == eColliderType::Rect2D
			&& rightType == eColliderType::Rect2D)
		{

			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}


		if (leftType == eColliderType::Circle2D
			&& rightType == eColliderType::Circle2D)
		{
			//circle -circle
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).Length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == eColliderType::Circle2D && rightType == eColliderType::Rect2D)
			|| (leftType == eColliderType::Rect2D && rightType == eColliderType::Circle2D))
		{
			
			Vector2 circlePos, rectPos, rectSize;
			float circleRadius;

			if (leftType == eColliderType::Circle2D)
			{
				circlePos = leftPos + (leftSize / 2.0f);  // 원의 중심점
				circleRadius = leftSize.x / 2.0f;         // 원의 반지름
				rectPos = rightPos;                       // 사각형 위치 (좌상단)
				rectSize = rightSize;                     // 사각형 크기
			}
			else
			{
				circlePos = rightPos + (rightSize / 2.0f); // 원의 중심점
				circleRadius = rightSize.x / 2.0f;         // 원의 반지름
				rectPos = leftPos;                         // 사각형 위치 (좌상단)
				rectSize = leftSize;                       // 사각형 크기
			}

			// 사각형의 중심점과 반폭/반높이 계산
			Vector2 rectCenter = rectPos + (rectSize / 2.0f);
			float rectHalfWidth = rectSize.x / 2.0f;
			float rectHalfHeight = rectSize.y / 2.0f;

			// 원의 중심에서 사각형의 가장 가까운 점까지의 거리 계산
			Vector2 distance = circlePos - rectCenter;

			// 원의 중심에서 사각형의 가장 가까운 점 찾기
			Vector2 closestPoint;
			closestPoint.x = std::max(-rectHalfWidth, std::min(rectHalfWidth, distance.x));
			closestPoint.y = std::max(-rectHalfHeight, std::min(rectHalfHeight, distance.y));

			// 원의 중심에서 가장 가까운 점까지의 거리
			Vector2 diff = distance - closestPoint;
			float distanceToClosest = diff.Length();

			// 거리가 원의 반지름보다 작거나 같으면 충돌
			if (distanceToClosest <= circleRadius)
			{
				return true;
			}
		}

	}
}
#include "PEBoxCollider2D.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PECollider.h"
#include "PERenderer.h"

namespace PracticeEngine {
	BoxCollider2D::BoxCollider2D()
		: Collider(eColliderType::Rect2D)
	{
	}
	BoxCollider2D::~BoxCollider2D() {
	}

	 void BoxCollider2D::Initialize() {
	 }
	 void BoxCollider2D::Update() {
	 }
	 void BoxCollider2D::LateUpdate() {
	 }
	 void BoxCollider2D::Render() {
		 Transform* tr = GetOwner()->GetComponent<Transform>();
		 Vector3 pos = tr->GetPosition();
	 }
}
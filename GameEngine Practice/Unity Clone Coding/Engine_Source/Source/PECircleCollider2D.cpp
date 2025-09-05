#include "PECircleCollider2D.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PERenderer.h"

namespace PracticeEngine {
    CircleCollider2D::CircleCollider2D()
        : mRadius(1)
        , Collider(eColliderType::Rect2D)
    {
    }
    CircleCollider2D::~CircleCollider2D()
    {
    }

    void CircleCollider2D::Initialize() {

    }

    void CircleCollider2D::Update() {

    }

    void CircleCollider2D::LateUpdate() {

    }

    void CircleCollider2D::Render() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
    }
}
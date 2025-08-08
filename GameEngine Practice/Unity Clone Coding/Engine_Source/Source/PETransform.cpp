#include "PETransform.h"

namespace PracticeEngine {
	Transform::Transform() 
		: Component(eComponentType::SpriteRenderer)
		, mPosition{0,0}
		, mScale{1,1}
		, mRotation(0)
	{}
	Transform::~Transform() {}

	void Transform::Initialize() {}
	void Transform::Update() {}
	void Transform::LateUpdate() {}
	void Transform::Render(HDC hdc) {}
}
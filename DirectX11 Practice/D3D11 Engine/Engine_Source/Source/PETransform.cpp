#include "PETransform.h"
#include "PEGraphics.h"
#include "PECamera.h"
#include "PEConstantBuffer.h"
#include "PERenderer.h"

namespace PracticeEngine {
	Transform::Transform() 
		: Component(eComponentType::SpriteRenderer)
		, mWorldMatrix(Matrix::Identity)
		, mScale(Vector3::One)
		, mRotation(Vector3::Zero)
		, mPosition(Vector3::Zero)
	{}
	Transform::~Transform() {}

	void Transform::Initialize() {}
	void Transform::Update() {}
	void Transform::LateUpdate() {
		Matrix scale = Matrix::CreateScale(mScale.x, mScale.y, mScale.z);
		Matrix rotation = Matrix::CreateRotationX(Math::Radian(mRotation.x));
		rotation *= Matrix::CreateRotationY(Math::Radian(mRotation.y));
		rotation *= Matrix::CreateRotationZ(Math::Radian(mRotation.z));
		Matrix translation = Matrix::CreateTranslation(mPosition);

		mWorldMatrix = scale * rotation * translation;

		mForward = Vector3::TransformNormal(Vector3::Forward, rotation);
		mRight = Vector3::TransformNormal(Vector3::Right, rotation);
		mUp = Vector3::TransformNormal(Vector3::Up, rotation);
	}
	void Transform::Render() {}

	void Transform::Bind()
	{
		Graphics::TransformCB cbData = {};
		cbData.World = GetWorldMatrix();
		cbData.View = Camera::GetGpuViewMatrix();
		cbData.Projection = Camera::GetGpuProjectionMatrix();

		Graphics::ConstantBuffer* cb = Renderer::constantBuffers[CBSLOT_TRANSFORM];

		cb->SetData(&cbData);
		cb->Bind(eShaderStage::All);
	}
}
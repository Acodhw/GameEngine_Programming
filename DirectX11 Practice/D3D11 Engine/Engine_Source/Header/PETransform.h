#pragma once
#include "CommonInclude.h"
#include "PEComponent.h"

namespace PracticeEngine {
	using namespace Math;
	// ������Ʈ�� ��ġ, ũ��, ȸ���� �����ϴ� ������Ʈ
	class Transform : public Component
	{
	public :
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		// �������� �����մϴ�
		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		// ȸ���� �����մϴ�	
		void SetRot(float rot) { mRotation = rot; }
		// ũ�⸦ �����մϴ�
		void SetScl(Vector2 scl) { mScale.x = scl.x; mScale.y = scl.y; }
		// �������� �����ɴϴ�
		Vector2 GetPosition() { return mPosition; }
		// ȸ�� ������ �����ɴϴ�
		float GetRotation() { return mRotation; }
		// ũ�� ������ �����ɴϴ�
		Vector2 GetScale() { return mScale; }
	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}


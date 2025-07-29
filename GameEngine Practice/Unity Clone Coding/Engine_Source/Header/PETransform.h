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
		void Render(HDC hdc) override;

		// �������� �����մϴ�
		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		// �������� �����ɴϴ�
		Vector2 GetPosition() { return mPosition; }
	private:
		Vector2 mPosition;
	};
}


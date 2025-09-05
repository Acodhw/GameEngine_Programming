#pragma once
#include "PEComponent.h"

namespace PracticeEngine {
	//�浹 ������ üũ�ϴ� ������Ʈ
	class Collider : public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();
		
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		UINT32 GetID() { return mID; }

		const Vector2& offset = mOffset;
		void SetOffset(Vector2 ofs) { mOffset = ofs; }

		eColliderType GetColliderType() { return mType; }

		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	private:
		static UINT mCollisionID;

		UINT32 mID;
		Vector2 mOffset;
		Vector2 mSize;
		eColliderType mType;
	};
}


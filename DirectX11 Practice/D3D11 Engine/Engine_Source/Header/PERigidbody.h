#pragma once
#include "PEComponent.h"

namespace PracticeEngine {
    class Rigidbody :public Component
    {
	public:
		Rigidbody();
		~Rigidbody();

		 void Initialize() override;
		 void Update() override;
		 void LateUpdate() override;
		 void Render() override;

		 void SetMass(float mass) { mMass = mass; }
		 void AddForce(Vector2 force) { mForce = force; }
		 void SetGround(bool ground) { mIsGround = ground; }
		 void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		 Vector2 GetVelocity() { return mVelocity; }

	private:
		bool mIsGround;

		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mLimitedVelocity;
		Vector2 mVelocity;
		Vector2 mGravity;
    };

}

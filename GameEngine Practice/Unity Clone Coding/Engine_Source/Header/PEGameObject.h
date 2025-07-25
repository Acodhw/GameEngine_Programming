#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	//Actor : 게임 내 여러 오브젝트의 정보를 담는 클래스
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mx = x;
			my = y;
		}

		float GetPositionX() { return mx; }
		float GetPositionY() { return my; }
		
	private:
		// 게임 오브젝트의 좌표
		float mx;
		float my;
	};
}
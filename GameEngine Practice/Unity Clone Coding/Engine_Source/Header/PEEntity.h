#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	using namespace Math;
	// 이름을 가지는 클래스의 지정입니다
	class Entity 
	{
	public:
		Entity();
		virtual ~Entity();
		// 엔티티의 키를 제공합니다
		void SetName(const std::wstring& name) { mName = name; }
		// 엔티티의 이름을 불러옵니다
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName; // 엔티티의 이름
	};
}

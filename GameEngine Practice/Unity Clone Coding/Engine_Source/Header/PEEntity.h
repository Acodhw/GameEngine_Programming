#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	// 이름을 가지는 클래스의 지정입니다
	class Entity 
	{
	public:
		Entity();
		virtual ~Entity();
		// 엔티티의 키를 제공합니다
		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}

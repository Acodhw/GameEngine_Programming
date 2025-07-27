#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	class Entity // 이름을 갖는 것들에 대한 상속
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}

#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	// �̸��� ������ Ŭ������ �����Դϴ�
	class Entity 
	{
	public:
		Entity();
		virtual ~Entity();
		// ��ƼƼ�� Ű�� �����մϴ�
		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}

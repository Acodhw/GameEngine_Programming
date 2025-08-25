#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	using namespace Math;
	// �̸��� ������ Ŭ������ �����Դϴ�
	class Entity 
	{
	public:
		Entity();
		virtual ~Entity();
		// ��ƼƼ�� Ű�� �����մϴ�
		void SetName(const std::wstring& name) { mName = name; }
		// ��ƼƼ�� �̸��� �ҷ��ɴϴ�
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName; // ��ƼƼ�� �̸�
	};
}

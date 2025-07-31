#pragma once
#include "PEEntity.h"

namespace PracticeEngine {
	// ���� �� ���ҽ��� �����ϴ� Ŭ����
	class Resource abstract : public Entity
	{
	public:
		Resource(eResourceType type);
		Resource() = delete;
		virtual ~Resource();

		// ���ҽ��� �ε��ϴ� �Լ�
		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ� => Ŭ������ �߻�ȭ/�޸� �Ҵ� �Ұ�

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		std::wstring mPath;
	};
}

// ���ҽ� : ���ӿ��� ���Ǵ� �����͵��� ��Ī
// => �̹���, ����, ����ġ ��
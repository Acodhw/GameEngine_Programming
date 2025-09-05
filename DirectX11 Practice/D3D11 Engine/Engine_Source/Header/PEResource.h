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

		// ���ҽ��� �����ϴ� �Լ�
		virtual HRESULT Save(const std::wstring& path) = 0;
		// ���ҽ��� �ε��ϴ� �Լ�
		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ� => Ŭ������ �߻�ȭ/�޸� �Ҵ� �Ұ�
		// ���ҽ��� ��θ� �����ɴϴ�
		const std::wstring& GetPath() { return mPath; }
		// ���ҽ��� ��θ� �ҷ��ɴϴ�
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		std::wstring mPath;
	};
}

// ���ҽ� : ���ӿ��� ���Ǵ� �����͵��� ��Ī
// => �̹���, ����, ����ġ ��
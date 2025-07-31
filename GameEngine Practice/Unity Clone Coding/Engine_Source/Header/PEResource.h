#pragma once
#include "PEEntity.h"

namespace PracticeEngine {
	// 게임 내 리소스를 관리하는 클래스
	class Resource abstract : public Entity
	{
	public:
		Resource(eResourceType type);
		Resource() = delete;
		virtual ~Resource();

		// 리소스를 로딩하는 함수
		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 => 클래스를 추상화/메모리 할당 불가

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		std::wstring mPath;
	};
}

// 리소스 : 게임에서 사용되는 데이터들의 총칭
// => 이미지, 사운드, 스위치 등
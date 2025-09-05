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

		// 리소스를 저장하는 함수
		virtual HRESULT Save(const std::wstring& path) = 0;
		// 리소스를 로딩하는 함수
		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 => 클래스를 추상화/메모리 할당 불가
		// 리소스의 경로를 가져옵니다
		const std::wstring& GetPath() { return mPath; }
		// 리소스의 경로를 불러옵니다
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		std::wstring mPath;
	};
}

// 리소스 : 게임에서 사용되는 데이터들의 총칭
// => 이미지, 사운드, 스위치 등
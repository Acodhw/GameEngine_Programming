#pragma once
#include "PEResource.h"

namespace PracticeEngine {
	class Resources 
	{
	public:
		// 리소스 목록에서 리소스를 찾습니다
		template<typename T>
		static T* Find(const std::wstring& key){
			auto iter = mResources.find(key);

			if (iter == mResources.end()) return nullptr;

			return dynamic_cast<T*>(iter->second);
		}
		// 리소스 목록에 리소스를 로드합니다
		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path) {
			T* resource = Resources::Find<T>(key);

			if (resource != nullptr) return resource;

			resource = new T();
			if (FAILED(resource->Load(path))) {
				MessageBox(nullptr, (L"Resource Error!\nCheck the Path\n" + path).c_str(), L"Error!", MB_OK);
				assert(false);
			}
			
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}

	private:
		static std::map<std::wstring, Resource*> mResources; // 현재 리소스 목록입니다
	};
}


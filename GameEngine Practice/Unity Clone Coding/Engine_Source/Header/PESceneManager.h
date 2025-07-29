#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	// 여러 씬들을 관리하는 클래스
	class SceneManager
	{
	public:
		// 특정 씬을 씬 메니져에게 제공합니다
		template <typename T> // 상속받는 씬에 대한 탬플렛
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize(); // 씬 초기화

			mScene.insert(std::make_pair(name, scene)); // 씬을 씬 map에 넣음

			return scene; // 씬 리턴
		}

		// 씬 메지녀가 가지고 있는 씬 정보를 제공합니다
		static Scene* LoadScene(const std::wstring& name)
		{
			if(mActiveScene)
				mActiveScene->OnExit();
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name); // 씬 map에서 해당 이름 씬을 찾기
			if (iter == mScene.end()) // 씬이 없으면
				return nullptr; // nullptr 제공

			mActiveScene = iter->second; // 현재 활성화 씬을 지금 씬으로 변경

			mActiveScene->OnEnter();

			return iter->second; // 찾은 씬 리턴
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::map<std::wstring, Scene*> mScene; // 씬 메니저에 로드 된 씬 종류
		static Scene* mActiveScene; // 현재 활성화된 씬
	};
}


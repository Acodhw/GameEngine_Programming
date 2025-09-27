#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	class Scene;
	// 여러 씬들을 관리하는 클래스
	class SceneManager
	{
	public:
		// 특정 씬을 씬 메니져에게 제공합니다
		template <typename T> // 상속받는 씬에 대한 탬플렛
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			mScene.insert(std::make_pair(name, scene));

			scene->SetName(name);
			scene->Initialize(); // 씬 초기화

			return scene; // 씬 리턴
		}

		// 씬 메지녀가 가지고 있는 씬 정보를 제공합니다
		static Scene* LoadScene(const std::wstring& name);
		
		static bool SetActiveScene(const std::wstring& name);
		// 현재 작동중인 씬을 가져옵니다
		static Scene* GetActiveScene() { return mActiveScene; }
		// 게임이 진행되는 동안 계속 실행되는 씬을 가져옵니다
		static Scene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }
		static std::vector<GameObject*> GetGameObjects(eLayerType layer);
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Release();
		static void Destroy();

	private:
		static std::map<std::wstring, Scene*> mScene; // 씬 메니저에 로드 된 씬 종류
		static Scene* mActiveScene; // 현재 활성화된 씬
		static Scene* mDontDestroyOnLoad; // 삭제되지 않는 씬
	};
}


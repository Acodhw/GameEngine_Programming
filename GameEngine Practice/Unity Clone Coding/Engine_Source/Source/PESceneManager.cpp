#include "PESceneManager.h"

namespace PracticeEngine {

	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize() 
	{
	
	}

	void SceneManager::Update() 
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate() 
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc) 
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}
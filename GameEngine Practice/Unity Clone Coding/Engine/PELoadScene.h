#pragma once
#include "..\\PracticeEngine_SOURCE\\PESceneManager.h"
#include "PEPlayScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene을 씬 메니져의 씬에 생성

		SceneManager::LoadScene(L"PlayScene"); // playScene을 로딩
	}
}
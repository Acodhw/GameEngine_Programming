#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"
#include "PELoadingScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene"); // 게임 시작 시 로딩하는 영역
		SceneManager::LoadScene(L"LoadingScene");
	}
}
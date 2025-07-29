#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene을 씬 메니져의 씬에 생성
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene을 씬 메니져의 씬에 생성

		SceneManager::LoadScene(L"PlayScene"); // playScene을 로딩
	}
}
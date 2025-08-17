#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"
#include "PEToolScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene을 씬 메니져의 씬에 생성
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene을 씬 메니져의 씬에 생성
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"TitleScene"); // playScene을 로딩
	}
}
#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"
#include "PEToolScene.h"
#include "PELoadingScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene"); // 게임 시작 시 로딩하는 영역
		//SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene을 씬 메니져의 씬에 생성
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene을 씬 메니져의 씬에 생성
		SceneManager::LoadScene(L"LoadingScene");
		//SceneManager::LoadScene(L"TitleScene"); // playScene을 로딩
	}
}
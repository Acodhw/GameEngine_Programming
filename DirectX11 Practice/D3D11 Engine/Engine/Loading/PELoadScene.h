#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"
#include "PEToolScene.h"
#include "PELoadingScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene"); // ���� ���� �� �ε��ϴ� ����
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene�� �� �޴����� ���� ����
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene�� �� �޴����� ���� ����
		SceneManager::LoadScene(L"LoadingScene");
		//SceneManager::LoadScene(L"TitleScene"); // playScene�� �ε�
	}
}
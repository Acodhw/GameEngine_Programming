#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"
#include "PEToolScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene�� �� �޴����� ���� ����
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene�� �� �޴����� ���� ����
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"TitleScene"); // playScene�� �ε�
	}
}
#pragma once
#include "PESceneManager.h"
#include "PEPlayScene.h"
#include "PETitleScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene"); // TitleScene�� �� �޴����� ���� ����
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene�� �� �޴����� ���� ����

		SceneManager::LoadScene(L"PlayScene"); // playScene�� �ε�
	}
}
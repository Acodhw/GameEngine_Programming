#pragma once
#include "..\\PracticeEngine_SOURCE\\PESceneManager.h"
#include "PEPlayScene.h"

namespace PracticeEngine {

	void LoadScenes() 
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene"); // playScene�� �� �޴����� ���� ����

		SceneManager::LoadScene(L"PlayScene"); // playScene�� �ε�
	}
}
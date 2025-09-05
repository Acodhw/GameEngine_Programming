#include "PETitleScene.h"
#include "PESpriteObj.h"
#include "PESceneManager.h"
#include "PEGameObject.h"
#include "PETransform.h"
#include "PESpriteRenderer.h"
#include "PEInput.h"


namespace PracticeEngine {

    TitleScene::TitleScene() {}
    TitleScene::~TitleScene() {}

    void TitleScene::Initialize()
    {
        Scene::Initialize();
    }
    void TitleScene::Update()
    {
        Scene::Update();     
        if (Input::GetKeyDown(eKeyCode::E)) {
            SceneManager::LoadScene(L"PlayScene");
        }
    }
    void TitleScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    void TitleScene::Render()
    {
        Scene::Render();
        //wchar_t str[50] = L"Title";
        //TextOutW(hdc, 50, 50, str, wcslen(str));
    }

    void TitleScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void TitleScene::OnExit()
    {
        Scene::OnExit();
    }
}
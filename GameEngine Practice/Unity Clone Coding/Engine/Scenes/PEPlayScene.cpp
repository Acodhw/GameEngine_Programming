#include "PEPlayScene.h"
#include "PEPlayer.h"
#include "PEBackGround.h"
#include"PEGameObject.h"
#include "PETransform.h"
#include "PESpriteRenderer.h"
#include "PEObject.h"


namespace PracticeEngine {
    PlayScene::PlayScene()
    {
    }
    PlayScene::~PlayScene()
    {
        
    }
    void PlayScene::Initialize()
    {
        Scene::Initialize();

        GameObject * pl = Object::Instantiate<Player>
            (eLayerType::Player, Vector2(100.0f, 100.0f));
        SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
        sr->ImageLoad(L"..\\Resources\\Player_idle.png");

        GameObject* bg2 = Object::Instantiate<BackGround>
            (eLayerType::BackGround, Vector2(0, 0));
        SpriteRenderer* sr2 = bg2->AddComponent<SpriteRenderer>();
        sr2->ImageLoad(L"..\\Resources\\CloudOcean.png");
    }

    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void PlayScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void PlayScene::OnExit()
    {
        Scene::OnExit();
    }
}
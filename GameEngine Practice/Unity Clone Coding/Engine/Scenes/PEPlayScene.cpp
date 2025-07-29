#include "PEPlayScene.h"
#include "PEPlayer.h"
#include"PEGameObject.h"
#include "PETransform.h"
#include "PESpriteRenderer.h"


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

        Player* bg = new Player();
        Transform* tr = bg->AddComponent<Transform>();
        tr->SetPos(Vector2(0, 0));

        tr->SetName(L"TR");

        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        sr->SetName(L"SR");
        sr->ImageLoad(L"..\\Resources\\Player_idle.png");

        AddGameObject(bg, eLayerType::Player);

        Player* bg2 = new Player();
        Transform* tr2 = bg2->AddComponent<Transform>();
        tr2->SetPos(Vector2(0, 0));

        tr2->SetName(L"TR2");

        SpriteRenderer* sr2 = bg2->AddComponent<SpriteRenderer>();
        sr2->SetName(L"SR2");
        sr2->ImageLoad(L"..\\Resources\\CloudOcean.png");

        AddGameObject(bg2, eLayerType::BackGround);
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
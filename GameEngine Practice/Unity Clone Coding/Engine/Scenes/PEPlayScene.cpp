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

        AddGameObject(bg);
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
}
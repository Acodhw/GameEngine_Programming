#include "PEPlayScene.h"
#include "PEPlayer.h"
#include "PEBackGround.h"
#include"PEGameObject.h"
#include "PETransform.h"
#include "PESpriteRenderer.h"
#include "PEObject.h"
#include "PETexture.h"
#include "PEResources.h"


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

        // 게임 오브젝트 로딩 전, 리소스 로딩
        
        GameObject * pl = Object::Instantiate<Player>
            (eLayerType::Player, Vector2(100.0f, 100.0f));
        SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
        Graphics::Texture* tex = Resources::Find<Graphics::Texture>(L"PL");
        sr->SetTexture(tex);

        GameObject* bg2 = Object::Instantiate<BackGround>
            (eLayerType::BackGround, Vector2(0, 0));
        SpriteRenderer* sr2 = bg2->AddComponent<SpriteRenderer>();
        tex = Resources::Find<Graphics::Texture>(L"BG");
        sr2->SetTexture(tex);

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
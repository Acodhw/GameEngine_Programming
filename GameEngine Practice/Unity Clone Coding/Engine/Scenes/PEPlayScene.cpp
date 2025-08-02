#include "PEPlayScene.h"
#include "PEPlayerScript.h"
#include "PESpriteObj.h"
#include"PEGameObject.h"
#include "PETransform.h"
#include "PESpriteRenderer.h"
#include "PEObject.h"
#include "PETexture.h"
#include "PEResources.h"
#include "PECamera.h"
#include "PERenderer.h"
#include "PEAnimator.h"


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

        // 메인카메라
        GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector2(0, 0));
        Camera* cComp = camera->AddComponent<Camera>();
        Renderer::mainCamera = cComp;
        

        // 게임 오브젝트 로딩 전, 리소스 로딩
        
        GameObject * pl = Object::Instantiate<SpriteObj>
            (eLayerType::Player, Vector2(100.0f, 100.0f));
        Graphics::Texture* tex = Resources::Find<Graphics::Texture>(L"PL_S");
        pl->AddComponent<PlayerScript>();
        cComp->SetTarger(pl);

        Animator* animator = pl->AddComponent<Animator>();
        animator->CreateAnimation(L"idle", tex
            , Vector2(0.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2(0.5f, 0.5f), 7, 0.3f);
        animator->PlayAnimation(L"idle", true);         

        GameObject* bg2 = Object::Instantiate<SpriteObj>
            (eLayerType::BackGround, Vector2(750, 520));
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
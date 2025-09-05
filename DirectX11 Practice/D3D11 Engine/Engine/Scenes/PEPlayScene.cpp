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
#include "PEBoxCollider2D.h"
#include "PECircleCollider2D.h"
#include "PETile.h"
#include "PETileMapRenderer.h"
#include "PECollisionManager.h"
#include <io.h> // for _access

namespace PracticeEngine {
    PlayScene::PlayScene()
    {
    }
    PlayScene::~PlayScene()
    {

    }
    void PlayScene::Initialize()
    {
        //FILE* pFile = nullptr;
        //_wfopen_s(&pFile, L"..\\Resources\\Test.tile", L"rb");
        //if (pFile) {
        //    while (true)
        //    {
        //        int idxX = 0;
        //        int idxY = 0;

        //        int posX = 0;
        //        int posY = 0;

        //        if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
        //            break;
        //        if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
        //            break;
        //        if (fread(&posX, sizeof(int), 1, pFile) == NULL)
        //            break;
        //        if (fread(&posY, sizeof(int), 1, pFile) == NULL)
        //            break;

        //        Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile, Vector2(posX, posY));
        //        TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
        //        tmr->SetTexture(Resources::Find<Graphics::Texture>(L"TL"));
        //        tmr->SetIndex(Vector2(idxX, idxY));

        //    }
        //}

        //// 메인카메라
        //GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector2(0, 0));
        //Camera* cComp = camera->AddComponent<Camera>();
        //Renderer::mainCamera = cComp;


        //// 게임 오브젝트 로딩 전, 리소스 로딩

        //GameObject* pl = Object::Instantiate<SpriteObj>
        //    (eLayerType::Player, Vector2(100.0f, 100.0f));
        //Graphics::Texture* tex = Resources::Find<Graphics::Texture>(L"PL_S");
        //pl->AddComponent<PlayerScript>();
        //BoxCollider2D* bcol = pl->AddComponent<BoxCollider2D>();
        //bcol->SetSize(Vector2(0.5, 1));
        //bcol->SetOffset(Vector2::Up * 50 + Vector2::Left * 25);
        //CircleCollider2D* ccol = pl->AddComponent<CircleCollider2D>();
        //ccol->SetSize(Vector2::One * 0.5f);
        //ccol->SetOffset(Vector2::Up * 75 + Vector2::Left * 25);
        //cComp->SetTarger(pl);

        //Animator* animator = pl->AddComponent<Animator>();
        //animator->CreateAnimation(L"idle", tex
        //    , Vector2(0.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2(0.5f, 0.5f), 7, 0.3f);
        //animator->PlayAnimation(L"idle", true);

        //GameObject* bg2 = Object::Instantiate<SpriteObj>
        //    (eLayerType::BackGround, Vector2(0, 0));
        //SpriteRenderer* sr2 = bg2->AddComponent<SpriteRenderer>();
        //tex = Resources::Find<Graphics::Texture>(L"BG");
        //sr2->SetTexture(tex);
        Scene::Initialize();
    }

    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    void PlayScene::Render()
    {
        Scene::Render();
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
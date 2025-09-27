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
#include "PEGraphicsDevice_DX11.h"
#include "PEMaterial.h"
#include "PEPlayer.h"
#include "PECameraScript.h"
#include <io.h> // for _access

namespace PracticeEngine {
    PlayScene::PlayScene()
        : mPlayer(nullptr)
    {
    }
    PlayScene::~PlayScene()
    {

    }
    void PlayScene::Initialize()
    {
        Scene::Initialize();

        // main camera
        GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector3(0.0f, 0.0f, -10.0f));
        Camera* cameraComp = camera->AddComponent<Camera>();
        cameraComp->SetProjectionType(Camera::eProjectionType::Orthographic);
        cameraComp->SetSize(200.0f);

        CameraScript* cameraScript = camera->AddComponent<CameraScript>();
        Renderer::mainCamera = cameraComp;

        mPlayer = Object::Instantiate<Player>(eLayerType::Player);
        Object::DontDestroyOnLoad(mPlayer);

        SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
        sr->SetSprite(Resources::Find<Graphics::Texture>(L"Player"));
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
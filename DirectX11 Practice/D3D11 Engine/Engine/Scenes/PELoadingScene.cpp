#include "PEScene.h"
#include "PELoadingScene.h"
#include "PESceneManager.h"
#include "PERenderer.h"
#include "PEResources.h"
#include "PETexture.h"
#include "PEApplication.h"
#include "PETitleScene.h"
#include "PEPlayScene.h"

extern PracticeEngine::Application application;


namespace PracticeEngine {
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
		, mMutualExclusion()
		, mResourcesLoadThread()
	{

	}

	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoadThread;
		mResourcesLoadThread = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutualExclusion));
	}

	void LoadingScene::Update()
	{
		
	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render()
	{
		if (mbLoadCompleted)
		{
			//만약 메인쓰레드가 종료되는데 자식쓰레드가 남아있다면
			//자식쓰레드를 메인쓰레드에 편입시켜 메인쓰레드가 종료되기전까지 block
			mResourcesLoadThread->join();

			//메인쓰레드와 완전 분리 시켜 독립적인 쓰레드 운영가능
			//mResourcesLoadThread->detach();

			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LoadingScene::OnEnter()
	{

	}

	void LoadingScene::OnExit()
	{

	}
	void LoadingScene::resourcesLoad(std::mutex& m) // mutex : 임계 영역 - cpu 연산에 한 쓰레드가 이걸 이용할 때, 다른 쓰레드는 대기상태
	{
		while (true)
		{
			if (application.IsLoaded() == true)
				break;
		}
		m.lock();
		{
			Resources::Load<Graphics::Texture>(L"Player", L"..\\Resources\\CloudOcean.png");
		
			Renderer::Initialize();

			SceneManager::CreateScene<TitleScene>(L"TitleScene");
			SceneManager::CreateScene<PlayScene>(L"PlayScene");
		}
		m.unlock();

		// complete
		SceneManager::SetActiveScene(L"LoadingScene");
		mbLoadCompleted = true;

	}

}


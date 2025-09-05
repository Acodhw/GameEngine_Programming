#include "PEScene.h"
#include "PELoadingScene.h"
#include "PESceneManager.h"
#include "PERenderer.h"
#include "PEResources.h"
#include "PETexture.h"


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

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render()
	{

	}

	void LoadingScene::OnEnter()
	{

	}

	void LoadingScene::OnExit()
	{

	}
	void LoadingScene::resourcesLoad(std::mutex& m) // mutex : 임계 영역 - cpu 연산에 한 쓰레드가 이걸 이용할 때, 다른 쓰레드는 대기상태
	{
		m.lock();
		{
			Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
			Resources::Load<Graphics::Texture>(L"PL", L"..\\Resources\\Player_idle.png");
			Resources::Load<Graphics::Texture>(L"PL_S", L"..\\Resources\\Player_idle-Sheet.png");
			Resources::Load<Graphics::Texture>(L"PL_A", L"..\\Resources\\Player_idle-Sheet_Aplha.bmp");
			Resources::Load<Graphics::Texture>(L"TL", L"..\\Resources\\Grasstile.png");
		}
		m.unlock();

		// complete
		mbLoadCompleted = true;

	}

}


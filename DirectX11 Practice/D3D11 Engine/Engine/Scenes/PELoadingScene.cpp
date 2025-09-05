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
			//���� ���ξ����尡 ����Ǵµ� �ڽľ����尡 �����ִٸ�
			//�ڽľ����带 ���ξ����忡 ���Խ��� ���ξ����尡 ����Ǳ������� block
			mResourcesLoadThread->join();

			//���ξ������ ���� �и� ���� �������� ������ �����
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
	void LoadingScene::resourcesLoad(std::mutex& m) // mutex : �Ӱ� ���� - cpu ���꿡 �� �����尡 �̰� �̿��� ��, �ٸ� ������� ������
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


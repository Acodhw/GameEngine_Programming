#include "PEApplication.h"
#include "PEInput.h"
#include "PETime.h"
#include "PESceneManager.h"
#include "PEResources.h"
#include "PEFmod.h"
#include "PECollisionManager.h"
#include "PEUIManager.h"
#include "PERenderer.h"

#define MAX_LOADSTRING 100

namespace PracticeEngine {

	Application::Application()
		: mHwmd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(NULL)
		, mBackBuffer(NULL)
		, mbLoaded(false)
		, title(new wchar_t[MAX_LOADSTRING])
	{

	}

	Application::~Application()
	{
		delete[] title;
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		AdjustWindowRect(hwnd, width, height);
		InitializeEtc();

		mGraphicDevice = std::make_unique<Graphics::GraphicsDevice_DX11>();
		//Renderer::Initialize();
		mGraphicDevice->Initialize();

		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
	}

	void Application::AdjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwmd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(hwnd, true);
		GetWindowText(mHwmd, title, MAX_LOADSTRING);
	}

	void Application::InitializeEtc()
	{
		Input::Initailze();
		Time::Initailze();
	}

	void Application::Run()
	{
		if (mbLoaded == false)
			mbLoaded = true;

		Update();
		LateUpdate();
		Render();

		Destroy();
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();	

		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		Graphics::GetDevice()->ClearRenderTargetView();
		Graphics::GetDevice()->ClearDepthStencilView();
		Graphics::GetDevice()->BindViewPort();
		Graphics::GetDevice()->BindDefaultRenderTarget();

		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();
		infoTitle();

		Graphics::GetDevice()->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();

		Renderer::Release();
	}

	void Application::infoTitle() {
		float fps = 1.0f / Time::DeltaTime;

		wchar_t str[MAX_LOADSTRING] = L"";
		swprintf(str, MAX_LOADSTRING, L"%ws \tFPS : %d", title, (int)fps);
		int len = wcsnlen_s(str, MAX_LOADSTRING);

		SetWindowText(mHwmd, str);
	}
}
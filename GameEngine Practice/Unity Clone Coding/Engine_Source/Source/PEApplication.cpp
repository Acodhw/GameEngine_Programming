#include "PEApplication.h"
#include "PEInput.h"
#include "PETime.h"
#include "PESceneManager.h"
#include "PEResources.h"

#define MAX_LOADSTRING 100

namespace PracticeEngine {

	Application::Application()
		: mHwmd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(nullptr)
		, mBackBuffer(nullptr)
		, title(new wchar_t[MAX_LOADSTRING])
	{		
	}
	
	Application::~Application() {
		delete[] title;
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();
	}


	void Application::Run() {
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Update() {
		Time::Update(); // 시간 처리를 맨 앞에서
		Input::Update(); // 키 처리를 플레이어 처리보다 빠르게
		SceneManager::Update();

	}
	
	void Application::LateUpdate() {
		SceneManager::LateUpdate();
	}

	void Application::Render() {
		Rectangle(mBackHDC, -5, -5, mWidth + 5, mHeight + 5);
		SceneManager::Render(mBackHDC);

		// BackBuffer를 원본  Buffer에 복사
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY); 
		infoTitle();
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::infoTitle() {
		float fps = 1.0f / Time::DeltaTime;	

		wchar_t str[MAX_LOADSTRING] = L"";
		swprintf(str, MAX_LOADSTRING, L"%ws \tFPS : %d", title, (int)fps);
		int len = wcsnlen_s(str, MAX_LOADSTRING);

		SetWindowTextW(mHwmd, str);
	}


	// private확장자

	void Application::clearRenderTarget()
	{
		//clear
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);

		Rectangle(mBackHDC, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(mBackHDC, oldBrush);
		DeleteObject(grayBrush);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwmd = hwnd;
		mHdc = GetDC(mHwmd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // 윈도우 작업영역을 Rect로 변경(&RECT, 윈도우스타일, 메뉴바)

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwmd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwmd, true);
		GetWindowTextW(mHwmd, title, MAX_LOADSTRING);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼 가르킬 dc 생성
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer); // Buffer에다가 DC 바꿔주고
		DeleteObject(oldBitmap); // 이전 DC는 삭제
	}

	void Application::initializeEtc()
	{
		Input::Initailze();
		Time::Initailze();
		SceneManager::Initialize();
	}
}
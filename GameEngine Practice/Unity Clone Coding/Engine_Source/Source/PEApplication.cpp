#include "PEApplication.h"
#include "PEInput.h"
#include "PETime.h"
#include "PESceneManager.h"

#define MAX_LOADSTRING 100

namespace PracticeEngine {

	Application::Application()
		: mHwmd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(nullptr)
		, mBackBuffer(nullptr)
	{
		title = new wchar_t[MAX_LOADSTRING];		
	}
	
	Application::~Application() {
		delete[] title;
	}
	void Application::Initialize(HWND hwmd, UINT width, UINT height) {
		mHwmd = hwmd;
		mHdc = GetDC(mHwmd);
		
		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // ������ �۾������� Rect�� ����(&RECT, �����콺Ÿ��, �޴���)
		
		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwmd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwmd, true);

		GetWindowText(mHwmd, title, MAX_LOADSTRING);

		// ������ �ػ󵵿� �´� ����� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		//����� ����ų dc ����
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer); // Buffer���ٰ� DC �ٲ��ְ�
		DeleteObject(oldBitmap); // ���� DC�� ����
		
		Input::Initailze();
		Time::Initailze();
		SceneManager::Initialize();
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();

	}

	void Application::Update() {
		Time::Update(); // �ð� ó���� �� �տ���
		Input::Update(); // Ű ó���� �÷��̾� ó������ ������
		SceneManager::Update();
		

	}
	
	void Application::LateUpdate() {
		SceneManager::LateUpdate();
	}

	void Application::Render() {
		Rectangle(mBackHDC, -5, -5, mWidth + 5, mHeight + 5);
		SceneManager::Render(mBackHDC);

		// BackBuffer�� ����  Buffer�� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY); 
		infoTitle();
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void Application::infoTitle() {
		float fps = 1.0f / Time::DeltaTime;	

		wchar_t str[MAX_LOADSTRING] = L"";
		swprintf(str, MAX_LOADSTRING, L"%ws \tFPS : %d", title, (int)fps);
		int len = wcsnlen_s(str, MAX_LOADSTRING);

		SetWindowText(mHwmd, str);
	}
}
// EnginePractice.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "EnginePractice.h"

//#pragma comment(lib, "..\\x64\\Debug\\PracticeEngine_Window.lib")
#include "..\\PracticeEngine_SOURCE\\PEApplication.h"
#include "..\\PracticeEngine_Window\\PELoadScene.h"
#include "..\\PracticeEngine_SOURCE\\PESceneManager.h"
#include "..\\PracticeEngine_SOURCE\\PEResources.h"
#include "..\\PracticeEngine_SOURCE\\PETexture.h"

PracticeEngine::Application application;

ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// WCHAR = 유니코드 저장용 char형 데이터

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndTileProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,             // 프로그램의 인스턴스 핸들(메모리에 저장된 이 프로그램의 공간)
                     _In_opt_ HINSTANCE hPrevInstance,      // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들, 없으면 NULL
                     _In_ LPWSTR    lpCmdLine,              // 명령행으로 입렫된 프로그램 인수(유명한 args)
                     _In_ int       nCmdShow)               // 프로그램 실행될 형태, 모양정보들 저장
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //메모리 누수 체크
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // TODO: 여기에 코드를 입력합니다.
    

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);             // 타이틀 이름 불러오기
    LoadStringW(hInstance, IDC_ENGINEPRACTICE, szWindowClass, MAX_LOADSTRING);  // 창 클래스 이름 불러오기
    MyRegisterClass(hInstance, szWindowClass, WndProc);
    MyRegisterClass(hInstance, L"TILEMAP", WndTileProc);                                                 // 새로운 레지스터 클래스에 인스턴스 대입 (윈도우 정보 보관)

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow)) // 창 생성이 성공적으로 수행되었는지 확인합니다
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ENGINEPRACTICE));

    MSG msg;

    //GetMessage
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    // 메세지큐 == null => 메세지 가져오지 않음
    // 메세지큐가 없으면 멈춤

    // PeekMessage : 
    // 메세지 큐의 메세지 유뮤와 관계없이 함수 리턴
    // 리턴 == true : message 있음, 리턴 == false : message 없음 알려줌
    // 메세지큐 신경 없이 항상 작동


    while (true) // 메세지 큐의 여부와 상관없이 작동하는 루프
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {

            if (msg.message == WM_QUIT)
                break;

            if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);     // 메세지를 번역
                DispatchMessage(&msg);      // 메세지를 적용
            }
        }
        else {
           
            application.Run();
            // 메세지가 없을 경우 여기서 처리
            // 게임 로직 함수 처리
        }

        
    }

    // 기본 메시지 루프입니다 -PeekMessage롷 병합
    /*while (GetMessage(&msg, nullptr, 0, 0)) // 메세지가 받는 경우에만 루프
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);     // 메세지를 번역
            DispatchMessage(&msg);      // 메세지를 적용
        }
    }*/
    Gdiplus::GdiplusShutdown(gpToken); // 메모리에서 토큰 제거
    application.Release();
    return (int) msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ENGINEPRACTICE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ENGINEPRACTICE);
    wcex.lpszClassName  = name;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
    const UINT width = 1600;
    const UINT height = 900;

    // 창 생성 함수(윈도우 스타일, 타이틀 이름, 윈도우 형태, 윈도우 생성 위치x, y, 가로세로 크기x, y, 부모 윈도우, 메뉴 정보, 창 인스턴스, 좌표 저장하는 파라미터)
    // 반환 => 핸들 반환(윈도우가 가지고 있는 주소의 위치)
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

    HWND ToolHwnd = CreateWindowW(L"TILEMAP", L"TileMap", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 480, 960, nullptr, nullptr, hInstance, nullptr);

    application.Initialize(hWnd, width, height);
    //2개 이상 윈도우 생성 가능
    // HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
    //     CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);  // 윈도우 보이기
    UpdateWindow(hWnd);          // 윈도우 창 업데이트


   

    Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL); // gdiplus로 이미지 불러오기 시작(포인터 토큰, gdi인풋, gdi 아웃풋)

    PracticeEngine::LoadScenes(); // 씬 로딩

    PracticeEngine::Scene* activeScene = PracticeEngine::SceneManager::GetActiveScene();
    std::wstring name = activeScene->GetName();
    if (name == L"ToolScene")
    {
        ShowWindow(ToolHwnd, nCmdShow);
        UpdateWindow(ToolHwnd);

        //Tile 윈도우 크기 조정
        PracticeEngine::Graphics::Texture* texture
            = PracticeEngine::Resources::Find<PracticeEngine::Graphics::Texture>(L"TL");

        RECT rect = { 0, 0, texture->width, texture->height };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        UINT toolWidth = rect.right - rect.left;
        UINT toolHeight = rect.bottom - rect.top + texture->height;

        SetWindowPos(ToolHwnd, nullptr, width, 0, toolWidth, toolHeight, 0);
        ShowWindow(ToolHwnd, true);
        UpdateWindow(ToolHwnd);
    }
    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

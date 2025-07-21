// EnginePractice.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "EnginePractice.h"

#define MAX_LOADSTRING 100

// WCHAR = 유니코드 저장용 char형 데이터

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,             // 프로그램의 인스턴스 핸들(메모리에 저장된 이 프로그램의 공간)
                     _In_opt_ HINSTANCE hPrevInstance,      // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들, 없으면 NULL
                     _In_ LPWSTR    lpCmdLine,              // 명령행으로 입렫된 프로그램 인수(유명한 args)
                     _In_ int       nCmdShow)               // 프로그램 실행될 형태, 모양정보들 저장
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);             // 타이틀 이름 불러오기
    LoadStringW(hInstance, IDC_ENGINEPRACTICE, szWindowClass, MAX_LOADSTRING);  // 창 클래스 이름 불러오기
    MyRegisterClass(hInstance);                                                 // 새로운 레지스터 클래스에 인스턴스 대입 (윈도우 정보 보관)

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow)) // 창 생성이 성공적으로 수행되었는지 확인합니다
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ENGINEPRACTICE));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0)) // 사용자의 반응(메세지)
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);     // 메세지를 번역
            DispatchMessage(&msg);      // 메세지를 적용
        }
    }

    return (int) msg.wParam;
}


//캐릭터 구현



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ENGINEPRACTICE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ENGINEPRACTICE);
    wcex.lpszClassName  = szWindowClass;
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

   // 창 생성 함수(윈도우 스타일, 타이틀 이름, 윈도우 형태, 윈도우 생성 위치x, y, 가로세로 크기x, y, 부모 윈도우, 메뉴 정보, 창 인스턴스, 좌표 저장하는 파라미터)
   // 반환 => 핸들 반환(윈도우가 가지고 있는 주소의 위치)
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr); 

  //2개 이상 윈도우 생성 가능
  // HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
  //     CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);  // 윈도우 보이기
   UpdateWindow(hWnd);          // 윈도우 창 업데이트

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

        HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // 브러쉬 생성(어떤 브러쉬가 그림이 그려질지)
        HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc에게 브러쉬 대입 이후 오래된(이전에) 브러쉬 리턴

        Rectangle(hdc, 100, 100, 200, 200); // 사각형 그리는 함수

        (HBRUSH)SelectObject(hdc, oldbr); // 오래된 브러쉬로 돌려놓기
        DeleteObject(br); // 생성된 브러쉬를 제거

        HPEN p = CreatePen(PS_SOLID, 10,  RGB(255, 0, 0)); // 같은 원리를 펜에 적용
        HPEN oldp = (HPEN)SelectObject(hdc, p);

        Ellipse(hdc, 200, 300, 500, 700);

        (HBRUSH)SelectObject(hdc, oldp);

        DeleteObject(p);
        // DC = 화면 출력에 필요한 모든 데이터를 가지는 구조체
        // GDI 모듈에 의해 관리
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

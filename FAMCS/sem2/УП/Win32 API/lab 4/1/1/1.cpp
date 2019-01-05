// 1.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "1.h"
#include <string.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd, hChild, hButtonUp, hButtonH, hButtonCreate, hButtonDelete, hEdit, hButtonMove;
static RECT rc;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
ATOM				MyRegisterClassChild(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProcChild(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY1, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);
	MyRegisterClassChild(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//  ФУНКЦИЯ: MyRegisterClassChild ()
//
//  НАЗНАЧЕНИЕ: регистрирует класс дочернего окна.
//
ATOM MyRegisterClassChild(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProcChild;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDI_MY1);
	wcex.lpszClassName = L"дочернее";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   // дочернее окно создается невидимым
   hChild = CreateWindow(L"дочернее", L"управляемое", WS_CHILDWINDOW | WS_BORDER | WS_CAPTION, 170, 100, 300, 200, hWnd, NULL, hInstance, NULL);
  // hEdit = CreateWindow(L"edit", L"300x200", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 50, 50, 190, 30, hChild, 0, hInstance, NULL);
   hButtonCreate = CreateWindow(L"button", L"отобразить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 50, 100, 40, hWnd, (HMENU)ID_ButtonCreate, hInstance, NULL);
   hButtonDelete = CreateWindow(L"button", L"скрыть", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 100, 100, 40, hWnd, (HMENU)ID_ButtonDelete, hInstance, NULL);
   hButtonUp = CreateWindow(L"button", L"вверх", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 150, 100, 40, hWnd, (HMENU)ID_ButtonUp, hInstance, NULL);
   hButtonH = CreateWindow(L"button", L"расширить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 200, 100, 40, hWnd, (HMENU)ID_ButtonH, hInstance, NULL);
   hButtonMove = CreateWindow(L"button", L"вернуть", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 250, 100, 40, hWnd, (HMENU)ID_ButtonMove, hInstance, NULL);
   GetWindowRect(hChild, &rc);
   MapWindowPoints(NULL, hWnd, (LPPOINT)&rc, 2);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT child_rect;
	//static RECT rc = {170, 100, 400, 300 };
	GetWindowRect(hChild, &child_rect);
	int width = child_rect.right - child_rect.left;
	int height = child_rect.bottom - child_rect.top;
	char* str = new char[10];
	char* size = new char[4];
	//координаты и размеры дочернего окна
	static int nChildLeft = 170, nChildTop = 100, nChildWidht = 300, intChildHeight = 200;

	switch (message)
	{
	case WM_COMMAND:
	{
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:
		switch (wmId)
		{
		case ID_ButtonCreate:
			ShowWindow(hChild, SW_SHOWNORMAL);
			break;
		case ID_ButtonUp:
			MoveWindow(hChild, nChildLeft, nChildTop--, nChildWidht, intChildHeight, TRUE);
			break;
		case ID_ButtonH:
			MoveWindow(hChild, nChildLeft, nChildTop, nChildWidht++, intChildHeight, TRUE);
			#define _CRT_SECURE_NO_WARNINGS
			#pragma warning(disable : 4996)
			strcpy(str, _itoa(width, size, 10));
			strcat(str, "x");
			strncat(str, _itoa(height, size, 10), strlen(_itoa(height, size, 10)));
			SetWindowTextA(hEdit, str);
			break;
		case ID_ButtonDelete:
			ShowWindow(hChild, SW_HIDE);
			break;
		case ID_ButtonMove:
			MoveWindow(hChild, rc.left, rc.top, width, height, TRUE);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break; }
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//  ФУНКЦИЯ: WndProcChild (HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в дочернем окне.
LRESULT CALLBACK WndProcChild(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: добавьте любой код отрисовки...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
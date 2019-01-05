// 2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "2.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
static HMENU hMainMenu, hMenuFile, hMenuSetup;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
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
    LoadStringW(hInstance, IDC_MY2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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

   hMainMenu = CreateMenu();
   hMenuFile = CreatePopupMenu();
   AppendMenu(hMenuFile, MF_STRING, ID_OPEN, _T("Open file"));
   AppendMenu(hMenuFile, MF_SEPARATOR, 0, NULL);
   AppendMenu(hMenuFile, MF_STRING, ID_EXIT, _T("Exit"));

   hMenuSetup = CreatePopupMenu();
   AppendMenu(hMenuSetup, MF_STRING, ID_COLOR, _T("Color"));
   AppendMenu(hMenuSetup, MF_STRING, ID_FONT, _T("Font"));
   AppendMenu(hMainMenu, MF_POPUP, (UINT)hMenuFile, _T("File"));
   AppendMenu(hMainMenu, MF_POPUP, (UINT)hMenuSetup, _T("Setup"));
   AppendMenu(hMainMenu, MF_STRING, ID_HELP, _T("Help"));

   SetMenu(hWnd, hMainMenu);
   DrawMenuBar(hWnd);

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
	//int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
	{	UINT idCtl = LOWORD(wParam); // идентификатор дочернего окна
	UINT code = HIWORD(wParam);  // код уведомлени€
	HWND hChild = (HWND)lParam;  // дескриптор дочернего окна
	if (lParam != 0)
	{
		// сообщение от элемента управлени€ - другой способ обработки
	}
	else
	{
		UINT idItem = LOWORD(wParam); // идентификатор пункта меню
		switch (idItem)
		{
		case ID_OPEN:
			MessageBox(hWnd, _T(" ¬ыбран пункт меню open"), _T("Window"),
				MB_OK | MB_ICONINFORMATION);// пункт меню выбран
			break;
		case ID_EXIT:
			PostQuitMessage(0);  // закрыть приложение
			break;
		case ID_COLOR:
			MessageBox(hWnd, _T(" ¬ыбран пункт меню color"), _T("Window"),
				MB_OK | MB_ICONINFORMATION); // пункт меню выбран
			break;
		case ID_FONT:
			MessageBox(hWnd, _T(" ¬ыбран пункт меню font"), _T("Window"),
				MB_OK | MB_ICONINFORMATION); // пункт меню выбран
			break;
		case ID_HELP:
			MessageBox(hWnd, _T("¬ыбран пункт меню Help"), _T("Window"),
				MB_OK | MB_ICONINFORMATION); // пункт меню выбран
			break;
		}
	}
	};
	return 0;
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

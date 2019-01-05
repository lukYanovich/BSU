// 3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "3.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_MY3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY3);
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
	HBRUSH hBrush;
	HPEN hPen;
	POINT points[4];
	RECT rect;
	BYTE polytype[8];
	GetClientRect(hWnd, &rect);
	HRGN ship;
	HRGN flag;
	bool Move = 1;
	static int x = rect.left;
	static int y = rect.top + 250;

	//static int	Phase=0, Width, Height;
    switch (message)
    {
	case WM_CREATE:
		SetTimer(hWnd, ID_TIMER, 25, NULL);
		return 0;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		if (Move)
		{
			x += 30;
			if (x >= rect.right)
			{
				y += 25;
				x = rect.left;
			}
		}
		if ((x >= rect.right) && (y >= rect.bottom))
			KillTimer(hWnd, ID_TIMER);
		break;
    case WM_COMMAND:
        {
            wmId = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
            // Parse the menu selections:
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
        }
        break;
    case WM_PAINT:
        {
			hdc = BeginPaint(hWnd, &ps);
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			MoveToEx(hdc, rect.left + 350, rect.top + 150, NULL);
			points[0].x = rect.right - 350;
			points[0].y = rect.top + 150;
			points[1].x = rect.right - 400;
			points[1].y = rect.top + 250;
			points[2].x = rect.left + 400;
			points[2].y = rect.top + 250;
			points[3].x = rect.left + 350;
			points[3].y = rect.top + 150;
			polytype[0] = PT_LINETO;
			polytype[1] = PT_LINETO;
			polytype[2] = PT_LINETO;
			polytype[3] = PT_LINETO;
			polytype[4] = PT_LINETO;
			polytype[5] = PT_LINETO;
			polytype[6] = PT_LINETO;
			polytype[7] = PT_LINETO;
			PolyDraw(hdc, points, polytype, 4);
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			ship = CreatePolygonRgn(points, 4, WINDING);
			PaintRgn(hdc, ship);
			MoveToEx(hdc, rect.right / 2, rect.top + 150, NULL);
			points[0].x = rect.right / 2;
			points[0].y = rect.top + 20;
			points[1].x = rect.right / 2 + 150;
			points[1].y = rect.top + 80;
			points[2].x = rect.right / 2;
			points[2].y = rect.top + 130;
			PolyDraw(hdc, points, polytype, 3);
			hBrush = CreateSolidBrush(RGB(255, 255, 11));
			SelectObject(hdc, hBrush);
			flag = CreatePolygonRgn(points, 3, WINDING);
			PaintRgn(hdc, flag);
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			SelectObject(hdc, hPen);
			Arc(hdc, x, y, x + 30, y + 50, x + 30, y + 25, x, y + 25);
			// TODO: Add any drawing code here...
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

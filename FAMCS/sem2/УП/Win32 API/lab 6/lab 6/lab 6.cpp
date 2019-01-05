// lab 6.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "lab 6.h"
#include <stdio.h>
#include <winbase.h>
#include <Commdlg.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
static HMENU hMainMenu, hMenuFile, hMenuSetup;

//Для шрифта
static char FontStyle[LF_FACESIZE];
static LOGFONT log_font;
static HFONT font;
CHOOSEFONT CF;
//Для цвета
static COLORREF rgb_text, CustColors[16];
CHOOSECOLOR CC;
static char fullpath[256], filename[256], dir[256];
OPENFILENAME ofn;

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
    LoadStringW(hInstance, IDC_LAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB6);
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
   AppendMenu(hMenuFile, MF_STRING, ID_SAVE_AS, _T("Save As File"));
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
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
			int wmEvent = HIWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case ID_OPEN:
			{
				sprintf(fullpath, ""); sprintf(filename, ""); sprintf(dir, "");
				memset(&ofn, 0, sizeof(ofn));
				ZeroMemory(&ofn, sizeof(OPENFILENAME));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hWnd;
				ofn.hInstance = hInst; // дескриптор копии приложения
				ofn.lpstrFilter = _T("Текстовые файлы (*.txt)\0*.txt\0Все файлы (*.*)\0*.*\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFile = (LPWSTR)fullpath;
				ofn.nMaxFile = sizeof(fullpath);
				ofn.lpstrFileTitle = (LPWSTR)filename;
				ofn.nMaxFileTitle = sizeof(filename);
				ofn.lpstrInitialDir = (LPWSTR)dir;
				ofn.lpstrTitle = _T("Открыть в файле с именем...");
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY | OFN_EXPLORER;
				bool iCode = GetOpenFileName(&ofn);
				sprintf(dir, "%s", fullpath); dir[ofn.nFileOffset - 1] = '\0';
				if (iCode)
				{
					// пользователь выбрал файл, полное имя которого хранится в fullpath
				}
				break;
			}

			case ID_SAVE_AS:
			{
				sprintf(fullpath, ""); sprintf(filename, ""); sprintf(dir, "");
				ZeroMemory(&ofn, sizeof(OPENFILENAME));
				memset(&ofn, 0, sizeof(OPENFILENAME));
				ofn.lStructSize = sizeof(OPENFILENAME);
				ofn.hwndOwner = hWnd;
				ofn.hInstance = hInst; // дескриптор копии приложения
				ofn.lpstrFilter = _T("Текстовые файлы (*.txt)\0*.txt\0Все файлы (*.*)\0*.*\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFile = (LPWSTR)fullpath;
				ofn.nMaxFile = sizeof(fullpath);
				ofn.lpstrFileTitle = (LPWSTR)filename;
				ofn.nMaxFileTitle = sizeof(filename);
				ofn.lpstrInitialDir = (LPWSTR)dir;
				ofn.lpstrTitle = _T("Сохранить в файле с именем...");
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY | OFN_EXPLORER;
				bool iCode = GetSaveFileName(&ofn);
				sprintf(dir, "%s", fullpath); dir[ofn.nFileOffset - 1] = '\0';
				if (iCode)
				{
					// пользователь выбрал файл, полное имя которого хранится в fullpath
				}
				break;
			}
			case ID_COLOR:
			{
				rgb_text = RGB(0, 0, 255);
				for (int i = 0; i<16; i++) CustColors[i] = 0;
				memset(&CC, 0, sizeof(CHOOSECOLOR));
				CC.lStructSize = sizeof(CHOOSECOLOR);
				CC.hwndOwner = hWnd;
				CC.hInstance = hWnd;
				CC.lpCustColors = CustColors;
				CC.Flags = CC_RGBINIT | CC_FULLOPEN;
				CC.rgbResult = rgb_text;

				if (ChooseColor(&CC))
				{
					// пользователь выбрал цвет, информация о нем хранится в CC.rgbResult
					rgb_text = CC.rgbResult;
				}
				break;
			}

			case ID_FONT:
			{
				memset(&log_font, 0, sizeof(LOGFONT));
				log_font.lfWeight = FW_NORMAL;
				log_font.lfCharSet = ANSI_CHARSET;
				log_font.lfOutPrecision = OUT_DEFAULT_PRECIS;
				log_font.lfClipPrecision = CLIP_DEFAULT_PRECIS;
				log_font.lfQuality = DEFAULT_QUALITY;
				log_font.lfPitchAndFamily = DEFAULT_PITCH | FF_MODERN;
				sprintf(FontStyle, "System"); sprintf((char*)log_font.lfFaceName, "System");
				font = CreateFontIndirect(&log_font);
				memset(&CF, 0, sizeof(CHOOSEFONT));
				CF.lStructSize = sizeof(CHOOSEFONT);
				CF.hwndOwner = hWnd;
				CF.hInstance = hInst;
				CF.lpLogFont = &log_font;
				CF.Flags = CF_SCREENFONTS | CF_EFFECTS | CF_INITTOLOGFONTSTRUCT;
				CF.rgbColors = RGB(0, 0, 0);
				CF.lpszStyle = (LPWSTR)FontStyle;
				CF.nFontType = SCREEN_FONTTYPE;
				CF.nSizeMin = 4;
				CF.nSizeMax = 100;

				if (ChooseFont(&CF))
				{
					// пользователь выбрал шрифт, информация о нем хранится в log_font
					font = CreateFontIndirect(&log_font);
				}
				break;
			}

			case ID_HELP:
			{
				MessageBox(hWnd, _T("Выбран пункт меню Help"), _T("Window"), MB_OK | MB_ICONINFORMATION); // пункт меню выбран
				break;
			}

			case ID_EXIT:
			{
				PostQuitMessage(0);  // закрыть приложение
				break;
			}



            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
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

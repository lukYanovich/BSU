// 1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "1.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd, hButtonSelect, hList, hButtonExit, hCombo, hEdit;

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
    LoadStringW(hInstance, IDC_MY1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

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

	hButtonSelect = CreateWindow(L"button", L"смени цвет на следующий", WS_CHILD | BS_DEFPUSHBUTTON | WS_VISIBLE, 20, 20, 190, 30, hWnd, (HMENU)ID_ButtonSelect, hInstance, NULL);

	hList = CreateWindow(L"listbox", NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY, 20, 60, 190, 100, hWnd, (HMENU)ID_List, hInstance, NULL);

	hButtonExit = CreateWindow(L"button", L"выход", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 250, 20, 190, 30, hWnd, (HMENU)ID_ButtonExit, hInstance, NULL);

	hCombo = CreateWindow(L"combobox", NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | CBS_SIMPLE | CBS_DROPDOWNLIST, 20, 185, 190, 160, hWnd, (HMENU)ID_Combo, hInstance, NULL);

	//hEdit = CreateWindow(L"edit", L"255,236,128", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 250, 220, 190, 30, hWnd, 0, hInstance, NULL);

	//  заполним списки названиями цветов, хранящихся в массиве Color
	char Color[6][8] = { "желтый","зеленый","красный","синий","белый","серый" };
	int i;
	for (i = 0; i < 6; i++)
	{
		SendMessageA(hList, LB_ADDSTRING, 0, (LPARAM)Color[i]);
		SendMessageA(hCombo, CB_ADDSTRING, 0, (LPARAM)Color[i]);
	}


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
	int nSelect = 0;//номер выбранной строки
	HRGN hReg = CreateRectRgn(250, 60, 440, 205);//прямоугольная область для окрашивания
	HBRUSH hBr;//кисть  
	static COLORREF mycolor;//текущий цвет
	static int Red, Green, Blue;
	char* str = new char[20];
	char* razd = ",";
	char* color = new char[4];
	//набор цветов
	static COLORREF color_set[6] = { RGB(255,236,128), RGB(0,255,0), RGB(255,0,0), RGB(0,0,255), RGB(255,255,255), RGB(118,118,118) };

    switch (message)
    {
    case WM_COMMAND://  какой элемент управления послал сообщение
	{
		switch (LOWORD(wParam))
		{
			// нажата кнопка смены цвета
		case ID_ButtonSelect:
			// посылаем сообщение списку и узнаем, какая в нем выбрана строка
			//увеличиваем номер и сохраняем в nSelect
			nSelect = SendMessage(hList, LB_GETCURSEL, 0, 0L) + 1;
			// если была выбрана последняя строка, то следующей будет первая
			if (nSelect >= SendMessage(hList, LB_GETCOUNT, 0, 0L)) nSelect = 0;
			//посылаем сообщения спискам, чтобы выбрать в них строку nSelect
			SendMessage(hList, LB_SETCURSEL, (WPARAM)nSelect, 0L);
			SendMessage(hCombo, CB_SETCURSEL, (WPARAM)nSelect, 0L);
			Red = (int)GetRValue(color_set[nSelect]);
			Green = (int)GetGValue(color_set[nSelect]);
			Blue = (int)GetBValue(color_set[nSelect]);
			strcpy(str, itoa(Red, color, 10));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Green, color, 10), strlen(itoa(Green, color, 10)));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Blue, color, 10), strlen(itoa(Blue, color, 10)));
			SetWindowTextA(hEdit, str);
			break;
			// пришло сообщение от списка
		case ID_List:
			// выясняем, какую строку выбрали 
			nSelect = SendMessage(hList, LB_GETCURSEL, 0, 0L);
			// устанавливаем тот же выбор в выпадающем списке
			SendMessage(hCombo, CB_SETCURSEL, (WPARAM)nSelect, 0L);
			Red = (int)GetRValue(color_set[nSelect]);
			Green = (int)GetGValue(color_set[nSelect]);
			Blue = (int)GetBValue(color_set[nSelect]);
			strcpy(str, itoa(Red, color, 10));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Green, color, 10), strlen(itoa(Green, color, 10)));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Blue, color, 10), strlen(itoa(Blue, color, 10)));
			SetWindowTextA(hEdit, str);
			break;
			// пришло сообщение от выпадающего списка
		case ID_Combo:  nSelect = SendMessage(hCombo, CB_GETCURSEL, 0, 0L);
			SendMessage(hList, LB_SETCURSEL, (WPARAM)nSelect, 0L);
			Red = (int)GetRValue(color_set[nSelect]);
			Green = (int)GetGValue(color_set[nSelect]);
			Blue = (int)GetBValue(color_set[nSelect]);
			strcpy(str, itoa(Red, color, 10));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Green, color, 10), strlen(itoa(Green, color, 10)));
			strncat(str, razd, strlen(razd));
			strncat(str, itoa(Blue, color, 10), strlen(itoa(Blue, color, 10)));
			SetWindowTextA(hEdit, str);
			break;
			// пришло сообщение от кнопки Выход
		case ID_ButtonExit:
			// посылаем сообщение главному окну о завершении работы
			SendMessage(hWnd, WM_DESTROY, 0, 0L);
			break;
		}

		// определяем, какой цвет выбрали	
		mycolor = color_set[nSelect];
		// помечаем главное окно как целиком требующее обновления	
		InvalidateRect(hWnd, 0, TRUE);
		// обновляем окно, ему придет сообщение WM_PAINT
		UpdateWindow(hWnd); 
	}
		break;
		//это сообщение будет приходить каждый раз, когда окно будет изменять свое состояние с активного на неактивное 
	case WM_ACTIVATE:
		nSelect = 0;
		SendMessage(hCombo, CB_SETCURSEL, (WPARAM)nSelect, 0L);
		SendMessage(hList, LB_SETCURSEL, (WPARAM)nSelect, 0L);
		mycolor = color_set[nSelect];
		InvalidateRect(hWnd, 0, TRUE);
		UpdateWindow(hWnd);
		break;
		//сообщение о перерисовке содержимого окна
    case WM_PAINT:
		//получаем контекст для рисования
		hdc = BeginPaint(hWnd, &ps);
		//создаем сплошную кисть нужного цвета
		hBr = CreateSolidBrush(mycolor);
		//окрашиваем область hReg кистью hBr
		FillRgn(hdc, hReg, hBr);
		//создаем сплошную кисть черного цвета
		hBr = CreateSolidBrush(RGB(0, 0, 0));
		//рисуем рамку вокруг области
		FrameRgn(hdc, hReg, hBr, 1, 1);
		//заканчиваем рисовать
		EndPaint(hWnd, &ps);
		break;
		//сообщение о завершении работы
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

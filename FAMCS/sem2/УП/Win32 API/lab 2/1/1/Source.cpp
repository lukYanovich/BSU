#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <tchar.h>

#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmd)
{
	static TCHAR szWindowClass[] = _T("win32app");
	TCHAR szTitle[] = _T("easy paint");

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	HWND hwnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	ShowWindow(hwnd, nCmd);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;				// структура для рисования
	HBRUSH hbrush, hbrush2;

	static int x1 = 20, y1 = 20;	// координаты левого верхнего угла прямоугольника
	static int x2 = 130, y2 = 130;	// координаты правого нижнего угла прямоугольника
	static int xx1 = 20, yy1 = 20;
	static int xx2 = 130, yy2 = 130;
	static int x, y;	// текущие координаты курсора
	static HRGN l, r;	//области, помечающие углы прямоугольника
	static HRGN l1;		//область прямоугольника
	static BOOL InReg_l = 0, InReg_r = 0, InReg_l1 = 0;		//флаги, показывающие за какой угол двигают прямоугольник

	//создадим кисти для окрашивания областей
	hbrush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));
	hbrush2 = CreateSolidBrush(RGB(0, 0, 255));

	//определим текущую координату курсора(передается в lParam)
	x = LOWORD(lParam);
	y = HIWORD(lParam);


	switch (msg)
	{
	case WM_LBUTTONDOWN:
		InReg_l = 0; InReg_r = 0;
		//если курсор в левом кружке, то устанавливаем флаг InReg_l=1
		if (PtInRegion(l, x, y)) InReg_l = 1;
		//если курсор в правом кружке, то устанавливаем флаг InReg_r=1
		else if (PtInRegion(r, x, y)) InReg_r = 1;
		//иначе ни в какой кружок не попали
		else MessageBoxA(NULL, "не попали в квадрат!", "Сообщение", MB_OK);
		return 0;
		break;
	case WM_RBUTTONDOWN:
		InReg_l1 = 0;
		//если курсор в левом кружке, то устанавливаем флаг InReg_l=1
		if (PtInRegion(l1, x, y)) InReg_l1 = 1;//если курсор в правом кружке, то устанавливаем флаг InReg_r=1
		else MessageBoxA(NULL, "рисунок обновлён", "Сообщение", MB_OK);
		return 0;
		break;
		//отжата левая кнопка мыши
	case WM_LBUTTONUP:
		// сбрасываем флаги 
		InReg_l = 0;
		InReg_r = 0;
		return 0;
		break;
	case WM_RBUTTONUP:
		// сбрасываем флаги 
		InReg_l1 = 0;
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
		return 0;
		break;
		//мышь перемещается
	case WM_MOUSEMOVE:
		// если в левом кружке,то изменяем координаты обоих углов
		if (InReg_l)
		{
			x2 = x2 + (x - x1);
			y2 = y2 + (y - y1);
			x1 = x;
			y1 = y;
			//требуем перерисовки окна  
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
		}
		// если в правом кружке, то изменяем координаты нижнего угла
		if (InReg_r)
		{
			x2 = x;
			y2 = y;
			//требуем перерисовки окна  
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
		}
		if (InReg_l1)
		{
			x2 = x2 + (x - x1);
			y2 = y2 + (y - y1);
			x1 = x;
			y1 = y;//требуем перерисовки окна  
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
		}
		return 0;
		break;
		/*case WM_RBUTTONDOWN:
		{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;

		InvalidateRect(hwnd,NULL,TRUE);
		UpdateWindow(hwnd);
		}*/
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, x1, y1, x2, y2); // рисуем прямоугольник
		l = CreateEllipticRgn(x1 - 8, y1 + 8, x1 + 8, y1 - 8);
		r = CreateEllipticRgn(x2 - 8, y2 + 8, x2 + 8, y2 - 8);
		l1 = CreateRectRgn(x1, y1, x2, y2);
		FillRgn(hdc, l, hbrush); FillRgn(hdc, r, hbrush);
		FrameRgn(hdc, r, hbrush2, 1, 1); FrameRgn(hdc, l, hbrush2, 1, 1);
		EndPaint(hwnd, &ps);
		return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
		break;
	}
	return 0;
}
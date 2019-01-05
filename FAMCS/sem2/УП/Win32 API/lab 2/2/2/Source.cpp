#undef UNICODE
#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <tchar.h>

int countParts = 4;

HPEN hVioletPen;
HBRUSH hPinkBrush;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Lab 2 - 2";

void Line(HDC, double, double, double, double);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!hPrevInstance)
	{
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS  wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_HELP);
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE - 9);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_DESTROY:
		DeleteObject(hVioletPen);
		DeleteObject(hPinkBrush);
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		hVioletPen = CreatePen(PS_SOLID, 2, RGB(59, 18, 35));
		hPinkBrush = CreateSolidBrush(RGB(158, 104, 128));
		break;
	case WM_PAINT:

		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		RECT R;
		GetClientRect(hwnd, &R);

		INT width;
		width = (R.right - R.left) / 4;

		for (int i = 0; i < countParts - 1; i++){
			Line(hdc, width*(i + 1), R.top, width*(i + 1), R.bottom);
		}

		TextOut(hdc, R.right / 8 - 49, 5, "Прямоугольник", 13);
		TextOut(hdc, 3 * (R.right / 8) - 15, 5, "Ромб", 4);
		TextOut(hdc, 5 * (R.right / 8) - 23, 5, "Эллипс", 6);
		TextOut(hdc, 7 * (R.right / 8) - 25, 5, "Сектор", 6);

		SelectBrush(hdc, hPinkBrush);
		SelectPen(hdc, hVioletPen);

		// Прямоугольник
		Rectangle(hdc, R.left + 10, R.top + 40, R.right / 4 - 10, R.bottom - 40);

		//Ромб
		int x1, y1, x2, y2, x3, y3, x4, y4;
		x1 = 1.5* width;
		y1 = R.top + 20;
		x2 = width * 2 - 10;
		y2 = (R.bottom - R.top) / 2;
		x3 = x1;
		y3 = R.bottom - 20;
		x4 = width + 10;
		y4 = y2;

		Line(hdc, x1, y1, x2, y2);
		Line(hdc, x2, y2, x3, y3);
		Line(hdc, x3, y3, x4, y4);
		Line(hdc, x4, y4, x1, y1);

		// Эллипс
		Ellipse(hdc, 2 * width + 10, R.top + 40, 3 * width - 10, R.bottom - 40);

		y1 = (R.bottom - R.top) / 2 + (width - 20) / 2;
		y2 = (R.bottom - R.top) / 2 - (width - 20) / 2;

		int temp;
		temp = (width - 20) * sqrt(2) / 4;
		//Сектор
		Pie(hdc, 3 * width + 10, y1, 4 * width - 10, y2,
			3.5*width - temp, (R.bottom - R.top) / 2 + temp, 3.5*width, y1);

		EndPaint(hwnd, &ps);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

void Line(HDC hdc, double x1, double y1, double x2, double y2){
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	return;
}
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.lpszClassName = L"My Class";
	RegisterClass(&w);
	hwnd = CreateWindow(L"My Class", L"Win Api 32", WS_OVERLAPPEDWINDOW,
		300, 200, 400, 400, NULL, NULL, hInstance, NULL);

	//button1
	CreateWindow(L"button", L"+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 10,//coord-s of left up corner
		80, 30,   //width, height
		hwnd, (HMENU)10000, hInstance, NULL);
	//button2
	CreateWindow(L"button", L"-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 10,
		80, 30,
		hwnd, (HMENU)10001, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	HDC hdc; //контекст для рисования
	HFONT hf; //шрифт для рисования
	static LOGFONT font; //структура для логического шрифта
	static int xtext, ytext; //координаты текста для вывода

	PAINTSTRUCT ps; //структура для рисования


	switch (Message) {

	case WM_COMMAND:
		if (LOWORD(wparam) == 10000) //была нажата первая кнопка
			font.lfHeight += 1;
		else if (LOWORD(wparam) == 10001)//вторая кнопка
			font.lfHeight -= 1;

		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		hf = CreateFontIndirect(&font);
		SelectObject(hdc, hf);

		TextOut(hdc, xtext, ytext, L"Some text", 10);

		DeleteObject(hf);
		EndPaint(hwnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		font.lfHeight = 20;
		font.lfWidth = 0; //use default value
		font.lfEscapement = 0; //without slope
		font.lfOrientation = 0;
		font.lfWeight = 0; //default
		font.lfItalic = 0;
		font.lfUnderline = 0;
		font.lfStrikeOut = 0;
		font.lfCharSet = DEFAULT_CHARSET;
		font.lfOutPrecision = OUT_DEFAULT_PRECIS;
		font.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		font.lfQuality = DEFAULT_QUALITY;
		font.lfPitchAndFamily = VARIABLE_PITCH | FF_DONTCARE;
		strcpy((char*)font.lfFaceName, "Arial");

		xtext = 150, ytext = 150;
		break;

	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}
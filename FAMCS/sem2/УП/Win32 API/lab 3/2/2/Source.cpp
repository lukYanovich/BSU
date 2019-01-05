#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include <windows.h>
#include <windowsx.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "WinAPI Lab";

void Line(HDC, double, double, double, double);

HPEN hVioletPen;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его значение */
	if (!hPrevInstance)
	{  /* инициализируем приложение -  подготавливаем данные класса окна и регистрируем его */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* завершаем создание копии приложения -     создаем главное окно приложения */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* Цикл обработки сообщений */
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
	// Заполняем структуру класса окна WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_SHIELD); // иконка
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//курсор
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 16);//+15); // цвет заднего окна
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// Регистрируем класс окна
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		szTitle,             // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT,       // горизонтальная координата окна
		CW_USEDEFAULT,       // вертикальная координата окна
		CW_USEDEFAULT,       // ширина окна
		CW_USEDEFAULT,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_MAXIMIZE); //размер открывающегося окна с запуска... А нет, просто разные флаги открытия... Но я в них не разобралась =\... Нашла! Щупак стр 42
	UpdateWindow(hWnd);
	return (TRUE);
}

void parallelogram(HDC hdc, int left, int top, int right, int bottom);
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int         cxClient, cyClient;
	static HDC         hdc;

	PAINTSTRUCT        ps;
	HFONT hFontN, hFontO;
	static LOGFONT lf;
	static RECT rect;
	static int x1 = 16, y1 = 4;

	switch (iMsg)
	{

	case WM_CREATE:
		hVioletPen = CreatePen(PS_SOLID, 4, RGB(59, 18, 35));
		break;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		rect.left = cxClient / 3;
		rect.top = cyClient / 3;
		rect.right = 2 * cxClient / 3;
		rect.bottom = 2 * cyClient / 3;

		lf.lfWidth = (rect.right - rect.left) / x1;
		lf.lfHeight = (rect.bottom - rect.top) / y1;
		strcpy(lf.lfFaceName, "Times New Roman");

		break;

	case WM_RBUTTONDOWN:
		rect.left -= 10;
		rect.bottom += 10;
		rect.right += 10;
		rect.top -= 10;
		lf.lfWidth = (rect.right - rect.left) / x1;
		lf.lfHeight = (rect.bottom - rect.top) / y1;
		InvalidateRect(hwnd, NULL, true);

		break;

	case WM_LBUTTONDOWN:
		rect.left += 10;
		rect.bottom -= 10;
		rect.right -= 10;
		rect.top += 10;
		lf.lfWidth = (rect.right - rect.left) / x1;
		lf.lfHeight = (rect.bottom - rect.top) / y1;
		InvalidateRect(hwnd, NULL, true);
		break;

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(WHITE_BRUSH));
		SelectPen(hdc, hVioletPen);
		parallelogram(hdc, rect.left, rect.top, rect.right, rect.bottom);
		hFontN = CreateFontIndirect(&lf);
		hFontO = (HFONT)SelectObject(hdc, hFontN);
		SetBkMode(hdc, TRANSPARENT);


		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		DeleteObject(hVioletPen);
		break;

	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
	return 0;
}

void Line(HDC hdc, double x1, double y1, double x2, double y2){
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	return;
}

void parallelogram(HDC hdc, int left, int top, int right, int bottom){
	int w = right - left;
	int h = bottom - top;
	Line(hdc, left, top, right, top);
	Line(hdc, right, top, right, bottom);
	Line(hdc, right, bottom, left, bottom);
	Line(hdc, left, bottom, left, top);
}
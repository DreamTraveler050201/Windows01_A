#include <Windows.h>

typedef HINSTANCE HINST;

#define API WINAPI
#define msgbox MessageBox

HINSTANCE hInst;
HWND hwnd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINST hInstance, HINST hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInst = hInstance;

	char szClassName[] = "Hellp";

	WNDCLASS wcex;

	//wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"TextWindow";
	//wcex.hIconSm = NULL;

	RegisterClass(&wcex);

	HWND hWnd = CreateWindow(L"TextWindowO", L"AAA", WS_OVERLAPPEDWINDOW, 10, 10, 100, 100, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

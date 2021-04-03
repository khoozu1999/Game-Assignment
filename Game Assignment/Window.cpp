#include "Windows.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"

//Singleton
KZWindows* KZWindows::sInstance = NULL;

KZWindows* KZWindows::getInstance()
{
	if (KZWindows::sInstance == NULL)
	{
		sInstance = new KZWindows;
	}

	return sInstance;
}

void KZWindows::releaseInsrance()
{
	delete sInstance;
	sInstance = NULL;
}

bool isFullscreen = false;

KZWindows::KZWindows()
{
	this->g_hWnd = NULL;
	this->hInstance = GetModuleHandle(NULL);
	ZeroMemory(&wndClass, sizeof(wndClass));
	keyIn = 0;
	mouseX = 0;
	mouseY = 0;
	gameState = 1;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int keyIn;

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == 27)
		{
			PostQuitMessage(0);
		}

		KZWindows::getInstance()->keyIn = wParam;

		printf("wParam-%d\n", wParam);
		break;

	case WM_MOUSEMOVE:
		KZWindows::getInstance()->mouseX = LOWORD(lParam);
		KZWindows::getInstance()->mouseY = HIWORD(lParam);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



void KZWindows::createWindows()
{
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "Windows";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	//wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClass(&wndClass);

	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Windows", WS_OVERLAPPEDWINDOW, 0, 100, 1080, 720, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hWnd, 1);

	
}

void KZWindows::clearWindows()
{
	UnregisterClass(wndClass.lpszClassName, hInstance);
}

void KZWindows::fullscreen() {

	if (d3dPP.Windowed == true)
	{
		d3dPP.Windowed = false;
		d3dPP.BackBufferWidth = 1920;
		d3dPP.BackBufferHeight = 1080;
	}

	else if (d3dPP.Windowed == false)
	{
		d3dPP.Windowed = true;
		d3dPP.BackBufferWidth = 480;
		d3dPP.BackBufferHeight = 640;
	}

	HRESULT hr = d3dDevice->Reset(&d3dPP);
	if (FAILED(hr)) {
		PostQuitMessage(0);
	}
}

bool KZWindows::loop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) break;

		TranslateMessage(&msg);

		DispatchMessage(&msg);

		if (isFullscreen == true)
		{
			fullscreen();
			isFullscreen = false;
		}

	}

	stateChange();
	DirectInput::getInstance()->InputLoop();

	GameStateManager::getInstance()->update();

	Graphic::getInstance()->present();

	if (keyIn != 0)
	{
		keyIn = 0;
	}

	return msg.message != WM_QUIT;
}

void KZWindows::stateChange()
{
	if (keyIn >= 98 && keyIn <= 105)
	{
		GameStateManager::getInstance()->preState = GameStateManager::getInstance()->currentState;
		GameStateManager::getInstance()->currentState = keyIn - 98;
	}
}
#ifndef WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "resource.h"
#include <d3d9.h>

class KZWindows
{
private:
	static KZWindows* sInstance;
	KZWindows();

public:
	HWND g_hWnd;
	WNDCLASS wndClass;
	HINSTANCE hInstance;
	int keyIn, mouseX, mouseY;

	static KZWindows* getInstance();
	static void releaseInsrance();

	void createWindows();
	void clearWindows();
	bool loop();
	void stateChange();
	void fullscreen();
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9* d3dDevice;

	int gameState = 1;
};

#endif
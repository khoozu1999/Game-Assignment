#pragma once
#include <d3dx9.h>
#include "GameState.h"

#define GAMETITLE "Running Sim"

class MainMenu : public GameState {
public:
	MainMenu();
	~MainMenu();

	HRESULT hr[5];

	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();

	int function;
	float timer;
	bool isFunction;

	RECT GameTitleRect;
	RECT backgroundRect

		LPDIRECT3DTEXTURE9 buttonImage;
	LPDIRECT3DTEXTURE9 background;

	LPD3DXSPRITE titleSprite;
	LPD3DXFONT gameTitle;
};
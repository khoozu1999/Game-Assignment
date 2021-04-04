#pragma once
#include <d3dx9.h>
#include "GameState.h"



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

	int r,g ,b;
	float timer;
	

	RECT gameTitleRect;
	RECT backgroundRect;
	RECT rectFont;

	LPD3DXSPRITE titleSprite;
	LPD3DXFONT font;
	LPDIRECT3DTEXTURE9 buttonImage;
	LPDIRECT3DTEXTURE9 background;
	LPDIRECT3DTEXTURE9 gameTitle;

	
	
};
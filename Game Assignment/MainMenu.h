#pragma once
#include <d3dx9.h>
#include "GameState.h"


#define TITLE "RUNNING SIM"

class MainMenu : public GameState {
public:
	MainMenu();
	~MainMenu();
	
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	

	RECT gameTitleRect;
	RECT backgroundRect;
	RECT fontRect;

	
	LPD3DXFONT font;
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 buttonImage;
	LPDIRECT3DTEXTURE9 background;
	LPD3DXFONT gameTitle;
	

	
	
};
#pragma once
#include <d3dx9.h>
#include "GameState.h"
#include "Sound.h"


#define TITLE "RUNNING SIM"

class MainMenu : public GameState 
{
public:
	MainMenu();
	~MainMenu();
	
	Sound* sound;

	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	

	RECT gameTitleRect;
	RECT backgroundRect;
	RECT fontRect;
	RECT fontRect2;
	RECT fontRect3;
	RECT fontRect4;
	

	
	LPD3DXFONT font;
	LPD3DXFONT font2;
	LPD3DXFONT font3;
	LPD3DXFONT font4;


	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 buttonImage;
	LPDIRECT3DTEXTURE9 background;
	LPD3DXFONT gameTitle;
	

	void restart(){}
	
};
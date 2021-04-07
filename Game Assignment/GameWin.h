
#pragma once
#include <d3dx9.h>
#include "GameState.h"

class GameWin : public GameState
{
public:
	static GameWin* sInstance;
	GameWin();
	~GameWin();

	HRESULT hr;
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 bgTexture1;
	LPD3DXFONT font;
	LPD3DXFONT font2;
	LPD3DXFONT gameWin;
	LPDIRECT3DTEXTURE9 background;


	RECT gameTitleRect;
	RECT backgroundRect;
	RECT fontRect;
	RECT gameWinRect;
	RECT fontRect2;

	void init();
	void fixedUpdate();
	void draw();
	void update();
	void release();
	void restart();

};



#pragma once

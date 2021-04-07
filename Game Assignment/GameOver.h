
#pragma once
#include <d3dx9.h>
#include "GameState.h"

class GameOver : public GameState
{
public:
	static GameOver* sInstance;
	GameOver();
	~GameOver();

	HRESULT hr;
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 bgTexture1;
	LPD3DXFONT font;
	LPD3DXFONT gameOver;
	LPDIRECT3DTEXTURE9 background;

	
	RECT gameTitleRect;
	RECT backgroundRect;
	RECT fontRect;
	RECT gameOverRect;

	void init();
	void fixedUpdate();
	void draw();
	void update();
	void release();


};




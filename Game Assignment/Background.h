#pragma once
#include <d3dx9.h>
#include "GameState.h"

class Background
{
private:
	static Background* sInstance;
	Background();
	~Background();

public:
	static Background* getInstance();
	static void releaseInstance();
	
	D3DXVECTOR3 drawPosition[2][4];
	
	HRESULT hr;
	LPD3DXSPRITE bgSprite;
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 bgTexture1;
	

	RECT spriteRect, backgroundRect;
	
	
	void init();
	void fixedUpdate();
	void draw();
	void update();
	void release();


};



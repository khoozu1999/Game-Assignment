#pragma once
#include <d3dx9.h>
#include "GameState.h"

class Character : public GameState
{
public:
	Character();
	~Character();

	HRESULT hr;

	LPD3DXSPRITE charSprite;
	D3DXVECTOR3 position, positionBG;
	RECT charRect[16];
	LPDIRECT3DTEXTURE9 charTexture;
	/*LPDIRECT3DTEXTURE9 bgTexture1;
	LPDIRECT3DTEXTURE9 bgTexture2;
	LPDIRECT3DTEXTURE9 bgTexture3;
	LPDIRECT3DTEXTURE9 bgTexture4;*/

	D3DXVECTOR2 charSize, charDirection, charPosition, charVelocity;
	D3DXMATRIX mat;
	int frameNum, charFrame, charState;
	float frameRate, frameTimer, animationSpeed, charSpeed;
	bool isMoving;

	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


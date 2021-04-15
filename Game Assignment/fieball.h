#pragma once
#include <d3dx9.h>
#include "GameState.h"
#include "Collider.h"


class fieball
{
public:
	fieball();
	~fieball();
	HRESULT hr;
	LPD3DXSPRITE sprite;
	RECT rect[16];
	LPDIRECT3DTEXTURE9 texture;

	D3DXVECTOR3 position, speed;

	D3DXVECTOR2 size, direction, velocity, positionf;
	D3DXMATRIX mat;
	int frameNum, Frame, State, jump_time, faceDirection, FireballDirect;
	float frameRate, frameTimer, animationSpeed, Speed;
	

	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


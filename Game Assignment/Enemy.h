#pragma once
#include <d3dx9.h>
#include "GameState.h"

class Enemy
{
private:
	static Enemy* sInstance;
	Enemy();
	~Enemy();
public:
	static Enemy* getInstance();
	static void releaseInstance();
	HRESULT hr;
	LPD3DXSPRITE charSprite;
	D3DXVECTOR3 position;
	RECT charRect[16];
	LPDIRECT3DTEXTURE9 charTexture;

	D3DXVECTOR2 charSize, charDirection, charPosition, charVelocity;
	D3DXMATRIX mat;
	int frameNum, charFrame, charState, spawnRate;
	float frameRate, frameTimer, animationSpeed, charSpeed, spawnTime;
	bool isMoving;

	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


#pragma once
#include <d3dx9.h>
#include "GameState.h"

class Character
{
private:
	static Character* sInstance;
	Character();
	~Character();
public:
	static Character* getInstance();
	static void releaseInstance();
	HRESULT hr;

	LPD3DXSPRITE charSprite;
	D3DXVECTOR3 position, positionBG;
	RECT charRect[16];
	LPDIRECT3DTEXTURE9 charTexture;

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


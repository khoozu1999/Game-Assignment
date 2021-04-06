#pragma once
#include <d3dx9.h>
#include "GameState.h"

class Character
{
private:
	static Character* sInstance;
	int boundary;
	float force;
	Character();
	~Character();
public:
	static Character* getInstance();
	static void releaseInstance();
	HRESULT hr;
	LPD3DXSPRITE charSprite;
	RECT charRect[16];
	LPDIRECT3DTEXTURE9 charTexture;

	D3DXVECTOR3 position, speed;

	D3DXVECTOR2 charSize, charDirection, charPosition, charVelocity;
	D3DXMATRIX mat;
	int frameNum, charFrame, charState, jump_time, char_faceDirection, hp,score,scoretext;
	float frameRate, frameTimer, animationSpeed, charSpeed;
	bool isMoving;
	


	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


#pragma once
#include <d3dx9.h>
#include "GameState.h"
class Character;

class Enemy
{
private:
	static Enemy* sInstance;
	double min, max;
	int enemyType;
	bool forward;
public:
	static Enemy* getInstance();
	static void releaseInstance();
	Enemy();
	~Enemy();

	HRESULT hr;
	LPD3DXSPRITE enemySprite;
	D3DXVECTOR3 position;
	RECT enemyRect[16];
	LPDIRECT3DTEXTURE9 enemy1;
	D3DXVECTOR2 enemySize, enemyDirection, enemyPosition, enemyVelocity, location, targetPosition[3];
	D3DXMATRIX mat;

	int frameNum, enemyFrame, enemyState, spawnRate, char_faceDirection, enemyHP, currentTargetIndex, targetIndexDirection;
	float frameRate, frameTimer, animationSpeed, charSpeed, spawnTime, x, y;
	bool isMoving;
	bool enemydie;

	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


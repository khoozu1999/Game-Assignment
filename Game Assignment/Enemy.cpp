#include "Enemy.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "DirectInput.h"

Enemy* Enemy::sInstance = NULL;

Enemy* Enemy::getInstance()
{
	if (Enemy::sInstance == NULL)
	{
		sInstance = new Enemy;
	}

	return sInstance;
}

void Enemy::releaseInstance()
{
	delete sInstance;
	sInstance = NULL;
}

Enemy::Enemy()
{
	
	enemySprite = NULL;
	enemy1 = NULL;

	position = { 0, 0, 0 };
	enemyFrame = 0;
	frameNum = 0;
	enemyState = 0;
	frameRate = 1.0f / frameNum;
	frameTimer = 0;
	animationSpeed = 0;
	charSpeed = 0;
	enemyHP = 10;
}

Enemy::~Enemy()
{

}


void Enemy::init()
{
	hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &enemySprite);
	hr = D3DXCreateTextureFromFileEx(Graphic::getInstance()->d3dDevice, "resource/enemy1.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), //change the XRGB to ignore the color
		NULL, NULL, &enemy1);

	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	enemySize.x = 64;
	enemySize.y = 64;

	enemyFrame = 0;
	frameNum = 4;
	animationSpeed = 5;
	frameRate = 1.0f / animationSpeed;
	frameTimer = 0;

	charSpeed = 0;
	enemyDirection.y = 1;

	enemyRect->top = 0;
	enemyRect->bottom = enemyRect->top + enemySize.y;
	enemyRect->left = enemySize.x * enemyFrame;
	enemyRect->right = enemyRect->left + enemySize.x;

	enemyPosition.x = 400;
	enemyPosition.y = 350;

	enemyVelocity.x = 0;
	enemyVelocity.y = 0;

	enemydie = false;

	targetPosition[0].x = 50;
	targetPosition[0].y = 350;

	targetPosition[1].x = 500;
	targetPosition[1].y = 350;

	targetPosition[2].x = 200;
	targetPosition[2].y = 350;

	currentTargetIndex = 0;
	targetIndexDirection = 1;
}

void Enemy::fixedUpdate()
{
	
	animationSpeed = 5;
	frameRate = 1.0f / animationSpeed;
	frameTimer += 1.0f / 60;
	if (frameTimer >= frameRate)
	{
		frameTimer -= frameRate;
		enemyFrame++;
		enemyFrame %= frameNum;
	}

	enemyRect->top = enemySize.y * enemyState;
	enemyRect->bottom = enemyRect->top + enemySize.y;
	enemyRect->left = enemySize.x * enemyFrame;
	enemyRect->right = enemyRect->left + enemySize.x;

	D3DXVECTOR2 offset = targetPosition[currentTargetIndex] - enemyPosition;
	D3DXVECTOR2 direction;
	D3DXVec2Normalize(&direction, &offset);
	float lenght = D3DXVec2Length(&offset);
	if (lenght < 5) { //Once reah posision
		//change target index
		currentTargetIndex += targetIndexDirection;

		if (currentTargetIndex == 2) {
			targetIndexDirection = -1;
		}
		else if (currentTargetIndex == 0) {
			targetIndexDirection = 1;
		}
	}
	enemyPosition += ((direction * 80) / 60.0);
	// enemy animation
	if (currentTargetIndex == 0 || currentTargetIndex == 2) {
		enemyState = 1;
	}

	if (currentTargetIndex == 1 || currentTargetIndex == 3) {
		enemyState = 2;
	}
}

void Enemy::update()
{
	/*enemyPosition.x++;
	if (enemyPosition.x > 150) {
		enemyPosition.x--;
	}*/
	
	//D3DXVECTOR2 scaling(1.5f, 1.5f);
	enemySprite->SetTransform(&mat);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, 0, &enemyPosition);
}

void Enemy::draw()
{
	enemySprite->Begin(D3DXSPRITE_ALPHABLEND);
	enemySprite->SetTransform(&mat);
	if (enemydie == false) {
		enemySprite->Draw(enemy1, enemyRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
		
	}
	enemySprite->End();
}

void Enemy::release()
{
	enemySprite->Release();
	enemySprite = NULL;

	/*enemySprite->Release();
	enemy1 = NULL;*/
}



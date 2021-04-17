#include "character.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "DirectInput.h"
#include "Collider.h"
#include "Enemy.h"
#include "Sound.h"


Character* Character::sInstance = NULL;

Collider* collider = new Collider;

Character* Character::getInstance()
{
	if (Character::sInstance == NULL)
	{
		sInstance = new Character;
	}

	return sInstance;
}

void Character::releaseInstance()
{
	delete sInstance;
	sInstance = NULL;
}

Character::Character()
{
	charSprite = NULL;
	charTexture = NULL;


	position = { 100, -220, 0 };
	charFrame = 0;
	frameNum = 0;
	charState = 0;
	frameRate = 1.0f / frameNum;
	frameTimer = 0;
	animationSpeed = 0;
	charSpeed = 0;
	charHP = 3;

	isMoving = false;
}

Character::~Character()
{
	
}

void Character::init()
{
	hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &charSprite);
	hr = D3DXCreateTextureFromFileEx(Graphic::getInstance()->d3dDevice, "resource/char.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), //change the XRGB to ignore the color
		NULL, NULL, &charTexture);

	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	charSize.x = 64;
	charSize.y = 64;

	charFrame = 0;
	frameNum = 4;
	animationSpeed = 12;
	frameRate = 1.0f / animationSpeed;
	frameTimer = 0;

	charSpeed = 0;
	charDirection.y = 1;

	charRect->top = 0;
	charRect->bottom = charRect->top + charSize.y;
	charRect->left = charSize.x * charFrame;
	charRect->right = charRect->left + charSize.x;

	charPosition.x = 100;
	charPosition.y = 350;

	charVelocity.x = 0;
	charVelocity.y = 0;
	char_faceDirection = 1;
	ishurt = true;
	isAttack = true;

}

void Character::update()
{
	printf("char: %d enemy: %d\n", charHP, Enemy::getInstance()->enemyHP);
	//printf("Character : %lf - %lf\n", charPosition.x, charPosition.y);
	
	if (DirectInput::getInstance()->diKeys[DIK_DOWN]) {
		charVelocity.y++;
		isMoving = true;
	}
	if (DirectInput::getInstance()->diKeys[DIK_LEFT]) {
		charVelocity.x--;
		char_faceDirection = -1;
		charState = 1;
		isMoving = true;
	}
	else if (DirectInput::getInstance()->diKeys[DIK_RIGHT]) {
		charVelocity.x++;
		char_faceDirection = 1;
		charState = 2;
		isMoving = true;
	}
	else {
		charVelocity.x = 0;
		isMoving = false;
		isAttack = false;
	}
	if (DirectInput::getInstance()->diKeys[DIK_UP] && charPosition.y == 350){
		isMoving = true;
		D3DXVECTOR2 jumpDirection = D3DXVECTOR2(sin(0 / 180 * 3.142), -cos(0 / 180 * 3.142));
		jumpDirection.x *= char_faceDirection;
		charVelocity = (jumpDirection * 250);
	}

}

void Character::fixedUpdate()
{

	

	if (isMoving)
	{
		charSpeed++;
	}

	if (charSpeed > 0)
	{
		animationSpeed = charSpeed / 2;
		animationSpeed = max(animationSpeed, 5);
		animationSpeed = min(animationSpeed, 5);
		frameRate = 1.0f / animationSpeed;
		frameTimer += 1.0f / 60;

		if (!isMoving)
		{
			animationSpeed--;
			//charSpeed--;
			charSpeed = 0;
			charSpeed = max(charSpeed, 0);
			animationSpeed = min(charSpeed, 40);
		}
	}
	if (charSpeed == 0) {
		charState = 0;
	}

	if (frameTimer >= frameRate)
	{
		frameTimer -= frameRate;
		charFrame++;
		charFrame %= frameNum;
	}

	bool isCollEnemy = false;

	if (Enemy::getInstance()->enemydie == false) {

		if (collider->isCollide(charPosition, charSize * 0.5, Enemy::getInstance()->enemyPosition, Enemy::getInstance()->enemySize * 0.5)) {
			isCollEnemy = true;
		}
	}
	

	if (isCollEnemy == true)
	{
		if (ishurt == true) {
			Sound::getInstance()->playHitSound();
			charHP -= 1;
			ishurt = false;
		}
	}
	else {
		ishurt = true;
	}

	if (charHP <= 0) {
		GameStateManager::getInstance()->currentState = 2;
		charPosition.x = 100;
		charPosition.y = 350;
		charHP += 3;
		Enemy::getInstance()->enemyHP = 10;
	}

	if (Enemy::getInstance()->enemyHP <= 0) {
		GameStateManager::getInstance()->currentState = 3;
		Enemy::getInstance()->enemydie = true;
		
	}

	charRect->top = charSize.y * charState;
	charRect->bottom = charRect->top + charSize.y;
	charRect->left = charSize.x * charFrame;
	charRect->right = charRect->left + charSize.x;

	if (charPosition.y <= 350) {
		charVelocity.y += (350 / 60.0);
		charPosition += (charVelocity / 60.0);
	}
	else {
		charVelocity.y = 0;
		charPosition.y = 350;
	}

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, 0, &charPosition);
}

void Character::draw()
{
	charSprite->Begin(D3DXSPRITE_ALPHABLEND);
	charSprite->SetTransform(&mat);
	charSprite->Draw(charTexture, charRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	charSprite->End();
}

void Character::release()
{
	charSprite->Release();
	charSprite = NULL;

	charTexture->Release();
	charTexture = NULL;
}


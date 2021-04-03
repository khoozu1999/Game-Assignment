#include "Character.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "DirectInput.h"

Character* Character::sInstance = NULL;

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
	ZeroMemory(&mat, sizeof(mat));
	ZeroMemory(&charSize, sizeof(charSize));
	ZeroMemory(&charSize, sizeof(charDirection));
	ZeroMemory(&charSize, sizeof(charPosition));
	ZeroMemory(&charSize, sizeof(charVelocity));
	ZeroMemory(&charRect, sizeof(charRect));

	position = { 0,-280,0 };
	charFrame = 0;
	frameNum = 0;
	charState = 0;
	frameRate = 1.0f / frameNum;
	frameTimer = 0;
	animationSpeed = 0;
	charSpeed = 0;

	isMoving = false;
}

Character::~Character()
{

}

void Character::init()
{
	hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &charSprite);
	hr = D3DXCreateTextureFromFileEx(Graphic::getInstance()->d3dDevice, "resource/pink1.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), //change the XRGB to ignore the color
		NULL, NULL, &charTexture);

	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	charSize.x = 64;
	//charSize.y = 42.666;
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
		animationSpeed = max(animationSpeed, 4);
		animationSpeed = min(animationSpeed, 20);
		frameRate = 1.0f / animationSpeed;
		frameTimer += 1.0f / 60;

		if (!isMoving)
		{
			charSpeed--;
			charSpeed = max(charSpeed, 0);
			animationSpeed = min(charSpeed, 40);
		}
	}

	charVelocity = charDirection * (charSpeed / 60.0f);
	charPosition += charVelocity;

	if (frameTimer >= frameRate)
	{
		frameTimer -= frameRate;
		charFrame++;
		charFrame %= frameNum;
	}

	charRect->top = charSize.y * charState;
	charRect->bottom = charRect->top + charSize.y;
	charRect->left = charSize.x * charFrame;
	charRect->right = charRect->left + charSize.x;

	D3DXVECTOR2 scaling(0.6f, 0.6f);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, 0, &charPosition);
}

void Character::update()
{
	printf("Character : %lf - %lf\n", charPosition.x, charPosition.y);
	if (DirectInput::getInstance()->diKeys[DIK_UP] && DirectInput::getInstance()->diKeys[DIK_LEFT])
	{
		//charState = 1;
		charDirection.x = -1;
		charDirection.y = -1;
		isMoving = true;
	}

	else if (DirectInput::getInstance()->diKeys[DIK_DOWN] && DirectInput::getInstance()->diKeys[DIK_RIGHT])
	{
		//charState = 2;
		charDirection.x = 1;
		charDirection.y = 1;
		isMoving = true;
	}

	//else if (DirectInput::getInstance()->diKeys[DIK_UP])
	//{
	//	//charState = 3;
	//	charDirection.x = 0;
	//	charDirection.y = -1;
	//	isMoving = true;
	//}

	else if (DirectInput::getInstance()->diKeys[DIK_UP])
	{
		if (charVelocity.y == 0)
		{
			isJump = true;
		}

	}

	else if (DirectInput::getInstance()->diKeys[DIK_DOWN])
	{
		//charState = 0;
		charDirection.x = 0;
		charDirection.y = 1;
		isMoving = true;
		isJump = false;
	}

	else if (DirectInput::getInstance()->diKeys[DIK_LEFT])
	{
		charState = 1;
		charDirection.x = -1;
		charDirection.y = 0;
		isMoving = true;
		isJump = false;
	}

	else if (DirectInput::getInstance()->diKeys[DIK_RIGHT])
	{
		charState = 2;
		charDirection.x = 1;
		charDirection.y = 0;
		isMoving = true;
		isJump = false;
	}

	else
	{
		isMoving = false;
		isJump = false;
		if (charSpeed == 0) {
			charState = 0;
		}
	}

	if (charSpeed > 50) //speed limit
	{
		charSpeed = 50.0;

	}

	if (charPosition.y > 0) //speed limit
	{
		charPosition.y = 0.0;

	}

	if (isJump) {
		isJumpp = true;
		jump_time = 0;
	}
	else {
		if (isJumpp) {
			//
			D3DXVECTOR2 cursorPosition;
			cursorPosition.x = charPosition.x;
			cursorPosition.y = charPosition.y - 128;
			D3DXVECTOR2 offset = cursorPosition - charPosition;
			D3DXVec2Normalize(&offset, &offset);
			charVelocity = offset * 20;
			//
			charVelocity.y -= (200 / 6.0);
			charPosition += (charVelocity / 60.0);
			if (jump_time >= 5)
			{
				isJumpp = false;
			}
			jump_time++;
		}
		else {
			isJumpp = false;
		}
	}
}

void Character::draw()
{
	if (GameStateManager::getInstance()->preState == 1)
	{
		D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &charSprite);
		GameStateManager::getInstance()->preState = 5;
	}

	Graphic::getInstance()->red = 0;
	Graphic::getInstance()->green = 0;
	Graphic::getInstance()->blue = 0;

	charSprite->Begin(D3DXSPRITE_ALPHABLEND);
	charSprite->SetTransform(&mat);
	charSprite->Draw(charTexture, charRect, &position, NULL, D3DCOLOR_XRGB(255, 255, 255));
	charSprite->End();
}

void Character::release()
{
	charSprite->Release();
	charSprite = NULL;

	charTexture->Release();
	charTexture = NULL;
}


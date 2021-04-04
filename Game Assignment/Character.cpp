#include "character.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "DirectInput.h"
#include "Collider.h"

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


	position = { 100, -220, 0 };
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
	charPosition.y = 150;

	charVelocity.x = 0;
	charVelocity.y = 0;
	char_faceDirection = 1;
	hp = 1;

}

void Character::update()
{
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
	}
	if (DirectInput::getInstance()->diKeys[DIK_SPACE] && charPosition.y == 150){
		isMoving = true;
		D3DXVECTOR2 jumpDirection = D3DXVECTOR2(sin(0 / 180 * 3.142), -cos(0 / 180 * 3.142));
		jumpDirection.x *= char_faceDirection;
		charVelocity = (jumpDirection * 250);
	}

}

void Character::fixedUpdate()
{

	if (charPosition.y <= 150) {
		charVelocity.y += (350 / 60.0);
		charPosition += (charVelocity / 60.0);
	}
	else {
		charVelocity.y = 0;
		charPosition.y = 150;
	}

	if (isMoving)
	{
		charSpeed++;
	}

	if (charSpeed > 0)
	{
		animationSpeed = charSpeed / 2;
		animationSpeed = max(animationSpeed, 4);
		animationSpeed = min(animationSpeed, 10);
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

	/*charVelocity = charDirection * (charSpeed / 60.0f);
	charPosition += charVelocity;*/

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

	//D3DXVECTOR2 scaling(0.6f, 0.6f);
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, 0, &charPosition);
}

void Character::draw()
{
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


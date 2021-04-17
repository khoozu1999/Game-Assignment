#include "fieball.h"
#include"Graphic.h"
#include"DirectInput.h"
#include"Character.h"
#include"Collider.h"
#include"Enemy.h"
#include"Sound.h"

Collider* collider1 = new Collider;

fieball::fieball()
{
	sprite = NULL;
	texture = NULL;

	position = { 100, -220, 0 };
	Frame = 0;
	frameNum = 0;
	State = 0;
	frameRate = 1.0f / frameNum;
	frameTimer = 0;
	animationSpeed = 0;
	Speed = 0;
}
fieball::~fieball()
{
	

	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}
void fieball::init()
{
	hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &sprite);
	hr = D3DXCreateTextureFromFileEx(Graphic::getInstance()->d3dDevice, "resource/fireball1.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), //change the XRGB to ignore the color
		NULL, NULL, &texture);

	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	size.x = 42.667;
	size.y = 64;

	Frame = 0;
	frameNum = 6;
	animationSpeed = 12;
	frameRate = 1.0f / animationSpeed;
	frameTimer = 0;

	Speed = 0;

	rect->top = 0;
	rect->bottom = rect->top + size.y;
	rect->left = size.x * Frame;
	rect->right = rect->left + size.x;

	//position.x = 100;
	//position.y = 350;

	velocity.x = 0;
	velocity.y = 0;
	FireballDirect = 1;
}
void fieball::fixedUpdate()
{
	animationSpeed = 5;
	frameRate = 1.0f / animationSpeed;
	frameTimer += 1.0f / 60;
	if (frameTimer >= frameRate)
	{
		frameTimer -= frameRate;
		Frame++;
		Frame %= frameNum;
	}

	rect->top = size.y * State;
	rect->bottom = rect->top + size.y;
	rect->left = size.x * Frame;
	rect->right = rect->left + size.x;

	position.x += FireballDirect;


}
void fieball::update()
{
	if (DirectInput::getInstance()->diKeys[DIK_A]) {
		
		if (Character::getInstance()->char_faceDirection == 1) {
			Sound::getInstance()->playAttackSound();
			position.x = Character::getInstance()->charPosition.x + 50;
			position.y = Character::getInstance()->charPosition.y;
			FireballDirect = 1;
		}
		if (Character::getInstance()->char_faceDirection == -1) {
			Sound::getInstance()->playAttackSound();
			position.x = Character::getInstance()->charPosition.x + -50;
			position.y = Character::getInstance()->charPosition.y;
			FireballDirect = -1;
		}
	}

	positionf.x = position.x;
	positionf.y = position.y;

	if (collider1->isCollide(positionf, size, Enemy::getInstance()->enemyPosition, Enemy::getInstance()->enemySize))
	{
		position.y = -500;
		
		if (Character::getInstance()->isAttack == true) {
			Enemy::getInstance()->enemyHP -= 1;
			Character::getInstance()->isAttack = false;
		}
	}
	else {
		Character::getInstance()->isAttack = true;
	}
}
void fieball::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(texture, rect, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));
	sprite->End();
}
void fieball::release()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}
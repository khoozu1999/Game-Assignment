#include "PlayerController.h"

PlayerController::PlayerController(int hp, int x, int y, int speed, int height)
{
	this->hp = hp;

	this->speed = speed;
	this->jumpHeight = height;
	this->jump = false;
	this->jumpCurrent = 0;
	this->gravity = 20;

	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;

	this->boundary = 350;
}


void PlayerController::setGravity(int num)
{
	gravity = num;
}


int PlayerController::getGravity()
{
	return gravity;
}

D3DXVECTOR3 PlayerController::getPosition()
{
	return position;
}

int PlayerController::getJumpHeight()
{
	return jumpHeight;
}

void PlayerController::setJumpCurrent(int num)
{
	jumpCurrent = num;
}
int PlayerController::getJumpCurrent()
{
	return jumpCurrent;
}

void PlayerController::gravityPull()
{
	position.y += (gravity / 60.0);
}

bool PlayerController::onFloor()
{
	if (position.y < boundary)
		return false;

	return true;
}


void PlayerController::moveleft()
{
	position.x += speed;
}
void PlayerController::moveright()
{
	position.x -= speed;
}
void PlayerController::jumpUp()
{
	position.y -= (10);
	jumpCurrent -= 1;

}
void PlayerController::setJump(bool current)
{
	jump = current;
}
bool PlayerController::getJump()
{
	return jump;
}


void PlayerController::animation()
{

}
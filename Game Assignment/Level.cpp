#include "Level.h"
#include "Character.h"
#include "Background.h"
#include "Enemy.h"
#include "DirectInput.h"
#include"GameStateManager.h"

Level::Level() 
{
}

Level::~Level()
{
}

void Level::init() {
	//sprite = NULL;
	Background::getInstance()->init();
	Enemy::getInstance()->init();
	Character::getInstance()->init();

}
void Level::fixedUpdate() {
	Background::getInstance()->fixedUpdate();
	Enemy::getInstance()->fixedUpdate();
	Character::getInstance()->fixedUpdate();
}
void Level::update() {
	Background::getInstance()->update();
	Enemy::getInstance()->update();
	Character::getInstance()->update();

	if (DirectInput::getInstance()->diKeys[DIK_P])
	{
		release();
		GameStateManager::getInstance()->currentState = 0;
		init();
	}
	if (DirectInput::getInstance()->diKeys[DIK_R])
	{
		release();
		GameStateManager::getInstance()->currentState = 1;
		init();
	}

	


	
}
void Level::draw() {
	Background::getInstance()->draw();
	Enemy::getInstance()->draw();
	Character::getInstance()->draw();
	/*for (int i = 0; i < EnemyList.size(); i++)
	{
		EnemyList[i]->draw(Asteroid_texture, sprite);
	}*/
}

void Level::release() {

	Background::getInstance()->release();
	Background::getInstance()->releaseInstance();

	Enemy::getInstance()->release();
	Enemy::getInstance()->releaseInstance();

	Character::getInstance()->release();
	Character::getInstance()->releaseInstance();
}




void Level::restart() {

}
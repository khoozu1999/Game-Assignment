#include "Level.h"
#include "Character.h"
#include "Background.h"
#include "Enemy.h"
#include "DirectInput.h"
#include"GameStateManager.h"
#include "Sound.h"
#include "fieball.h"

Level::Level() 
{

}

Level::~Level()
{
}

void Level::init() {
	Background::getInstance()->init();
	Enemy::getInstance()->init();
	Character::getInstance()->init();
	fieball::getInstance()->init();
	particle.init();
}
void Level::fixedUpdate() {
	Background::getInstance()->fixedUpdate();
	Enemy::getInstance()->fixedUpdate();
	Character::getInstance()->fixedUpdate();
	fieball::getInstance()->fixedUpdate();
	if (i < 60)
		i++;
	particle.fixedUpdate();

	
}
void Level::update() {
	Background::getInstance()->update();
	Enemy::getInstance()->update();
	Character::getInstance()->update();
	fieball::getInstance()->update();

	i = particle.update(i);

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
	fieball::getInstance()->draw();
	if (i < 60) {
		particle.draw();
	}
	
}

void Level::release() {

	Background::getInstance()->release();
	Background::getInstance()->releaseInstance();
	

	Enemy::getInstance()->release();
	Enemy::getInstance()->releaseInstance();
	

	Character::getInstance()->release();
	Character::getInstance()->releaseInstance();

	fieball::getInstance()->release();
	fieball::getInstance()->releaseInstance();
}




void Level::restart() {

}
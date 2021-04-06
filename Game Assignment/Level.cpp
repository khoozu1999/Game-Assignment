#include "Level.h"
#include "Character.h"
#include "Background.h"
#include "Enemy.h"

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
}
void Level::draw() {
	Background::getInstance()->draw();
	Enemy::getInstance()->draw();
	Character::getInstance()->draw();
}

void Level::release() {

	Background::getInstance()->release();
	Background::getInstance()->releaseInstance();

	Enemy::getInstance()->release();
	Enemy::getInstance()->releaseInstance();

	Character::getInstance()->release();
	Character::getInstance()->releaseInstance();
}
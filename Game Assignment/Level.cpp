#include "Level.h"
#include "Character.h"
#include "Background.h"

Level::Level() 
{
}

Level::~Level()
{
}

void Level::init() {
	Character::getInstance()->init();
	Background::getInstance()->init();
}
void Level::fixedUpdate() {
	Character::getInstance()->fixedUpdate();
	Background::getInstance()->fixedUpdate();
}
void Level::update() {
	Character::getInstance()->update();
	Background::getInstance()->update();
}
void Level::draw() {
	
	Background::getInstance()->draw();
	Character::getInstance()->draw();
}
void Level::release() {
	Character::getInstance()->release();
	Character::getInstance()->releaseInstance();

	Background::getInstance()->release();
	Background::getInstance()->releaseInstance();
}
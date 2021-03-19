#include "GameStateManager.h"
#include "Level1.h"
#include "Character.h"


//singleton
GameStateManager* GameStateManager::sInstance = NULL;

GameStateManager* GameStateManager::getInstance()
{
	if (GameStateManager::sInstance == NULL)
	{
		sInstance = new GameStateManager;
	}

	return sInstance;
}

void GameStateManager::releaseInsrance()
{
	delete sInstance;
	sInstance = NULL;
}

GameStateManager::GameStateManager()
{
	currentState = 0;
	framesToUpdate = 0;
	preState = 0;

	/*Level1* level1 = new Level1();
	level1->init();
	stateList.push_back(level1);*/

	Character* character = new Character();
	character->init();
	stateList.push_back(character);

	gTime = new GTime();
	gTime->init(60);
}

GameStateManager::~GameStateManager()
{
	for (int i = 0; i < stateList.size(); i++)
	{
		stateList[i]->release();
		delete stateList[i];
		stateList[i] = NULL;
	}

	delete gTime;
}

void GameStateManager::update()
{
	stateList[currentState]->update();

	framesToUpdate = gTime->framesToUpdate();

	for (int i = 0; i < framesToUpdate; i++)
	{
		stateList[currentState]->fixedUpdate();
	}

}

void GameStateManager::draw()
{
	stateList[currentState]->draw();
}
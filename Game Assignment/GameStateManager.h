#ifndef GAMESTATEMANAGER
#include <stdio.h>
#include <vector>
#include "GameState.h"
#include "GTime.h"

class GameStateManager
{
private:
	static GameStateManager* sInstance;
	GameStateManager();
	~GameStateManager();

public:
	enum State
	{
		MAIN_MENU,
		LEVEL,
		LOSE_MENU

	};
	static GameStateManager* getInstance();
	static void releaseInsrance();

	int currentState, preState, framesToUpdate;
	std::vector<GameState*> stateList;
	
		
	
	GTime* gTime;

	void update();
	void draw();

};

#endif // !GAMESTATEMANAGER




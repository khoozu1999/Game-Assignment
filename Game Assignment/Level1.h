#pragma once
#include "GameState.h"
class Level1 : public GameState
{
public:
	Level1();
	~Level1();


	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


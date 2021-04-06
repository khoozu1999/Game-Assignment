#pragma once
#include "GameState.h"
class Level : public GameState
{
public:
	Level();
	~Level();


	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


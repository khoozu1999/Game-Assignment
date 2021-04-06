#pragma once
#include "GameState.h"
#include<vector>
#include <string>

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


	void restart();
	//std::string score;
	//LPD3DXSPRITE sprite;
	//LPD3DXFONT fscore;
	//RECT rectUI;

	//void SpawnEnemy();
};


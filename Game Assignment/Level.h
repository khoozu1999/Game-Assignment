#pragma once
#include "GameState.h"
#include<vector>
#include <string>

class Level : public GameState
{
public:
	Level();
	~Level();

	int Timer;
	//std::vector<Enemy*>EnemyList;
	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
	//std::string score;
	//LPD3DXSPRITE sprite;
	//LPD3DXFONT fscore;
	//RECT rectUI;

	//void SpawnEnemy();
};


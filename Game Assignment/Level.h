#pragma once
#include "GameState.h"
#include<vector>
#include <string>
#include"fieball.h"

class Level : public GameState
{
public:
	Level();
	~Level();

	fieball fieball;

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


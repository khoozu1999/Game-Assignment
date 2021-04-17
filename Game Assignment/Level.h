#pragma once
#include "GameState.h"
#include<vector>
#include <string>
#include "Particle.h"

class Level : public GameState
{
public:
	Level();
	~Level();
	int i;
	//fieball fieball;
	Particle particle;
	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();


	void restart();
};


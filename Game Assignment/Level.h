#pragma once
#include "GameState.h"
#include<vector>
#include <string>
#include"fieball.h"
#include "Particle.h"

class Level : public GameState
{
public:
	Level();
	~Level();

	fieball fieball;
	Particle particle;
	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();


	void restart();
};


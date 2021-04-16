#pragma once
#include <d3dx9.h>

class Particle
{
public:
	Particle();
	~Particle();
	HRESULT hr;
	LPD3DXSPRITE sprite;
	RECT rect[16];
	LPDIRECT3DTEXTURE9 texture;

	D3DXVECTOR3 position, speed;

	D3DXVECTOR2 pposition[1000];
	D3DXVECTOR2 pvelocity[1000];
	D3DXMATRIX mat;
	int particle_index;
	float frameRate, frameTimer, animationSpeed, Speed;


	void init();
	void fixedUpdate();
	void update();
	void draw();
	void release();
};


#pragma once
#include <d3dx9.h>

class Coin {
public:

	Coin();
	~Coin();

	D3DXVECTOR3 position;
	float left, top;

	void physics();
	void animations();
   
};

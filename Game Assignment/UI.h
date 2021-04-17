#pragma once
#include <d3dx9.h>

class UI {
public:


	UI();
	~UI();
	RECT hpRect;
	D3DXVECTOR3 hpPosition1;
	D3DXVECTOR3 hpPosition2;
	D3DXVECTOR3 hpPosition3;

   void draw();

};

#ifndef COLLIDER
#define COLLIDER
#include "Character.h"
#include <stdio.h>

class Collider
{
public:
	Collider();

	bool isCollide(D3DXVECTOR2 positionA, D3DXVECTOR2 sizeA, D3DXVECTOR2 positionB, D3DXVECTOR2 sizeB);
};
#endif // !PHYSIC

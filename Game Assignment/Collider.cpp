#include "Collider.h"

Collider::Collider()
{
	
}

bool Collider::isCollide(D3DXVECTOR2 positionA, D3DXVECTOR2 sizeA, D3DXVECTOR2 positionB, D3DXVECTOR2 sizeB) {

	RECT rectA;
	rectA.left = positionA.x;
	rectA.right = positionA.x + sizeA.x;
	rectA.top = positionA.y;
	rectA.bottom = positionA.y + sizeA.y;

	RECT rectB;
	rectB.left = positionB.x;
	rectB.right = positionB.x + sizeB.x;
	rectB.top = positionB.y;
	rectB.bottom = positionB.y + sizeB.y;

	if (rectA.bottom < rectB.top) return false;
	if (rectA.top > rectB.bottom) return false;
	if (rectA.right < rectB.left) return false;
	if (rectA.left > rectB.right) return false;

	return true;
}

bool Collider::attack(D3DXVECTOR2 positionA, D3DXVECTOR2 sizeA, D3DXVECTOR2 positionB, D3DXVECTOR2 sizeB) {

	RECT rectA;
	rectA.left = positionA.x;
	rectA.right = positionA.x + sizeA.x;
	rectA.top = positionA.y;
	rectA.bottom = positionA.y + sizeA.y;

	RECT rectB;
	rectB.left = positionB.x;
	rectB.right = positionB.x + sizeB.x;
	rectB.top = positionB.y;
	rectB.bottom = positionB.y + sizeB.y;

	if (rectA.bottom < rectB.top) return false;
	if (rectA.top > rectB.bottom) return false;
	if (rectA.right < rectB.left) return false;
	if (rectA.left > rectB.right) return false;

	return true;
}

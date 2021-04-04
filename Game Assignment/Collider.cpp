//#include "Collider.h"
//
//Collider::Collider()
//{
//	velocity = 0;
//	gravity = 3;
//}
//
//bool Collider::isCollider(D3DXVECTOR2 posCharacter, D3DXVECTOR2 sizeCharacter)
//	RECT character;
//
//	character.left = posCharacter.x + 20;
//	character.right = posCharacter.x + sizeCharacter.x - 20;
//	character.top = posCharacter.y;
//	character.bottom = posCharacter.y + sizeCharacter.y + 8;
//
//	platform.left = posPlatform.x;
//	platform.right = posPlatform.x + sizePlatform.x;
//	platform.top = posPlatform.y;
//	platform.bottom = posPlatform.y + sizePlatform.y;
//
//
//	if (character.bottom < platform.top) return false;
//	if (character.right < platform.left) return false;
//	if (character.left > platform.right) return false;
//	if (character.top > platform.bottom) return false;
//	return true;
//}
//
//bool Collider::isEnemyCollider(D3DXVECTOR2 posCharacter, D3DXVECTOR2 sizeCharacter, D3DXVECTOR2 posEnemy, D3DXVECTOR2 sizeEnemy)
//{
//	RECT character1;
//	RECT enemy1;
//
//	character1.left = posCharacter.x + 20;
//	character1.right = posCharacter.x + sizeCharacter.x - 20;
//	character1.top = posCharacter.y;
//	character1.bottom = posCharacter.y + sizeCharacter.y + 8;
//
//	enemy1.left = posEnemy.x + 8;
//	enemy1.right = posEnemy.x + sizeEnemy.x - 8;
//	enemy1.top = posEnemy.y + 8;
//	enemy1.bottom = posEnemy.y + sizeEnemy.y + 8;
//
//
//	if (character1.bottom < enemy1.top) return false;
//	if (character1.right < enemy1.left) return false;
//	if (character1.left > enemy1.right) return false;
//	if (character1.top > enemy1.bottom) return false;
//	return true;
//}
//
//bool Collider::enemyCollider(D3DXVECTOR2 posEnemy, D3DXVECTOR2 sizeEnemy, D3DXVECTOR2 posStone, D3DXVECTOR2 sizeStone)
//{
//	RECT enemy;
//	RECT stone;
//
//	enemy.left = posEnemy.x + 8;
//	enemy.right = posEnemy.x + sizeEnemy.x - 8;
//	enemy.top = posEnemy.y + 8;
//	enemy.bottom = posEnemy.y + sizeEnemy.y;
//
//	stone.left = posStone.x;
//	stone.right = posStone.x + sizeStone.x;
//	stone.top = posStone.y;
//	stone.bottom = posStone.y + sizeStone.y;
//
//
//	if (enemy.bottom < stone.top) return false;
//	if (enemy.right < stone.left) return false;
//	if (enemy.left > stone.right) return false;
//	if (enemy.top > stone.bottom) return false;
//	return true;
//}
//
//bool Collider::isColliderDoor(D3DXVECTOR2 posCharacter, D3DXVECTOR2 sizeCharacter, D3DXVECTOR2 posDoor)
//{
//	RECT character3;
//	RECT door;
//
//	character3.left = posCharacter.x + 20;
//	character3.right = posCharacter.x + sizeCharacter.x - 20;
//	character3.top = posCharacter.y;
//	character3.bottom = posCharacter.y + sizeCharacter.y + 8;
//
//	door.left = posDoor.x;
//	door.right = posDoor.x + 32;
//	door.top = posDoor.y;
//	door.bottom = posDoor.y + 64 + 8;
//
//
//	if (character3.bottom < door.top) return false;
//	if (character3.right < door.left) return false;
//	if (character3.left > door.right) return false;
//	if (character3.top > door.bottom) return false;
//	return true;
//}
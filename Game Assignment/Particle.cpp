#include "Particle.h"
#include "Graphic.h"
#include "Character.h"
#include "Enemy.h"
#include "Collider.h"
#include "fieball.h"

Collider* colliderp = new Collider;

Particle::Particle()
{
	sprite = NULL;
	texture = NULL;
}

Particle::~Particle()
{

}

void Particle::init()
{
	D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/green.png", &texture);

	particle_index = 0;
	for (int i = 0; i < 1000; i++)
	{
		pposition[i].x = 0;
		pposition[i].y = -500;

		pvelocity[i].x = 0;
		pvelocity[i].y = 1;
	}

	particledraw = false;
}

void Particle::fixedUpdate()
{

	for (int i = 0; i < 1000; i++)
	{
		pposition[i] += pvelocity[i];
	}

}

int Particle::update(int i)
{
	if (colliderp->isCollide(fieball::getInstance()->positionf, fieball::getInstance()->size, Enemy::getInstance()->enemyPosition, Enemy::getInstance()->enemySize)) {
		i = 0;
		if (i < 60)
			particledraw = true;	
	}
	if (i >= 60)
	{
		for (int i = 0; i < 1000; i++)
		{
			pposition[i].x = 0;
			pposition[i].y = -500;

			pvelocity[i].x = 0;
			pvelocity[i].y = 1;
		}
		particledraw = false;
	}
	
	
	if (particledraw == true)
	{
		pposition[particle_index] = Enemy::getInstance()->enemyPosition;
		
		int degree = rand() % 360;
		float rad = degree / 180.0 * 3.142;
		pvelocity[particle_index].x = sin(rad);
		
		pvelocity[particle_index].y = -cos(rad);

		particle_index++;
		particle_index %= 1000;
	}
	return i;
}

void Particle::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	for (int i = 0; i < 1000; i++)
	{
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, 0, &pposition[i]);
		sprite->SetTransform(&mat);
		sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}


	sprite->End();
}

void Particle::release()
{

	texture->Release();

}
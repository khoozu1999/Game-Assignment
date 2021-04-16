#include "Particle.h"
#include "Graphic.h"
#include "Character.h"


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
	D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/particle.png", &texture);

	//ZeroMemory(&pposition, sizeof(pposition));
	particle_index = 0;
	for (int i = 0; i < 1000; i++)
	{
		pposition[i].x = 100;
		pposition[i].y = 350;

		pvelocity[i].x = 0;
		pvelocity[i].y = 1;
	}
}

void Particle::fixedUpdate()
{
	
	for (int i = 0; i < 1000; i++)
	{
		pposition[i] += pvelocity[i];
	}

}

void Particle::update()
{
	pposition[particle_index] = Character::getInstance()->charPosition;

	int degree = rand() % 360;
	float rad = degree / 180.0 * 3.142;
	pvelocity[particle_index].x = sin(rad);
	pvelocity[particle_index].y = -cos(rad);

	particle_index++;
	particle_index %= 1000;
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
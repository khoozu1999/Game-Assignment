#include "stdio.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "Background.h"
#include "Windows.h"
#include "Character.h"



Background* Background::sInstance = NULL;

Background* Background::getInstance()
{
	if (Background::sInstance == NULL)
	{
		sInstance = new Background;
	}

	return sInstance;
}

void Background::releaseInstance()
{
	
	sInstance = NULL;
}

Background::Background() {

	bgTexture1 = NULL;
	bgSprite = NULL;


	backgroundRect = { 0,0,720,520};

}

Background::~Background()
{
	
}

void Background::init() {

	HRESULT hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &bgSprite);

	hr = D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/background.png", &bgTexture1);
	

	spriteRect.left = spriteRect.top = 0;
	spriteRect.right = spriteRect.bottom = 32;
}

void Background::update() {

}
void Background::fixedUpdate() {

	
}

void Background::draw() {

	bgSprite->Begin(D3DXSPRITE_ALPHABLEND);

	bgSprite->Draw(bgTexture1, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	
	bgSprite->End();
	
}

void Background::release()
{
	bgSprite->Release();
	bgSprite = NULL;

	bgTexture1->Release();
	
	bgTexture1 = NULL;

	delete drawPosition;


}
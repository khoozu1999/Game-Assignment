#include "stdio.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Graphic.h"
#include "Background.h"
#include "Windows.h"

Background::Background() {

	bgTexture1 = NULL;
	bgTexture2 = NULL;
	bgTexture3 = NULL;
	bgTexture4 = NULL;
	bgSprite = NULL;


	backgroundRect = { 0,0,270,104};

}

Background::~Background()
{

}

void Background::init() {

	HRESULT hr = D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &bgSprite);

	hr = D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/building1.png", &bgTexture1);
	hr = D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/building2.png", &bgTexture2);
	hr = D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/building3.png", &bgTexture3);
	hr = D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/building4.png", &bgTexture4);

	spriteRect.left = spriteRect.top = 0;
	spriteRect.right = spriteRect.bottom = 32;
}

void Background::update() {

}
void Background::fixedUpdate() {

}

void Background::drawBackground() {

	bgSprite->Begin(D3DXSPRITE_ALPHABLEND);

	bgSprite->Draw(bgTexture1, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	bgSprite->Draw(bgTexture2, &backgroundRect, NULL, &drawPosition[1][2], D3DCOLOR_XRGB(255, 255, 255));
	bgSprite->Draw(bgTexture3, &backgroundRect, NULL, &drawPosition[1][3], D3DCOLOR_XRGB(255, 255, 255));
	bgSprite->Draw(bgTexture4, &backgroundRect, NULL, &drawPosition[1][4], D3DCOLOR_XRGB(255, 255, 255));

	bgSprite->End();
	
}

void Background::release()
{
	bgSprite->Release();
	bgSprite = NULL;

	bgTexture1->Release();
	bgTexture2->Release();
	bgTexture3->Release();
	bgTexture4->Release();
	bgTexture1 = NULL;
	bgTexture2 = NULL;
	bgTexture3 = NULL;
	bgTexture4 = NULL;

	delete drawPosition;


}
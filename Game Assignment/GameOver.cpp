#include "GameOver.h"
#include "Graphic.h"
#include "Background.h"
#include "DirectInput.h"
#include "GameStateManager.h"

GameOver::GameOver(){

}

GameOver::~GameOver(){

}

void GameOver::init() {

	D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &sprite);

	D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/background.png", &background);

	D3DXCreateFont(Graphic::getInstance()->d3dDevice, 60, 0, 0, FW_BOLD, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &gameOver);

	D3DXCreateFont(Graphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font);



	gameOverRect.left = 180;
	gameOverRect.top = 130;
	gameOverRect.right = 800;
	gameOverRect.bottom = 600;

	fontRect.left = 200;
	fontRect.top = 250;
	fontRect.right = 520;
	fontRect.bottom = 600;
}

void GameOver::update() {

	if (DirectInput::getInstance()->diKeys[DIK_R])
	{
		release();
		GameStateManager::getInstance()->currentState = 1;
		init();
	}
}

void GameOver::fixedUpdate() {

}

void GameOver::draw() {

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(background, &backgroundRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	gameOver->DrawText(sprite, "GAME OVER", -1, &gameOverRect, 0, D3DCOLOR_XRGB(255, 255, 0));

	font->DrawText(sprite, "R for Restart", -1, &fontRect, DT_RIGHT, D3DCOLOR_XRGB(255, 255, 0));

	sprite->End();
}

void GameOver::release() {


	sprite->Release();
	sprite = NULL;

	background->Release();
	background = NULL;

	gameOver->Release();
	gameOver = NULL;
}

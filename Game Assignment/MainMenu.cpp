#include <d3d9.h>
#include <stdio.h>
#include "MainMenu.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"

MainMenu::MainMenu() {

	titleSprite = NULL;

}

MainMenu:: ~MainMenu() {

}

void MainMenu::init() {

	

	timer = 0;


	 D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &titleSprite);
	 D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/background.png", &background);
	 D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/gameTitle.png", &gameTitle);
	 D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/button.png", &buttonImage);
	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font);

	
	gameTitleRect.left = gameTitleRect.top = 0;
	gameTitleRect.right = 40;
    gameTitleRect.bottom = 60;

	rectFont.left = 50;
	rectFont.top = 160;
	rectFont.right = 350;
	rectFont.bottom = 300;

	backgroundRect.top = 0;
	backgroundRect.bottom =520;
	backgroundRect.left = 0;
	backgroundRect.right = 720;

	gameTitleRect.top = 10;
	gameTitleRect.left = 10;
	gameTitleRect.bottom = gameTitleRect.top + 100;
	gameTitleRect.right = gameTitleRect.left + 200;

	//Start Button
	//Button* button = new Button;
	//button->position.x = BUFFER_WIDTH / 2;
	//button->position.y = 500;
	//button->size.x = 259;
	//button->size.y = 84;
}

void MainMenu::update() {

}

void MainMenu::fixedUpdate() {

}

void MainMenu::draw() {

	
	titleSprite->Begin(D3DXSPRITE_ALPHABLEND);

	titleSprite-> Draw(background, &backgroundRect, NULL, NULL, D3DCOLOR_XRGB(255, 255,255));
	titleSprite->Draw(gameTitle, &gameTitleRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	
	
	titleSprite->End();
}

void MainMenu::release() {

	titleSprite->Release();
	titleSprite = NULL;

	buttonImage->Release();
	buttonImage = NULL;

	background->Release();
	background = NULL;

	font->Release();
	font = NULL;

	gameTitle->Release();
	gameTitle = NULL;
}
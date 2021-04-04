#include <d3d9.h>
#include <stdio.h>
#include "MainMenu.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"

MainMenu::MainMenu() {

	sprite = NULL;

}

MainMenu:: ~MainMenu() {

}

void MainMenu::init() {



	D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &sprite);

	 D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/background.png", &background); 


	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 60, 0, 0, FW_BOLD, false,
		 DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		 DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &gameTitle);

	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		 DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		 DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font);
	 
	
	 gameTitleRect.left =180;
	 gameTitleRect.top = 130;
	 gameTitleRect.right = 800;
	 gameTitleRect.bottom = 600;

	 fontRect.left = 200;
	 fontRect.top = 300;
	 fontRect.right = 520;
	 fontRect.bottom = 600;

	backgroundRect.top = 0;
	backgroundRect.bottom =520;
	backgroundRect.left = 0;
	backgroundRect.right = 720;

	

	//Start Button
	//Button* button = new Button;
	//button->position.x = BUFFER_WIDTH / 2;
	//button->position.y = 500;
	//button->size.x = 259;
	//button->size.y = 84;
}

void MainMenu::update() {

		/*if (DirectInput::getInstance()->isKeyDown(DIK_RETURN))
		{
			release();
			GameStateManager::getInstance()->currentState = GameStateManager::LEVEL;
			init();
		}*/
	
}

void MainMenu::fixedUpdate() {

}

void MainMenu::draw() {

	
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(background, &backgroundRect, NULL, NULL, D3DCOLOR_XRGB(255, 255,255));
	gameTitle->DrawText(sprite, TITLE,-1, &gameTitleRect, 0, D3DCOLOR_XRGB(255, 255, 0));
	font->DrawText(sprite, "Press \"Enter\" to Play", -1, &fontRect, DT_CENTER, D3DCOLOR_XRGB(255, 255, 0));
	
	sprite->End();
}

void MainMenu::release() {

	sprite->Release();
	sprite = NULL;


	background->Release();
	background = NULL;



	gameTitle->Release();
	gameTitle = NULL;
}
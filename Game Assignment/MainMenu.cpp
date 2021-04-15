#include <d3d9.h>
#include <stdio.h>
#include "MainMenu.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"
#include "Level.h"
#include "fmod.hpp"
#include "Sound.h"

MainMenu::MainMenu() {

	sprite = NULL;
	Sound::getInstance()->playMainSound();
	
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

	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 30, 0, 0, 1, false,
		 DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		 DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font2);


	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 20, 0, 0, 1, false,
		 DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		 DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font3);


	 D3DXCreateFont(Graphic::getInstance()->d3dDevice, 20, 0, 0, 1, false,
		 DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		 DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", &font4);




	 
	
	 gameTitleRect.left =180;
	 gameTitleRect.top = 130;
	 gameTitleRect.right = 800;
	 gameTitleRect.bottom = 600;

	 fontRect.left = 200;
	 fontRect.top = 250;
	 fontRect.right = 520;
	 fontRect.bottom = 600;

	 fontRect2.left = 200;
	 fontRect2.top = 300;
	 fontRect2.right = 520;
	 fontRect2.bottom = 700;


	 fontRect3.left = 200;
	 fontRect3.top = 200;
	 fontRect3.right = 500;
	 fontRect3.bottom = 400;


	 fontRect4.left = 200;
	 fontRect4.top = 200;
	 fontRect4.right = 300;
	 fontRect4.bottom = 400;

	 

	backgroundRect.top = 0;
	backgroundRect.bottom =520;
	backgroundRect.left = 0;
	backgroundRect.right = 720;

	
}

void MainMenu::update() {

	if (DirectInput::getInstance()->diKeys[DIK_RETURN])
		{
			release();

			GameStateManager::getInstance()->currentState = 1;
			init();
		}

	system->update();
}

void MainMenu::fixedUpdate() {

}

void MainMenu::draw() {

	
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(background, &backgroundRect, NULL, NULL, D3DCOLOR_XRGB(255, 255,255));
	gameTitle->DrawText(sprite, TITLE,-1, &gameTitleRect, 0, D3DCOLOR_XRGB(255, 255, 0));
	font->DrawText(sprite, "Press \"Enter\" to Play", -1, &fontRect, DT_CENTER, D3DCOLOR_XRGB(255, 255, 0));
	font2->DrawText(sprite, "Press \"Esc\" to Exit", -1, &fontRect2, DT_CENTER, D3DCOLOR_XRGB(255, 255, 0));
	font3->DrawText(sprite, "P to Go Back Main Menu", -1, &fontRect3, DT_RIGHT, D3DCOLOR_XRGB(255, 255, 0));
	font4->DrawText(sprite, "R for Restart", -1, &fontRect4, DT_RIGHT, D3DCOLOR_XRGB(255, 255, 0));
	
	
	

	
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
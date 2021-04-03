//#include <d3d9.h>
//#include <stdio.h>
//#include "MainMenu.h"
//#include "Graphic.h"
//#include "GameStateManager.h"
//#include "DirectInput.h"
//
//MainMenu::MainMenu() {
//
//	titleSprite = NULL;
//}
//
//MainMenu:: ~MainMenu() {
//
//}
//
//void MainMenu::init() {
//
//	D3DXCreateSprite(Graphic::getInstance()->d3dDevice, &titleSprite);
//	D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/Button.jpg", &buttonImage);
//	D3DXCreateTextureFromFile(Graphic::getInstance()->d3dDevice, "resource/Background.png", &background);
//	D3DXCreateFont(Graphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
//		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
//		DEFAULT_PITCH | FF_DONTCARE, "Century Schoolbook", GAMETITLE);
//
//	GameTitleRect.top = 100;
//	GameTitleRect.left = 750;
//	GameTitleRect.bottom = GameTitleRect.top + 200;
//	GameTitleRect.right = GameTitleRect.left + 2000;
//
//	//Start Button
//	/*Button* button = new Button;
//	button->position.x = BUFFER_WIDTH / 2;
//	button->position.y = 500;
//	button->size.x = 259;
//	button->size.y = 84;*/
//}
//
//void MainMenu::update() {
//
//}
//
//void MainMenu::fixedUpdate() {
//
//}
//
//void MainMenu::draw() {
//
//}
//
//void MainMenu::release() {
//
//	titleSprite->Release();
//	titleSprite = NULL;
//
//	buttonImage->Release();
//	buttonImage = NULL;
//
//	background->Release();
//	background = NULL;
//
//
//	gameTitle->Release();
//	gameTitle = NULL;
//}
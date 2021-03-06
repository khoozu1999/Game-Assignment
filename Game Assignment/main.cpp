#include "Windows.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"
#include "Sound.h"
#pragma warning(disable:4996)

int main()
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)

{
	KZWindows* windows = KZWindows::getInstance();
	windows->createWindows();
	Graphic::getInstance()->createDirectX();
	DirectInput::getInstance()->CreateInput();

	while (windows->loop())
	{
		DirectInput::getInstance()->InputLoop();
		GameStateManager::getInstance()->update();
		Sound::getInstance()->update();
		Graphic::getInstance()->present();
	}

	windows->clearWindows();
	Graphic::getInstance()->clearGraphic();
	DirectInput::getInstance()->clearInput();
	
	delete windows;
	Graphic::getInstance()->releaseInsrance();
	DirectInput::getInstance()->releaseInsrance();
	GameStateManager::getInstance()->releaseInsrance();

	return 0;
	
}
#include "Windows.h"
#include "Graphic.h"
#include "GameStateManager.h"
#include "DirectInput.h"

int main()
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
//This is the testing command line look here
{
	KZWindows* windows = KZWindows::getInstance();
	windows->createWindows();

	Graphic::getInstance()->createDirectX();
	DirectInput::getInstance()->CreateInput();

	while (windows->loop())
	{

	}

	windows->clearWindows();
	Graphic::getInstance()->clearGraphic();
	DirectInput::getInstance()->clearInput();
	
	delete windows;
	Graphic::getInstance()->releaseInsrance();
	DirectInput::getInstance()->releaseInsrance();
	GameStateManager::getInstance()->releaseInsrance();

	return 0;
	//hello nicholas
}
#include "UI.h"


UI::UI() {


	hpRect.top = 220;
	hpRect.bottom = 0;
	hpRect.left = 26;
	hpRect.right = 250;


	hpPosition1 = {10,370,0};
	hpPosition1 = {50,370,0};
	hpPosition1 = {90,370,0};

	hpPosition2 = { 10,370,0 };
	hpPosition2 = { 50,370,0 };
	hpPosition2 = { 90,370,0 };


	hpPosition3 = { 10,370,0 };
	hpPosition3 = { 50,370,0 };
	hpPosition3 = { 90,370,0 };

}

UI::~UI() {


	hpRect.top = NULL;
	hpRect.bottom = NULL;
	hpRect.left = NULL;
	hpRect.right = NULL;
}


void UI::draw() {

}

#include <d3dx9.h>
#include "GameState.h"


class Button : public GameState {
public:
	Button();
	~Button();



	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();

	int function;
	float timer;
	bool isFunction;

	RECT GameTitleRect;

	LPDIRECT3DTEXTURE9 buttonImage;
	LPD3DXSPRITE titleSprite;
	LPD3DXFONT gameTitle;

}
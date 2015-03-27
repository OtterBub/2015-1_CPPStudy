#ifndef __GAMESTATE_TEST_STATE_H__
#define __GAMESTATE_TEST_STATE_H__

#include "GameState.h"
#include "GameObject.h"

class GameStateTestState : public GameState
{
public:
	GameStateTestState( GameFrame* frame );
	~GameStateTestState();

	bool Update( float deltaTime );
	bool Draw( DisplaySys* display );

	bool Enter();
	bool Exit();

	bool KeyUp( WORD keycode );
	bool KeyDown( WORD keycode );

private:
	OtterVector2ui mCharPos;
	GameObject mObj;
};

#endif 
#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <chrono>
#include "OtterVector.cpp"
#include "DisplaySys.h"
#include "Utill.h"

class GameFrame;

class GameState
{
public:
	GameState( GameFrame* frame ) 
	{ 
		mFrame = frame;
		memset( mKeyinput, false, sizeof( bool ) * 0xFF );
	}

	~GameState() {}

	virtual bool Update( float deltaTime ) = 0;
	virtual bool Draw( DisplaySys* display ) = 0;
	
	virtual bool Enter() = 0;
	virtual bool Exit() = 0;

	virtual bool KeyDown( WORD keycode ) { return true; }
	virtual bool KeyUp( WORD keycode ) { return true; }
	void KeyInputClear() { memset( mKeyinput, false, sizeof( bool ) * 0xFF ); }

protected:
	GameFrame* mFrame;
	bool mKeyinput[0xFF];
};


#endif

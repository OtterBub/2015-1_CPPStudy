#ifndef __GAME_FRAME_H__
#define __GAME_FRAME_H__

#include "GameState.h"

class GameFrame
{
public:
	GameFrame( OtterVector2ui screenSize );
	~GameFrame();

	bool Initialize();
	bool Run();	

	bool SetFPS( unsigned int fps );
	bool SetState( GameState* state );

	DisplaySys* GetDisplayPointer();

private:
	DisplaySys mDisplay;
	GameState* mCurrentGameState;
	std::chrono::time_point< std::chrono::system_clock > mCurrentTime;
	std::chrono::duration<float> mDeltaTime;
	unsigned int mFPS;
	float mTimeDuration;
};

#endif 
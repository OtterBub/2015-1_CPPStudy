#include "GameFrame.h"

GameFrame::GameFrame( OtterVector2ui screenSize ) :
mDisplay( screenSize )
{
	mFPS = 0;
	mCurrentGameState = nullptr;
}

GameFrame::~GameFrame()
{
}

bool GameFrame::Initialize()
{
	return true;
}

bool GameFrame::Run()
{
	static int lFPS = 0;
	static std::chrono::time_point<std::chrono::system_clock> mFPSTime;
	static std::chrono::duration<float> mFPSDeltaTime;
	WORD keyinput;
	
	mFPSTime = std::chrono::system_clock::now();
	mCurrentTime = std::chrono::system_clock::now();

	while( 1 )
	{
		mDeltaTime = std::chrono::system_clock::now() - mCurrentTime;

		if( mCurrentGameState == nullptr )
		{
			std::cout << "GameState is Null" << std::endl;
			return false;
		}

		if( mCurrentGameState && ( mTimeDuration < mDeltaTime.count() ) )
		{
			// Check KeyInput
			keyinput = win32_kbdown();
			if ( keyinput )
				mCurrentGameState->KeyDown( keyinput );
			else
				mCurrentGameState->KeyInputClear();

			/* keyinput = win32_kbup();
			if( keyinput )
				mCurrentGameState->KeyUp( keyinput ); */
			
			
			// Update Game
			mCurrentGameState->Update( mDeltaTime.count() );
			mCurrentTime = std::chrono::system_clock::now();

			// Draw Display
			mDisplay.Clear();
			mCurrentGameState->Draw( &mDisplay );
			mDisplay.Draw();

			mFPSDeltaTime = std::chrono::system_clock::now() - mFPSTime;
			lFPS++;

			// View Frame Per Second
			if( 1.0f < mFPSDeltaTime.count() )
			{
				mFPSTime = std::chrono::system_clock::now();
				std::cout << lFPS;
				lFPS = 0;
			}
		}
	}
	return true;
}

bool GameFrame::SetFPS( unsigned int fps )
{
	mFPS = fps;
	mTimeDuration = 1 / static_cast<float>(mFPS);
	return true;
}

bool GameFrame::SetState( GameState* state )
{
	if( mCurrentGameState != nullptr )
	{
		mCurrentGameState->Exit();
		delete mCurrentGameState;
	}
	mCurrentGameState = state;
	mCurrentGameState->Enter();
	return true;
}

DisplaySys* GameFrame::GetDisplayPointer()
{
	return &mDisplay;
}
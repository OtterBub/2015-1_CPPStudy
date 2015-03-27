#include "GameStateTestState.h"
#include "GameFrame.h"

GameStateTestState::GameStateTestState( GameFrame* frame ) :
GameState( frame )	
{

}
GameStateTestState::~GameStateTestState()
{

}

bool GameStateTestState::Update( float deltaTime )
{
	if( mKeyinput[0x41] )
		mObj.Translate( OtterVector2ui( -1, 0 ) );

	if( mKeyinput[0x44] )
		mObj.Translate( OtterVector2ui( +1, 0 ) );

	if( mKeyinput[0x57] )
		mObj.Translate( OtterVector2ui( 0, -1 ) );

	if( mKeyinput[0x53] )
		mObj.Translate( OtterVector2ui( 0, +1 ) );

	return true;
}
bool GameStateTestState::Draw( DisplaySys* display )
{

	mObj.Draw( display );
	return true;
}

bool GameStateTestState::Enter()
{
	mObj.SetModel( 'C' );
	mObj.SetPosition( OtterVector2ui( 2, 2 ) );
	return true;
}

bool GameStateTestState::Exit()
{
	return true;
}

bool GameStateTestState::KeyDown( WORD keycode )
{
	
	mKeyinput[ keycode ] = true;
	return true;
}

bool GameStateTestState::KeyUp( WORD keycode )
{
	mKeyinput[ keycode ] = false;
	return true;
}
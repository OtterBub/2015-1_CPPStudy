#include <iostream>
#include "GameFrame.h"
#include "GameStateTestState.h"

int main()
{
	GameFrame frame( OtterVector2ui( 30, 20 ) );
	frame.SetState( new GameStateTestState( &frame ) );
	frame.SetFPS( 30 );

	frame.Run();

	return 0;
}
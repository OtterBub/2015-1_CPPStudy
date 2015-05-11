#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Character.h"

int main()
{
	// Initialize
	const int width = 30, height = 30;
	//const int moveTime = 1000;
	//int CurrentTime = std::clock();
	//int PlayTime = CurrentTime;
	std::string map[width * height];

	for( int i = 0; i < height; ++i )
		map[i].resize( width );

	Character lChar;

	lChar.SetPosition( Position( 10, 1 ) );
	lChar.SetModel( 'A' );

	// GameLoop
	while( 1 )
	{
		COORD pos = { 0, };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), pos );

		// Map Display Claer
		for( int i = 0; i < height; ++i ) {
			for( int j = 0; j < width; ++j ) {
				map[i][j] = '.';
			}
		}
		
		//CurrentTime = std::clock();

		/*if( moveTime < ( CurrentTime - PlayTime ) ){
			lChar.Translate( 0, 1 );
			PlayTime = std::clock();
		}*/

		// Game Algorithm
		Position move;

		if( ( GetAsyncKeyState( VK_DOWN ) & 0x8000 ) == 0x8000 )
			move.y = 1;
		if( ( GetAsyncKeyState( VK_UP ) & 0x8000 ) == 0x8000 )
			move.y = -1;
		if( ( GetAsyncKeyState( VK_RIGHT ) & 0x8000 ) == 0x8000 )
			move.x = 1;
		if( ( GetAsyncKeyState( VK_LEFT ) & 0x8000 ) == 0x8000 )
			move.x = -1;

		lChar.Translate( move );

		Position lCharPosition = lChar.GetPosition();
		map[lCharPosition.y][lCharPosition.x] = lChar.GetModel();

		// Draw Game
		for( int i = 0; i < height; ++i )
			std::cout << map[i] << std::endl;
		
		std::cout << std::endl;

		Sleep( 30 );
	}

	return 0;
}
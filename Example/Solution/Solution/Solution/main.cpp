#include <iostream>
#include <string>
#include <Windows.h>
#include "Character.h"

int main()
{
	// Initialize
	const int width = 30, height = 30;
	std::string map[width * height];
	Character lChar;

	for( int i = 0; i < height; ++i )
		map[i].resize( width );

	lChar.SetPosition( Position( 10, 1 ) );
	lChar.SetModel( 'A' );

	// GameLoop
	while( 1 )
	{
		// Map Display Claer
		for( int i = 0; i < height; ++i )
		{
			for( int j = 0; j < width; ++j )
			{
				map[i][j] = '.';
			}
		}

		// Game Algorithm
		if( ( GetAsyncKeyState( VK_DOWN ) & 0x8000 ) == 0x8000 )
			lChar.Translate( Position( 0, 1 ) );
		if( ( GetAsyncKeyState( VK_UP ) & 0x8000 ) == 0x8000 )
			lChar.Translate( 0, -1 );
		if( ( GetAsyncKeyState( VK_RIGHT ) & 0x8000 ) == 0x8000 )
			lChar.Translate( Position( 1, 0 ) );
		if( ( GetAsyncKeyState( VK_LEFT ) & 0x8000 ) == 0x8000 )
			lChar.Translate( -1, 0 );

		Position lCharPosition = lChar.GetPosition();
		map[lCharPosition.y][lCharPosition.x] = lChar.GetModel();

		COORD pos = { 0, 0 };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos );
		// Draw Game
		for( int i = 0; i < height; ++i )
			std::cout << map[i] << std::endl;
		
		std::cout << std::endl;

		Sleep( 30 );
	}

	return 0;
}
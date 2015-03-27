#include "DisplaySys.h"

DisplaySys::DisplaySys( OtterVector2ui screenSize )
{
	mScreenSize = screenSize;
	mDisplayStr.resize( ( mScreenSize.x + 1 ) * ( mScreenSize.y + 1 ) );	

	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &info );
	info.bVisible = false;
	SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &info );
}

DisplaySys::DisplaySys( int width, int height )
{
	mScreenSize.x = width;
	mScreenSize.y = height;

	mDisplayStr.resize( ( mScreenSize.x + 1 ) * ( mScreenSize.y + 1 ) );

	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &info );
	info.bVisible = false;
	SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &info );
}

DisplaySys::~DisplaySys()
{
	
}

bool DisplaySys::Clear()
{
	int lCurrentPos = 0;
	for( unsigned int y = 0; y < mScreenSize.y; ++y )
	{
		for( unsigned int x = 0; x <= mScreenSize.x; ++x )
		{
			lCurrentPos = x + ( y * mScreenSize.x ) + y;
			mDisplayStr[ lCurrentPos ] = '.';
			
			if( x == ( mScreenSize.x ) )
			{
				mDisplayStr[ lCurrentPos ] = '\n';
			}
		}
	}
	//system( "cls" );
	return true;
}

bool DisplaySys::Draw()
{
	
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	// Set Windows Consol Caret Pos to ( 0, 0 )
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), pos );

	//Draw String on Console
	std::cout << mDisplayStr;

	return true;
}

bool DisplaySys::SetPosChar( OtterVector2ui pos, char model )
{
	int lPos = GetScreenPos( pos );
	mDisplayStr[lPos] = model;

	return true;
}

unsigned int DisplaySys::GetScreenPos( OtterVector2ui pos )
{
	return pos.x + ( pos.y * mScreenSize.x ) + pos.y;
}

unsigned int DisplaySys::GetBufferSize()
{
	return mDisplayStr.size();
}

std::string& DisplaySys::GetBuffer()
{
	return mDisplayStr;
}
#ifndef __DISPLAY_SYS_H__
#define __DISPLAY_SYS_H__

#include <Windows.h>
#include <string>
#include <iostream>
#include "OtterVector.cpp"

class DisplaySys
{
public:
	DisplaySys( OtterVector2ui screenSize );
	DisplaySys( int width, int height );
	~DisplaySys();

	bool Clear();
	bool Draw();

	bool SetPosChar( OtterVector2ui pos, char model );
	
	unsigned int GetScreenPos( OtterVector2ui pos );
	unsigned int GetBufferSize();
		
	std::string& DisplaySys::GetBuffer();

private:
	OtterVector2ui mScreenSize;
	std::string mDisplayStr;
};

#endif 
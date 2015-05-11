#include "Position.h"

class Character
{
public:

	void SetPosition( Position pos )
	{
		mPos = pos;
	}
	void SetPosition( int x, int y )
	{
		mPos.x = x;
		mPos.y = y;
	}
	void SetModel( char model )
	{
		mModel = model;
	}
	void Translate( Position trans ) 
	{
		mPos += trans;
	}
	void Translate( int x, int y )
	{
		mPos.x += x;
		mPos.y += y;
	}
	
	Position GetPosition()
	{
		return mPos;
	}
	char GetModel()
	{
		return mModel;
	}

private:
	Position mPos;
	char mModel;

};
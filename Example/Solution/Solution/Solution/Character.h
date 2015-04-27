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
		mPos = Position( x, y );
	}

	void SetModel( char model )
	{
		mModel = model;
	}

	void Translate( int x, int y )
	{
		mPos += Position( x, y );
	}
	void Translate( Position trans )
	{
		mPos += trans;
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
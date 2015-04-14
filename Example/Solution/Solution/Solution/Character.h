
class Position
{
public:

	Position( const Position& other )
	{
		this->x = other.x;
		this->y = other.y;
	}

	Position()
	{
		x = 0;
		y = 0;
	}

	Position( int x, int y )
	{
		this->x = x;
		this->y = y;
	}

public:
	int x, y;
};

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
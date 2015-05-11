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

	void operator+=( Position a ) {
		this->x += a.x;
		this->y += a.y;
	}

	void operator-= ( Position a ) {
		this->x -= a.x;
		this->y -= a.y;
	}
	

public:
	int x, y;

};
Position operator+( Position a, Position b ) {
	Position result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
}

Position operator-( Position a, Position b ) {
	Position result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;

	return result;
}

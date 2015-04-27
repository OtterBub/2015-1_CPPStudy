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
	Position operator+( const Position& other )
	{
		Position result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return result;
	}
	void operator+=( const Position& other )
	{
		this->x += other.x;
		this->y += other.y;
	}

	Position operator-( const Position& other )
	{
		Position result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;

		return result;
	}
	void operator-=( const Position& other )
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	Position operator*( const int& val )
	{
		Position result;
		result.x = this->x * val;
		result.y = this->y * val;

		return result;
	}
	void operator*=( const int& val )
	{
		this->x *= val;
		this->y *= val;
	}

public:
	int x, y;
};
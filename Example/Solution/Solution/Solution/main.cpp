#include <iostream>
#include <string>

class Position
{
public:
	Position( const Position& other )
	{

	}

	Position( float x, float y, float size )
	{
		std::cout << "Constructor" << std::endl;
		this->x = x;
		this->y = y;

		mpSize = new float(size);
	}

	~Position()
	{
		std::cout << "Destructor" << std::endl;
		
		if( mpSize != nullptr )
			delete mpSize;
	}

	void PrintPosition()
	{
		std::cout << x << ", " << y << std::endl;
	}

	
private:
	float x, y;
	float* mpSize;
};

void func()
{
	std::cout << "func Enter" << std::endl;
	Position pos( 10, 10, rand() );

	std::cout << "func Exit" << std::endl;
}

int main()
{
	int width = 30, height = 30;

	std::string str[ 50 ];
	
	for( int i = 0; i < height; ++i )
		str[i].resize( width );

	for( int i = 0; i < height; ++i )
	{
		for( int j = 0; j < width; ++j )
		{
			str[i][j] = '.';
		}
	}

	for( int i = 0; i < height; ++i )
		std::cout << str[i] << std::endl;

	return 0;
}
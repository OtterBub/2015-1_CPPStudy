#include <iostream>

class Position {
public:
	int x, y;
};

class ObjectInterface
{
public:
	virtual void Draw() = 0;
	void SetPosition( Position pos ) { mPos = pos; }
	Position GetPosition() { return mPos; }

protected:
	Position mPos;
};

class Object : public ObjectInterface
{
public:
	Object() { mPos.x = rand() % 100, mPos.y = rand() % 100; }
	void Draw() { std::cout << " ( " << mPos.x << ", " << mPos.y << " )" << std::endl; }	
};

class Char : public Object
{
public:
	Char() : Object() {}
	void Draw() {
		std::cout << mModel
			<< " HP: " << HP
			<< " MP: " << MP;

		Object::Draw();
	}
	void SetModel( char model ) { mModel = model; }
	void SetHPMP( int hp, int mp ) { HP = hp, MP = mp; }

private:
	char mModel;
	int HP, MP;
};

class Door : public Object
{
public:
	Door() : Object() {}
	void Draw() {

		std::cout << "Door is ";
		if( mBreakable ) {
			std::cout << "Can Break";
		}
		else {
			std::cout << "Cant Break";
		}
		Object::Draw();
	}
	void SetBreakable( bool able ) { mBreakable = able; }

private:
	char mModel;
	bool mBreakable;
};



int main()
{
	ObjectInterface* obj[5] = { 0, };

	Char* lCharA = new Char();
	Char* lCharB = new Char();
	Char* lCharC = new Char();
	Door* lDoorA = new Door();
	Door* lDoorB = new Door();

	lCharA->SetModel( 'A' );
	lCharB->SetModel( 'B' );
	lCharC->SetModel( 'C' );

	lCharA->SetHPMP( 10, 30 );
	lCharB->SetHPMP( 100, 0 );
	lCharC->SetHPMP( 30, 30 );

	lDoorA->SetBreakable( true );
	lDoorB->SetBreakable( false );

	obj[0] = lCharA;
	obj[1] = lCharB;
	obj[2] = lCharC;
	obj[3] = lDoorA;
	obj[4] = lDoorB;

	for( int i = 0; i < 5; ++i ) {
		obj[i]->Draw();
	}

	return 0;
}

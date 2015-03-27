#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "OtterVector.cpp"
#include "DisplaySys.h"

class GameObject
{
public:
	GameObject();
	GameObject( char model );
	~GameObject();

	virtual bool Update( float dt );
	virtual bool Draw( DisplaySys* display );

	bool SetPosition( OtterVector2ui pos );
	bool Translate( OtterVector2ui trans );
	bool SetModel( char model );

private:
	OtterVector2ui mPosition;
	char mModel;
};

#endif
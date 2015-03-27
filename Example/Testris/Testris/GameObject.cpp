#include "GameObject.h"

GameObject::GameObject()
{
	mModel = '.';
}

GameObject::GameObject( char model )
{
	mModel = model;
}

GameObject::~GameObject()
{
}

bool GameObject::Update( float dt )
{
	return true;
}

bool GameObject::Draw( DisplaySys* display )
{
	display->SetPosChar( mPosition, mModel );

	return true;
}

bool GameObject::SetPosition( OtterVector2ui pos )
{
	mPosition = pos;
	return true;
}

bool GameObject::Translate( OtterVector2ui trans )
{
	mPosition += trans;
	return true;
}

bool GameObject::SetModel( char model )
{
	mModel = model;
	return true;
}
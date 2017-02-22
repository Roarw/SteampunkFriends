#include "Wall.h"

Wall::Wall(GameObject * gameObject) : Component(gameObject)
{
}

Wall::~Wall()
{
}

void Wall::OnCollisionEnter(GameObject * other)
{
	gameObject->GetGameWorld()->DeleteObject(other);
}

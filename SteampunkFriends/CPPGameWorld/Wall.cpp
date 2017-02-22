#include "Wall.h"

std::string Wall::GetName()
{
	return "Wall";
}

Wall::Wall(GameObject * gameObject) : Component(gameObject)
{
}

Wall::~Wall()
{
}

void Wall::OnCollisionEnter(GameObject * other)
{
	//gameObject->GetGameWorld()->DeleteObjectNext(other);
}

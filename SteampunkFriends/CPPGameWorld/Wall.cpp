#include "Wall.h"
#include "Enemy.h"

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
	if ((Enemy*)other->GetComponent("Enemy") != NULL)
	{
		//gameObject->GetGameWorld()->DeleteObjectNext(other);
	}
}

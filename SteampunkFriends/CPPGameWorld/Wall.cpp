#include "Wall.h"
#include "Enemy.h"

#pragma region METHODS:
void Wall::OnCollisionEnter(GameObject * other)
{
	if ((Enemy*)other->GetComponent("Enemy") != NULL)
	{
		((Enemy*)other->GetComponent("Enemy"))->PlayDead(Vector2(0, 0));
	}
}
#pragma endregion

#pragma region GET/SET:
std::string Wall::GetName()
{
	return "Wall";
}
#pragma endregion

#pragma region CONSTRUCTORS:
Wall::Wall(GameObject * gameObject) : Component(gameObject)
{
}

Wall::~Wall()
{
}
#pragma endregion

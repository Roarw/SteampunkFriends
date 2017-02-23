#include "Wall.h"
#include "Enemy.h"

#pragma region METHODS:
void Wall::OnCollisionEnter(GameObject * other)
{
	if ((Enemy*)other->GetComponent("Enemy") != NULL)
	{
		Vector2 deathDirection;

		switch (wallSide)
		{
		case LEFT_WALL:
			deathDirection = Vector2(-1, 0);
			break;
		case TOP_WALL:
			deathDirection = Vector2(0, 1);
			break;
		case RIGHT_WALL:
			deathDirection = Vector2(1, 0);
			break;
		case BOTTOM_WALL:
			deathDirection = Vector2(0, -1);
			break;
		default:
			deathDirection = Vector2(0, 0);
			break;
		}

		((Enemy*)other->GetComponent("Enemy"))->PlayDead(deathDirection);
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
Wall::Wall(GameObject * gameObject, SIDEWALL wallSide) : Component(gameObject)
{
	this->wallSide = wallSide;
}

Wall::~Wall()
{
}
#pragma endregion

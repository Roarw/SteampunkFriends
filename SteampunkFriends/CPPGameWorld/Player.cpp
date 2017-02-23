#include "Player.h"
#include "GameWorld.h"

#pragma region METHODS:
void Player::Update()
{
	Vector2 moveDirection;

	for (int key : gameObject->GetGameWorld()->GetKeys()) 
	{
		switch (key) {
		case GLUT_KEY_UP:
			moveDirection.Y += 1;
			break;
		case GLUT_KEY_DOWN:
			moveDirection.Y -= 1;
			break;
		case GLUT_KEY_LEFT:
			moveDirection.X -= 1;
			break;
		case GLUT_KEY_RIGHT:
			moveDirection.X += 1;
			break;
		default:
			break;
		}
	}

	if (moveDirection.X != 0 || moveDirection.Y != 0) 
	{
		direction->X = moveDirection.X;
		direction->Y = moveDirection.Y;
	}

	moveDirection = moveDirection * speed * gameObject->GetGameWorld()->GetDeltaTime();
	transform->Translate(moveDirection);
}
#pragma endregion

#pragma region GET/SET:
std::string Player::GetName()
{
	return "Player";
}

Vector2 * Player::GetDirection()
{
	return direction;
}
#pragma endregion

#pragma region CONSTRUCTORS:
Player::Player(GameObject * gameObject, Transform * transform) : Component(gameObject)
{
	this->transform = transform;
	direction = new Vector2(0, 0);

	speed = 100;
}

Player::~Player()
{
	delete direction;
}
#pragma endregion
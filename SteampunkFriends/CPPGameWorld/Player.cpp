#include "Player.h"
#include "GameWorld.h"

void Player::Update()
{
	delete direction;
	direction = new Vector2(0, 0);

	for (int key : gameObject->GetGameWorld()->GetKeys()) 
	{
		switch (key) {
		case GLUT_KEY_UP:
			direction->Y += 1;
			break;
		case GLUT_KEY_DOWN:
			direction->Y -= 1;
			break;
		case GLUT_KEY_LEFT:
			direction->X -= 1;
			break;
		case GLUT_KEY_RIGHT:
			direction->X += 1;
			break;
		default:
			break;
		}
	}

	*direction = *direction * speed * gameObject->GetGameWorld()->GetDeltaTime();
	transform->Translate(*direction);
}

std::string Player::GetName()
{
	return "Player";
}

Vector2 * Player::GetDirection()
{
	return direction;
}

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

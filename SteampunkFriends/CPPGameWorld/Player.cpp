#include "Player.h"
#include "GameWorld.h"


void Player::Update()
{
	delete direction;
	direction = new Vector2(0, 0);

	for (int key : gameWorld->GetKeys()) 
	{
		switch (key) {
		case GLUT_KEY_UP:
			direction->Y -= 1;
			break;
		case GLUT_KEY_DOWN:
			direction->Y += 1;
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

	transform->Translate(*direction);
}

Player::Player(GameObject * gameObject, GameWorld * gameWorld, Transform * transform) : Component(gameObject)
{
	this->gameWorld = gameWorld;
	this->transform = transform;
	direction = new Vector2(0, 0);
}

Player::~Player()
{
	delete direction;
}

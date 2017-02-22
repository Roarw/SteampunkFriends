#pragma once
#include "Component.h"
#include "Vector2.h"
#include "IUpdate.h"
#include "Transform.h"

class GameWorld;

class Player :
	public Component, public IUpdate
{
private:
	Vector2 * direction;
	GameWorld * gameWorld;
	Transform * transform;
public:
	void Update();

	Player(GameObject * gameObject, GameWorld * gameWorld, Transform * transform);
	~Player();
};


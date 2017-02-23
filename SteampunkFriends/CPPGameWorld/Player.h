#pragma once
#include "Component.h"
#include "Vector2.h"
#include "IUpdate.h"
#include "Transform.h"

class Physics;

class Player :
	public Component, public IUpdate
{
private:
	Vector2 * direction;
	Transform * transform;
	Physics * physics;
	float speed;
public:
	void Update();

	std::string GetName();
	Vector2 * GetDirection();

	Player(GameObject * gameObject, Transform * transform, Physics * physics);
	~Player();
};


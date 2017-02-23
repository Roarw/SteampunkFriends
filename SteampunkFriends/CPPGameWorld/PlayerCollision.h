#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLISION_H

#include "Component.h"
#include "Collider.h"
#include "Physics.h"

class PlayerCollision :
	public Component
{
private:
	Collider * collider;
	Physics * physics;

	bool CollidingAt(Collider * other);
public:
	void CheckCollision(Collider * other);

	PlayerCollision(GameObject * gameObject, Collider * collider, Physics * physics);
	~PlayerCollision();
};
#endif // !PLAYERCOLLISION_H

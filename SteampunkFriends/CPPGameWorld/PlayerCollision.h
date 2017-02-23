#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLISION_H

#include "Component.h"

#include "Vector2.h"
#include "RectangleF.h"

class Transform;
class Collider;
class Physics;

class PlayerCollision :
	public Component
{
private:
	Transform * transform;
	Collider * collider;
	Physics * physics;

	bool CollidingAt(Collider * other, Vector2 velocity);
public:
	void CheckCollision(Collider * other);

	std::string GetName();

	PlayerCollision(GameObject * gameObject, Transform * transform, Collider * collider, Physics * physics);
	~PlayerCollision();
};
#endif // !PLAYERCOLLISION_H

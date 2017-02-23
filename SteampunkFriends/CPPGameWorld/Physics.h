#ifndef PHYSICS_H
#define PHYSICS_H

#include "Component.h"

#include "IUpdate.h"
#include "Vector2.h"

class Transform;

class Physics :
	public Component, public IUpdate
{
private:
	Transform * transform;
public:
	Vector2 Velocity;

	void Update();

	std::string GetName();
	Vector2 GetVelocity();

	Physics(GameObject * g, Transform * transform);
	~Physics();
};
#endif // !PHYSICS_H

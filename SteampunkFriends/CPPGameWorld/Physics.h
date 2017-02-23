#pragma once
#include "Component.h"
#include "IUpdate.h"
#include "GameObject.h"
#include "Vector2.h"
#include "Transform.h"

class Physics :
	public Component, public IUpdate
{
private:
	Transform * transform;
public:
	Vector2 Velocity;

	void Update();

	std::string GetName();

	Physics(GameObject * g, Transform * transform);
	~Physics();
};


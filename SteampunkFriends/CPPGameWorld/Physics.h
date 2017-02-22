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
	std::string GetName();
	Vector2 Velocity;
	Physics(GameObject * g, Transform * transform);
	void Update();
	~Physics();
};


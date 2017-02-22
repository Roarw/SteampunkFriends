#pragma once
#include "GameObject.h"
#include "Component.h"
#include "IOnCollisionEnter.h"

class Wall :
	public Component, public IOnCollisionEnter
{
public:
	Wall(GameObject * gameObject);
	~Wall();
	void OnCollisionEnter(GameObject* other);
};


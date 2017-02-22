#pragma once
#include "GameObject.h"
#include "Component.h"
#include "IOnCollisionEnter.h"

class Wall :
	public Component, public IOnCollisionEnter
{
public:
	std::string GetName();
	Wall(GameObject * gameObject);
	~Wall();
	void OnCollisionEnter(GameObject* other);
};


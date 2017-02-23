#pragma once
#include "GameObject.h"
#include "Component.h"
#include "IOnCollisionEnter.h"

class Wall :
	public Component, public IOnCollisionEnter
{
public:
	void OnCollisionEnter(GameObject* other);

	std::string GetName();

	Wall(GameObject * gameObject);
	~Wall();
};


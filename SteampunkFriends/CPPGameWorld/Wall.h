#pragma once
#include "GameObject.h"
#include "Component.h"
#include "IOnCollisionEnter.h"
#include "Enums.h"

class Wall :
	public Component, public IOnCollisionEnter
{
private:
	SIDEWALL wallSide;
public:
	void OnCollisionEnter(GameObject* other);

	std::string GetName();

	Wall(GameObject * gameObject, SIDEWALL wallSide);
	~Wall();
};


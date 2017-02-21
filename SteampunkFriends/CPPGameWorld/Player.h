#pragma once
#include "Component.h"
class Player :
	public Component
{
public:
	Player(GameObject * gameObject);
	~Player();
};


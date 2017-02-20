#pragma once
#include "GameObject.h"

class IOnCollisionStay
{
public:
	virtual void OnCollisionStay(GameObject * other) {};
};


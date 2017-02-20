#pragma once
#include "GameObject.h"

class IOnCollisionExit
{
public:
	virtual void OnCollisionExit(GameObject * other) {};
};

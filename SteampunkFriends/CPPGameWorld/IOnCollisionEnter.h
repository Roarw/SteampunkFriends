#pragma once
#include "GameObject.h"

class IOnCollisionEnter
{
public:
	virtual void OnCollisionEnter(GameObject * other) {};
};
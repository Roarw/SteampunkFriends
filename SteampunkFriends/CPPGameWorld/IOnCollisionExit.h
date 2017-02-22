#pragma once

class GameObject;

class IOnCollisionExit
{
public:
	virtual void OnCollisionExit(GameObject * other) {}
};

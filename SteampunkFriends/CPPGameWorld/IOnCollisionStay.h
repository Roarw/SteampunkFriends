#pragma once

class GameObject;

class IOnCollisionStay
{
public:
	virtual void OnCollisionStay(GameObject * other) {}
};


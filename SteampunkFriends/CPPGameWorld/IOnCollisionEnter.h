#pragma once

class GameObject;

class IOnCollisionEnter
{
public:
	virtual void OnCollisionEnter(GameObject * other) {}
};
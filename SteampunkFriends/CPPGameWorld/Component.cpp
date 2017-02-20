#include "Component.h"
#include "GameObject.h"

GameObject Component::GetGameObject()
{
	return * gameObject;
}

Component::Component(GameObject * gameObject)
{
	this->gameObject = gameObject;
}

Component::~Component()
{
}

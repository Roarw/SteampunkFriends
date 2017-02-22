#include "Component.h"
#include "GameObject.h"

std::string Component::GetName()
{
	return "Component";
}

GameObject * Component::GetGameObject()
{
	return gameObject;
}

Component::Component(GameObject * gameObject)
{
	this->gameObject = gameObject;
}

Component::~Component()
{
}

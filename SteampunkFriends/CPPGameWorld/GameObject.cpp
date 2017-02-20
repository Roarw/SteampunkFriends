#include <iostream>
#include <string>

#include "GameObject.h"

void GameObject::Update()
{
	
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	((SpriteRenderer*)components["SpriteRenderer"])->Draw(drawHandler);
}

void GameObject::AddComponent(Component * component)
{
	components[component->GetName()] = component;
}

Component* GameObject::GetComponent(std::string aName)
{
	return components[aName];
}

GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
}

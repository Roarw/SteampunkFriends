#include <iostream>
#include <string>
#include <map>

#include "GameObject.h"
#include "IOnCollisionEnter.h"
#include "IOnCollisionExit.h"
#include "IOnCollisionStay.h"
#include "SpriteRenderer.h"

using namespace std;

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

void GameObject::OnCollisionEnter(GameObject * other)
{
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		IOnCollisionEnter* co = dynamic_cast<IOnCollisionEnter *>(it->second);

		if (co != NULL)
		{
			co->OnCollisionEnter(other);
		}
	}
}

void GameObject::OnCollisionStay(GameObject * other)
{
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		IOnCollisionStay* co = dynamic_cast<IOnCollisionStay *>(it->second);

		if (co != NULL)
		{
			co->OnCollisionStay(other);
		}
	}
}

void GameObject::OnCollisionEnd(GameObject * other)
{
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		IOnCollisionExit* co = dynamic_cast<IOnCollisionExit *>(it->second);

		if (co != NULL)
		{
			co->OnCollisionExit(other);
		}
	}
}

GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
	for (pair<string, Component *> c : components)
	{
		delete(c.second);
		GameWorld::Instance->DeleteObject(this);
	}
}

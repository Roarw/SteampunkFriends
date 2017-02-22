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
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		IUpdate* co = dynamic_cast<IUpdate *>(it->second);

		if (co != NULL)
		{
			co->Update();
		}
	}
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	((SpriteRenderer*)components["SpriteRenderer"])->Draw(drawHandler);
	((Collider*)components["Collider"])->Draw(drawHandler);
}

void GameObject::AddComponent(Component * component)
{
	components[component->GetName()] = component;
}

GameWorld * GameObject::GetGameWorld()
{
	return gameWorld;
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

GameObject::GameObject(GameWorld* aGameWorld)
{
	gameWorld = aGameWorld;
}

GameObject::~GameObject()
{
	for (std::map<std::string, Component*>::iterator itr = components.begin(); itr != components.end(); itr++)
	{
		delete itr->second;
	}

	//gameWorld->DeleteObject(this);
}

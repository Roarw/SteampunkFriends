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
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		IDraw* co = dynamic_cast<IDraw *>(it->second);

		if (co != NULL)
		{
			co->Draw(drawHandler);
		}
	}

	for (it = components.begin(); it != components.end(); it++)
	{
		Collider* co = dynamic_cast<Collider *>(it->second);

		if (co != NULL)
		{
			co->Draw(drawHandler);
		}
	}

	//((SpriteRenderer*)components["SpriteRenderer"])->Draw(drawHandler);
	//((Collider*)components["Collider"])->Draw(drawHandler);
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
	//if (components[aName] != 0)
	//	return components[aName];
	//else
	//	return 0;

	if (components.find(aName) == components.end()) {
		return 0;
	}
	else {
		return components[aName];
	}
}

void GameObject::OnCollisionEnter(GameObject * other)
{
	map<string, Component*>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		Component * c = it->second;

		IOnCollisionEnter* co = dynamic_cast<IOnCollisionEnter *>(c);

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
		Component * c = it->second;

		IOnCollisionStay* co = dynamic_cast<IOnCollisionStay *>(c);

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
		Component * c = it->second;

		IOnCollisionExit* co = dynamic_cast<IOnCollisionExit *>(c);

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

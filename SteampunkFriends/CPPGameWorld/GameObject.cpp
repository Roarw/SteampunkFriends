#include "GameObject.h"
#include "DrawHandler.h"

using namespace std;

#pragma region METHODS:
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
#pragma endregion

#pragma region GET/SET:
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
	if (components.find(aName) == components.end()) 
	{
		return 0;
	}
	else 
	{
		return components[aName];
	}
}
#pragma endregion

#pragma region CONSTRUCTORS:
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
}
#pragma endregion
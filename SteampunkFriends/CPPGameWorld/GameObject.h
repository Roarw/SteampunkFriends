#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <map>
#include <string>

#include "GL\glut.h"
#include "soil.h"

#include "IUpdate.h"
#include "IDraw.h"
#include "IOnCollisionEnter.h"
#include "IOnCollisionExit.h"
#include "IOnCollisionStay.h"

#include "GameWorld.h"

class Component;
class Collider;

class GameObject : public IUpdate, public IDraw
{
private:
	GameWorld* gameWorld;
	std::map<std::string, Component*> components;
public:
	void Update();
	void Draw(DrawHandler * drawHandler);
	void OnCollisionEnter(GameObject * other);
	void OnCollisionStay(GameObject * other);
	void OnCollisionEnd(GameObject * other);

	void AddComponent(Component * component);
	GameWorld * GetGameWorld();
	Component* GetComponent(std::string aName);

	GameObject(GameWorld* aGameWorld);
	~GameObject();
};
#endif // !GAMEOBJECT_H

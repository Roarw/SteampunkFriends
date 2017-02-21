#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <map>
#include <string>

#include "GL\glut.h"
#include "soil.h"
#include "IUpdate.h"
#include "IDraw.h"
#include "DrawHandler.h"
#include "Component.h"

class GameObject : public IUpdate, public IDraw
{
private:
	std::map<std::string, Component*> components;
public:
	void Update();
	void Draw(DrawHandler * drawHandler);
	void OnCollisionEnter(GameObject * other);
	void OnCollisionStay(GameObject * other);
	void OnCollisionEnd(GameObject * other);

	void AddComponent(Component * component);
	Component* GetComponent(std::string aName);

	GameObject();
	~GameObject();
};
#endif // !GAMEOBJECT_H

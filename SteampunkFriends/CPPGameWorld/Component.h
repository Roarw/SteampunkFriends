#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

class GameObject;

class Component 
{
protected:
	GameObject * gameObject;
public:
	virtual std::string GetName();
	GameObject * GetGameObject();

	Component(GameObject * gameObject);
	~Component();
};

#endif // COMPONENT_H


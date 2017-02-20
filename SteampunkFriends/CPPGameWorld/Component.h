#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component 
{
protected:
	GameObject * gameObject;
public:
	GameObject GetGameObject();

	Component(GameObject * gameObject);
	~Component();
};

#endif // COMPONENT_H


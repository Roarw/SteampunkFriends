#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <map>
#include <string>

#include "GL\glut.h"
#include "soil.h"
#include "IUpdate.h"
#include "IDraw.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "DrawHandler.h"

class GameObject : public IUpdate, public IDraw
{
private:
	std::map<std::string, Component*> components;
	Transform * transform;
	SpriteRenderer * spriter;
public:
	void Update();
	void Draw(DrawHandler * drawHandler);

	Component* GetComponent(std::string aName);
	Transform * GetTransform();
	SpriteRenderer * GetSpriteRenderer();

	GameObject();
	~GameObject();
};
#endif // !GAMEOBJECT_H

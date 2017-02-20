#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
	Transform * transform;
	SpriteRenderer * spriter;
public:
	void Update();
	void Draw(DrawHandler * drawHandler);

	Transform * GetTransform();
	SpriteRenderer * GetSpriteRenderer();

	GameObject();
	~GameObject();
};
#endif // !GAMEOBJECT_H

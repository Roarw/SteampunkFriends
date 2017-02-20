#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GL\glut.h"
#include "soil.h"
#include "IUpdate.h"
#include "IDraw.h"
#include "SpriteRenderer.h"
#include "DrawHandler.h"

class GameObject : public IUpdate, public IDraw
{
private:
	SpriteRenderer * spriter; //Texture holder
public:
	void Update();
	void Draw(DrawHandler * drawHandler);

	GameObject();
	~GameObject();
};
#endif // !GAMEOBJECT_H

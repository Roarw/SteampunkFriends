#pragma once

#include "GL\glut.h"
#include "soil.h"
#include "Component.h"
#include "IDraw.h"
#include "DrawHandler.h"
#include "Vector2.h"

class SpriteRenderer :
	public Component, public IDraw
{
private:
	GLuint texture; //Texture holder
public:
	Vector2 * Size;
	std::string GetName();
	void Draw(DrawHandler * drawHandler);

	SpriteRenderer(GameObject * gameObject, char * texturePath);
	~SpriteRenderer();
};


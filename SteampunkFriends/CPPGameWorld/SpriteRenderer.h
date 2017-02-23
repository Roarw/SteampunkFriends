#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "GL\glut.h"
#include "soil.h"
#include "Component.h"
#include "IDraw.h"
#include "DrawHandler.h"

class Transform;

class SpriteRenderer :
	public Component, public IDraw
{
private:
	GLuint texture; //Texture holder
	Transform * transform;
public:
	Vector2 Size;
	bool MirrorX = false;
	bool FlipX = false;
	bool FlipY = false;
	bool Enabled = true;

	void Draw(DrawHandler * drawHandler);

	std::string GetName();

	SpriteRenderer(GameObject * gameObject, Transform * transform, char * texturePath);
	~SpriteRenderer();
};
#endif // !SPRITERENDERER_H

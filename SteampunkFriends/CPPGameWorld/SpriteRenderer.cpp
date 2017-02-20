#include "SpriteRenderer.h"
#include "GameObject.h"


void SpriteRenderer::Draw(DrawHandler * drawHandler)
{
	drawHandler->DrawTexture(texture, 0, 0, 0);
}

SpriteRenderer::SpriteRenderer(GameObject * gameObject, char * texturePath) : Component(gameObject)
{
	texture = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Load texture through soil
	glBindTexture(GL_TEXTURE_2D, texture); //bind texture
}

SpriteRenderer::~SpriteRenderer()
{
}

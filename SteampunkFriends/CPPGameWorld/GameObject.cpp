#include "GameObject.h"
#include "DrawHandler.h"

void GameObject::Update()
{
	
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	drawHandler->DrawTexture(texture, 0, 0, 0);
}

GameObject::GameObject()
{
	texture = SOIL_load_OGL_texture(".\\PokeBall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Load texture through soil
	glBindTexture(GL_TEXTURE_2D, texture); //bind texture
}

GameObject::~GameObject()
{
}

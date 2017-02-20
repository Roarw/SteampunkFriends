#pragma once

#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2.h"

std::string SpriteRenderer::GetName()
{
	return "SpriteRenderer";
}

void SpriteRenderer::Draw(DrawHandler * drawHandler)
{
	Transform * transform = ((Transform*)gameObject->GetComponent("Transform"));

	drawHandler->DrawTexture(texture, 
		transform->GetPosition()->X,
		transform->GetPosition()->Y,
		0);
}

SpriteRenderer::SpriteRenderer(GameObject * gameObject, char * texturePath) : Component(gameObject)
{
	texture = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Load texture through soil
	glBindTexture(GL_TEXTURE_2D, texture); //bind texture
	int w, h;
	int miplevel = 0;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &w);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &h);
	Size = new Vector2(w, h);
}

SpriteRenderer::~SpriteRenderer()
{
}

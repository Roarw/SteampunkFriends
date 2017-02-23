#include "SpriteRenderer.h"
#include "GameObject.h"
#include "DrawHandler.h"
#include "Transform.h"

#pragma region METHODS:
void SpriteRenderer::Draw(DrawHandler * drawHandler)
{
	if (Enabled)
	{
		if (FlipX || FlipY || MirrorX || Angle != 0)
		{
			drawHandler->DrawTexture(texture,
				transform->GetPosition()->X + offset.X,
				transform->GetPosition()->Y + offset.Y,
				0.0f,
				Size.X,
				Size.Y,
				MirrorX,
				FlipX,
				FlipY,
				Angle
			);
		}
		else
		{
			drawHandler->DrawTexture(texture,
				transform->GetPosition()->X,
				transform->GetPosition()->Y,
				0.0f,
				Size.X,
				Size.Y
			);
		}
	}
}
#pragma endregion

#pragma GET/SET:
std::string SpriteRenderer::GetName()
{
	return "SpriteRenderer";
}
#pragma endregion

#pragma CONSTRUCTORS:
SpriteRenderer::SpriteRenderer(GameObject * gameObject, Transform * transform, char * texturePath) : Component(gameObject)
{
	this->transform = transform;
	//Load texture through soil
	texture = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); 

	int w, h;
	int miplevel = 0;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &w);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &h);
	Size = Vector2(w, h);
}

SpriteRenderer::~SpriteRenderer()
{
}
#pragma endregion

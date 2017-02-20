#include "GameObject.h"

void GameObject::Update()
{
	
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	spriter->Draw(drawHandler);
}

Transform * GameObject::GetTransform()
{
	return transform;
}

SpriteRenderer * GameObject::GetSpriteRenderer()
{
	return spriter;
}

GameObject::GameObject()
{
	transform = new Transform(this, new Vector2());
	spriter = new SpriteRenderer(this, ".\\PokeBall.png");
}

GameObject::~GameObject()
{
	delete spriter;
}

#include "GameObject.h"

void GameObject::Update()
{
	
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	spriter->Draw(drawHandler);
}

GameObject::GameObject()
{
	spriter = new SpriteRenderer(this, ".\\PokeBall.png");
}

GameObject::~GameObject()
{
	delete spriter;
}

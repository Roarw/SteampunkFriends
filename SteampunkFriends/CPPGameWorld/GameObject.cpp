#include <iostream>
#include <string>

#include "GameObject.h"

void GameObject::Update()
{
	
}

void GameObject::Draw(DrawHandler * drawHandler)
{
	((SpriteRenderer*)components["SpriteRenderer"])->Draw(drawHandler);
}

Component* GameObject::GetComponent(std::string aName)
{
	return components[aName];
}

Transform * GameObject::GetTransform()
{
	return (Transform*)components["Transform"];
}

SpriteRenderer * GameObject::GetSpriteRenderer()
{
	return (SpriteRenderer*)components["SpriteRenderer"];
}

GameObject::GameObject()
{
	//transform = new Transform(this, new Vector2());
	//spriter = new SpriteRenderer(this, ".\\PokeBall.png");

	components["Transform"] = new Transform(this, new Vector2());
	components["SpriteRenderer"] = new SpriteRenderer(this, ".\\PokeBall.png");

	std::cout << components["Transform"]->GetName() << " has been added.\n";
	std::cout << components["SpriteRenderer"]->GetName() << " has been added.\n";
}

GameObject::~GameObject()
{
	delete spriter;
}

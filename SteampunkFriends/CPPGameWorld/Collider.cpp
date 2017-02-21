#pragma once
#include "Collider.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include <vector>

using namespace std;

std::string Collider::GetName()
{
	return "Collider";
}

Collider::Collider(GameObject * gameObject, Transform * transform, SpriteRenderer * spriteRenderer) : Component(gameObject)
{
	this->spriter = spriteRenderer;
	this->transform = transform;
}

void Collider::CheckCollision()
{
	vector<Collider *> temp;	// Temporary untill game has a real list of colliders
	vector<Collider *> tempCollisions = this->collisions;
	vector<Collider *>::iterator it;

	// Loop through collisionboxes 
	for (it = (temp).begin(); it != (temp).end(); ++it)
	{
		// Add simple collisioncheck before this if needed for performance 
		if (this->CollisionBox()->Intersects((*it)->CollisionBox()))
		{
			// Check for other collider in collisions
			if (find((tempCollisions).begin(), (collisions).end(), *it) != (tempCollisions).end()) // Added *before it here, but not sure if thats bad 
			{
				// Collision Stay
				gameObject->OnCollisionStay((*it)->gameObject);
			}
			else
			{
				// Collision Enter
				gameObject->OnCollisionEnter((*it)->gameObject);
				this->collisions.push_back(*it);
			}
		}
	}

	for (it = (tempCollisions).begin(); it != (tempCollisions).end(); ++it)
	{
		if (!this->CollisionBox()->Intersects((*it)->CollisionBox()))
		{
			// Collision End
			gameObject->OnCollisionEnd((*it)->gameObject);
			this->collisions.erase(it);
		}
	}
}

void Collider::Update()
{
	CheckCollision();
}

void Collider::Draw()
{

}

RectangleF * Collider::CollisionBox()
{
	Vector2 position = *transform->GetPosition();
	Vector2 size = *spriter->Size;

	return & RectangleF(
		position.X,
		position.Y,
		size.X,	
		size.Y
	);
}

Collider::~Collider()
{
	spriter = nullptr;
	transform = nullptr;
	vector<Collider *>().swap(collisions);
}

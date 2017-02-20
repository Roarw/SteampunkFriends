#pragma once
#include "Collider.h"
#include "RectangleF.h"
#include "GameObject.h"
#include <vector>

using namespace std;

Collider::Collider(GameObject * g) : Component(g)
{
	s = (SpriteRenderer*)(gameObject->GetComponent("SpriteRenderer"));
	t = (Transform*)(gameObject->GetComponent("Transform"));
	collisions = new vector<Collider *>;
}

void Collider::CheckCollision()
{
	vector<Collider *> * temp = new vector<Collider *>;	// Temporary untill game has a real list of colliders
	vector<Collider *> * collisions = this->collisions;
	vector<Collider *>::iterator it;

	// Loop through collisionboxes 
	for (it = (*temp).begin(); it != (*temp).end(); ++it)
	{
		// Add simple collisioncheck before this if needed for performance 
		if (this->CollisionBox()->Intersects((*it)->CollisionBox()))
		{
			// Check for other collider in collisions
			if (find((*collisions).begin(), (*collisions).end(), *it) != (*collisions).end()) // Added *before it here, but not sure if thats bad 
			{
				// Collision Stay
				gameObject->OnCollisionStay((*it)->gameObject);
			}
			else
			{
				// Collision Enter
				gameObject->OnCollisionEnter((*it)->gameObject);
			}
		}
	}

	for (Collider * c : *collisions)
	{
		if (!this->CollisionBox()->Intersects(c->CollisionBox()))
		{
			// Collision End
			gameObject->OnCollisionEnd(c->gameObject);
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
	Vector2 * position = t->GetPosition();
	Vector2 * size = s->Size;

	return new RectangleF(
		position->X,
		position->Y,
		size->X,	
		size->Y
	);
}

Collider::~Collider()
{
}

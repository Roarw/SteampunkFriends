#pragma once
#include "Collider.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "RectangleF.h"
#include <vector>

using namespace std;

std::string Collider::GetName()
{
	return "Collider";
}

Collider::Collider(GameObject * gameObject, Transform * transform, RectangleF sizeRect) : Component(gameObject)
{
	this->Size = sizeRect.Size;
	this->transform = transform;
}

Collider::Collider(GameObject * gameObject, Transform * transform, SpriteRenderer * spriteRenderer) : Component(gameObject)
{
	this->spriter = spriteRenderer;
	this->Size = spriter->Size;
	this->transform = transform;
}

void Collider::CheckCollision()
{
	vector<Collider *> temp;	// Temporary untill game has a real list of colliders
	vector<Collider *>::iterator it;

	// Loop through collisionboxes 
	for (it = (temp).begin(); it != (temp).end(); ++it)
	{
		// Add simple collisioncheck before this if needed for performance 
		if (CollisionBox().Intersects((*it)->CollisionBox()))
		{
			// Check for other collider in collisions
			if (find((this->collisions).begin(), (this->collisions).end(), *it) != (this->collisions).end()) // Added *before it here, but not sure if thats bad 
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

	for (it = (this->collisions).begin(); it != (this->collisions).end(); ++it)
	{
		if (!CollisionBox().Intersects((*it)->CollisionBox()))
		{
			// Collision End
			gameObject->OnCollisionEnd((*it)->gameObject);
			this->collisions.erase(it);
		}
	}
}

void Collider::Update()
{
	if(Enabled)
	{
		CheckCollision();
	}
}

void Collider::Draw(DrawHandler* drawHandler)
{
	drawHandler->DrawBox(CollisionBox(), 1.0f, 0.0f, 0.0f);
}

RectangleF Collider::CollisionBox()
{
	Vector2 position = *transform->GetPosition();

	return RectangleF(
		position.X,
		position.Y,
		Size.X,	
		Size.Y
	);
}

Collider::~Collider()
{
}

#pragma once
void Collider::CheckCollision()
{

#pragma region VARIABLES:
	vector<Collider *> colliders = gameObject->GetGameWorld()->GetColliders();
	vector<Collider *>::iterator it;
#pragma endregion

#pragma region METHODS:
	// Loop through collisionboxes 
	for (Collider * c : colliders)
	{
		if(c != this && c != nullptr)
		{ 
			// Add simple collisioncheck before this if needed for performance 
			if(c->Enabled)
			{ 
				//Making sure players can't go through walls.
				if((PlayerCollision*)gameObject->GetComponent("PlayerCollision") != NULL)
				{
					((PlayerCollision*)gameObject->GetComponent("PlayerCollision"))->CheckCollision(c);
				}

				if (CollisionBox().Intersects(c->CollisionBox()))
				{
					// Check for other collider in collisions
					vector<Collider *>::iterator index = find(collisions.begin(), collisions.end(), c);

					if (index != collisions.end())
					{
						// Collision Stay
						gameObject->OnCollisionStay(c->GetGameObject());
					}
					else
					{
						// Collision Enter
						gameObject->OnCollisionEnter(c->GetGameObject());
						this->collisions.push_back(c);
					}
				}
			}
		}
	}

	stack<vector<Collider *>::iterator> toRemove;

	for (it = collisions.begin(); it != collisions.end(); ++it)
	{
		if (*it == nullptr || *it == NULL)
		{
			toRemove.push(it);
		}
		else if (!CollisionBox().Intersects((*it)->CollisionBox()))
		{
			// Collision End
			gameObject->OnCollisionEnd((*it)->GetGameObject());
			toRemove.push(it);
		}
	}

	while(!toRemove.empty())
	{
		collisions.erase(toRemove.top());
		toRemove.pop();
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
 	if(Enabled)
		drawHandler->DrawBox(CollisionBox(), 1.0f, 0.0f, 0.0f);
}
#pragma endregion

#pragma region GET/SET:
std::string Collider::GetName()
{
	return "Collider";
}

RectangleF Collider::CollisionBox()
{
	Vector2 position = *transform->GetPosition();

	float offsetX = Size.X < 0 ? Size.X : 0;
	float offsetY = Size.Y < 0 ? Size.Y : 0;

	return RectangleF(
		position.X + offsetX,
		position.Y + offsetY,
		abs(Size.X),	
		abs(Size.Y)
	);
}
#pragma endregion

#pragma region CONSTRUCTORS:
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

Collider::~Collider()
{
}
#pragma endregion

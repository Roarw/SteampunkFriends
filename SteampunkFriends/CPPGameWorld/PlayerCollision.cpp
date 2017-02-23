#pragma region METHODS:
bool PlayerCollision::CollidingAt(Collider * other, Vector2 velocity)
{
	return RectangleF(
		collider->CollisionBox().X + velocity.X,
		collider->CollisionBox().Y + velocity.Y,
		collider->CollisionBox().Width,
		collider->CollisionBox().Height)
		.Intersects(other->CollisionBox());
}

void PlayerCollision::CheckCollision(Collider * other)
{
	if ((Wall*)other->GetGameObject()->GetComponent("Wall") != NULL && 
		CollidingAt(other, physics->GetVelocity()))
	{
		//X collision:
		if (CollidingAt(other, Vector2(physics->GetVelocity().X, 0)))
		{
			int signX = MyMath::sign(physics->Velocity.X);
			while (!CollidingAt(other, Vector2(signX, 0)))
			{
				transform->Translate(Vector2(signX, 0));
			}
			physics->Velocity = Vector2(0, physics->Velocity.Y);
		}

		//Y collision:
		if (CollidingAt(other, Vector2(0, physics->GetVelocity().Y)))
		{
			int signY = MyMath::sign(physics->Velocity.Y);
			while (!CollidingAt(other, Vector2(0, signY)))
			{
				transform->Translate(Vector2(0, signY));
			}
			physics->Velocity = Vector2(physics->Velocity.X, 0);
		}
	}
}
#pragma endregion 

#pragma region GET/SET:
std::string PlayerCollision::GetName()
{
	return "PlayerCollision";
}
#pragma endregion 

#pragma region CONSTRUCTORS:
PlayerCollision::PlayerCollision(GameObject * gameObject, Transform * transform, Collider * collider, Physics * physics) : Component(gameObject)
{
	this->transform = transform;
	this->collider = collider;
	this->physics = physics;
}

PlayerCollision::~PlayerCollision()
{
}
#pragma endregion 
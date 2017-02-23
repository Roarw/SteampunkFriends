#pragma region METHODS:
void Enemy::PlayDead(Vector2 direction)
{
	((Collider*)gameObject->GetComponent("Collider"))->Enabled = false;
	dying = true;

	deathDirection = direction;

	gameObject->GetGameWorld()->PlaySound("Yee.wav", 0.25f);
}

void Enemy::Update()
{
	if (!dying) 
	{
		Vector2 moveDirection = *target - *transform->GetPosition();
		moveDirection.Normalize();

		moveDirection = moveDirection * speed * gameObject->GetGameWorld()->GetDeltaTime();

		transform->Translate(moveDirection);
	}
	else 
	{
		if (spriter->Size.X > 5 && spriter->Size.Y > 5) 
		{
			//Shrinking:
			float factorX = (spriter->Size.X / 4) * gameObject->GetGameWorld()->GetDeltaTime();
			float factorY = (spriter->Size.Y / 4) * gameObject->GetGameWorld()->GetDeltaTime();

			spriter->Size.X -= factorX;
			spriter->Size.Y -= factorY;

			transform->Translate(Vector2(factorX / 2, factorY / 2));

			//Falling:
			if (deathDirection.Y < 0)
				transform->Translate(Vector2(-30 * gameObject->GetGameWorld()->GetDeltaTime(), -60 * gameObject->GetGameWorld()->GetDeltaTime()));
			else if (deathDirection.X < 0) 
				transform->Translate(Vector2(-45 * gameObject->GetGameWorld()->GetDeltaTime(), -15 * gameObject->GetGameWorld()->GetDeltaTime()));
			else
				transform->Translate(Vector2(-30 * gameObject->GetGameWorld()->GetDeltaTime(), 5 * gameObject->GetGameWorld()->GetDeltaTime()));
		}
		else 
		{
			gameObject->GetGameWorld()->DeleteObjectNext(gameObject);
		}
	}
}
#pragma endregion

#pragma region GET/SET:
std::string Enemy::GetName()
{
	return "Enemy";
}
#pragma endregion

#pragma region CONSTRUCTORS:
Enemy::Enemy(GameObject * gameObject, Transform * transform, SpriteRenderer * spriter, Vector2 * target) : Component(gameObject)
{
	this->transform = transform;
	this->spriter = spriter;
	this->target = target;

	dying = false;
	speed = 55 + (rand() % 40);
}

Enemy::~Enemy()
{
	delete target;
}
#pragma endregion
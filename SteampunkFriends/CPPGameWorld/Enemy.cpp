#include "Enemy.h"
#include "SpriteRenderer.h"

#pragma region METHODS:
void Enemy::PlayDead()
{
	((Collider*)gameObject->GetComponent("Collider"))->Enabled = false;
	dying = true;
}

void Enemy::Update()
{
	if (!dying) 
	{
		Vector2 direction = *target - *transform->GetPosition();
		direction.Normalize();

		direction = direction * speed * gameObject->GetGameWorld()->GetDeltaTime();

		transform->Translate(direction);
	}
	else 
	{
		if (spriter->Size.X > 5 && spriter->Size.Y > 5) 
		{
			float factorX = (spriter->Size.X / 5) * gameObject->GetGameWorld()->GetDeltaTime();
			float factorY = (spriter->Size.Y / 5) * gameObject->GetGameWorld()->GetDeltaTime();

			spriter->Size.X -= factorX;
			spriter->Size.Y -= factorY;

			transform->Translate(Vector2(factorX / 2, factorY / 2));
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
	speed = 100;
}

Enemy::~Enemy()
{
	delete target;
}
#pragma endregion
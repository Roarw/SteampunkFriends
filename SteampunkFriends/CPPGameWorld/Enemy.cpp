#include "Enemy.h"

std::string Enemy::GetName()
{
	return "Enemy";
}

void Enemy::Update()
{
	Vector2 direction = *target - *transform->GetPosition();
	direction.Normalize();
	
	direction = direction * gameObject->GetGameWorld()->GetDeltaTime();

	transform->Translate(direction);
}

Enemy::Enemy(GameObject * gameObject, Transform * transform, Vector2 * target) : Component(gameObject)
{
	this->transform = transform;
	this->target = target;
}

Enemy::~Enemy()
{
	delete target;
}

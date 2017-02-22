#include "Enemy.h"

std::string Enemy::GetName()
{
	return "Enemy";
}

void Enemy::Update()
{
	Vector2 direction = *target - *transform->GetPosition();
	direction.Normalize();
	
	direction = direction * speed * gameObject->GetGameWorld()->GetDeltaTime();

	transform->Translate(direction);
}

Enemy::Enemy(GameObject * gameObject, Transform * transform, Vector2 * target) : Component(gameObject)
{
	this->transform = transform;
	this->target = target;

	speed = 100;
}

Enemy::~Enemy()
{
	delete target;
}

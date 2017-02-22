#include "Physics.h"

Physics::Physics(GameObject * g, Transform * transform) : Component(g)
{
	this->Velocity = Vector2();
	this->transform = transform;
}

void Physics::Update()
{
	transform->Translate(Velocity * gameObject->GetGameWorld()->GetDeltaTime());
	this->Velocity = Velocity * 0.9;
}


Physics::~Physics()
{
}

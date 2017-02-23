#include "Physics.h"

#pragma region METHODS:
void Physics::Update()
{
	transform->Translate(Velocity * gameObject->GetGameWorld()->GetDeltaTime());
	this->Velocity = Velocity * 0.9;
}
#pragma endregion

#pragma region GET/SET:
std::string Physics::GetName()
{
	return "Physics";
}
#pragma endregion

#pragma region CONSTRUCTORS:
Physics::Physics(GameObject * g, Transform * transform) : Component(g)
{
	this->Velocity = Vector2();
	this->transform = transform;
}

Physics::~Physics()
{
}
#pragma endregion
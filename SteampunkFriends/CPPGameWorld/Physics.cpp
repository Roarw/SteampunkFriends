#include "Physics.h"

Physics::Physics(GameObject * g, Transform * transform) : Component(g)
{
	this->Velocity = Vector2();
}

void Physics::Update()
{

}


Physics::~Physics()
{
}

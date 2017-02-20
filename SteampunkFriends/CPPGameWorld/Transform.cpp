#include "Transform.h"



void Transform::Translate(Vector2 translation)
{
	position->X += translation.X;
	position->Y += translation.Y;
}

Vector2 * Transform::GetPosition()
{
	return position;
}

Transform::Transform(GameObject * gameObject, Vector2 * position) : Component(gameObject)
{
	this->position = position;
}


Transform::~Transform()
{
	delete position;
}

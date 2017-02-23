#pragma region METHODS:
void Transform::Translate(Vector2 translation)
{
	position->X += translation.X;
	position->Y += translation.Y;
}
#pragma endregion

#pragma region GET/SET:
Vector2 * Transform::GetPosition()
{
	return position;
}

std::string Transform::GetName()
{
	return "Transform";
}
#pragma endregion

#pragma region CONSTRUCTORS:
Transform::Transform(GameObject * gameObject, Vector2 * position) : Component(gameObject)
{
	this->position = position;
}

Transform::~Transform()
{
	delete position;
}
#pragma endregion

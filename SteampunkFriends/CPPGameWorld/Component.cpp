#pragma region GET/SET:
std::string Component::GetName()
{
	return "Component";
}

GameObject * Component::GetGameObject()
{
	return gameObject;
}
#pragma endregion

#pragma region CONSTRUCTORS:
Component::Component(GameObject * gameObject)
{
	this->gameObject = gameObject;
}

Component::~Component()
{
}
#pragma endregion

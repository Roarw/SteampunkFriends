#pragma region METHODS:
void EnemyCollision::Update()
{
	Vector2 * thisPosition = ((Transform*)gameObject->GetComponent("Transform"))->GetPosition();
	Vector2 * rightWallPosition = ((Transform*)rightWall->GetComponent("Transform"))->GetPosition();

	Vector2 thisSize = ((SpriteRenderer*)gameObject->GetComponent("SpriteRenderer"))->Size;

	if (thisPosition->X + thisSize.X >=
		rightWallPosition->X - 1) 
	{
		thisPosition->X = rightWallPosition->X - thisSize.X - 2;
		((Physics*)gameObject->GetComponent("Physics"))->Velocity.X = 0;
	}
}
#pragma endregion

#pragma region GET/SET:
std::string EnemyCollision::GetName()
{
	return "EnemyCollision";
}
#pragma endregion

#pragma region CONSTRUCTORS:
EnemyCollision::EnemyCollision(GameObject * gameObject, GameObject * rightWall) : Component(gameObject)
{
	this->rightWall = rightWall;
}

EnemyCollision::~EnemyCollision()
{
}
#pragma endregion

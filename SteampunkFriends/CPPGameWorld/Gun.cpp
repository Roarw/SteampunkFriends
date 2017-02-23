#include "Gun.h"
#include "Transform.h"
#include "Physics.h"
#include "Enemy.h"

#pragma region METHODS:
void Gun::PositionCollider()
{
	Vector2 aoe = Vector2();

	float a = player->GetDirection()->X;
	float b = player->GetDirection()->Y;

	float nSizeX = a * AOE.Width;
	float nSizeY = b * AOE.Height;

	aoe = nSizeX != 0 ? Vector2(nSizeX, ((Collider *)player->GetGameObject()->GetComponent("Collider"))->Size.Y) :
		Vector2(((Collider *)player->GetGameObject()->GetComponent("Collider"))->Size.X, nSizeY);

	collider->Size = aoe;
}

void Gun::Shoot()
{
	PositionCollider();

	collider->Enabled = true;
}

void Gun::Update()
{
	collider->Enabled = false;

	for (int key : gameObject->GetGameWorld()->GetKeys())
	{
		if (key == 32)
		{
			Shoot();
		}
	}
}

void Gun::OnCollisionStay(GameObject * other)
{
	// Check if other is enemy (not implemented)
	if ((Enemy *)other->GetComponent("Enemy") != NULL)
	{
		// Disable enemy collider ( so it wont get hit more than once)
		//((Collider *)other->GetComponent("Collider"))->Enabled = false;	

		// Vector diving enemy and player
		Vector2 dividingVector = *((Transform *)other->GetComponent("Transform"))->GetPosition() - *((Transform *)gameObject->GetComponent("Transform"))->GetPosition();

		// Percentage of max range
		float factor = 1 - abs(dividingVector.Length() / AOE.Size.Length());

		Vector2 v = MaxVelocityTransfered * *(player->GetDirection()) * factor;

		((Physics *)other->GetComponent("Physics"))->Velocity += v;
	}
}
#pragma endregion

#pragma region GET/SET:
std::string Gun::GetName()
{
	return "Gun";
}
#pragma endregion

#pragma region CONSTRUCTORS:
Gun::Gun(GameObject * g, Player * player) : Component(g)
{
	this->player = player;

	collider = new Collider(this->gameObject, (Transform*)this->gameObject->GetComponent("Transform"), AOE);

	collider->Enabled = false;

	this->gameObject->AddComponent(collider);
}

Gun::~Gun()
{
}
#pragma endregion

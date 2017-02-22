#include "Gun.h"
#include "Transform.h"
#include "Physics.h"

std::string Gun::GetName()
{
	return "Gun";
}

void Gun::OnCollisionEnter(GameObject * other)
{
	// Check if other is enemy (not implemented)

	// Disable enemy collider ( so it wont get hit more than once)
	((Collider *)other->GetComponent("Collider"))->Enabled = false;	

	// Vector diving enemy and player
	Vector2 dividingVector = *((Transform *)other->GetComponent("Transform"))->GetPosition() - *((Transform *)gameObject->GetComponent("Transform"))->GetPosition();

	// Percentage of max range
	float factor = dividingVector.Length() / AOE.Size.Length();

	Vector2 v = MaxVelocityTransfered * factor;

	((Physics *)other->GetComponent("Physics"))->Velocity += v;
}

Gun::Gun(GameObject * g, Player * player) : Component(g)
{
	this->player = player;

	collider = new Collider(this->gameObject, (Transform*)this->gameObject->GetComponent("Transform"), AOE);

	collider->Enabled = false;

	this->gameObject->AddComponent(collider);
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

void Gun::PositionCollider()
{
	collider->Size = Vector2(player->GetDirection()->X * AOE.X, AOE.Y);
}

void Gun::Shoot()
{
	PositionCollider();

	collider->Enabled = true;
}


Gun::~Gun()
{
}

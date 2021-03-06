#include "Gun.h"
#include "GameObject.h"
#include "Transform.h"
#include "Collider.h"
#include "Player.h"
#include "SpriteRenderer.h"
#include "Enemy.h"
#include "Physics.h"

#pragma region METHODS:
void Gun::PositionCollider()
{
	// Sizing
	Vector2 * transform = ((Transform*)gameObject->GetComponent("Transform"))->GetPosition();
	Vector2 * playerTransform = ((Transform*)player->GetGameObject()->GetComponent("Transform"))->GetPosition();
	Vector2 playerSize = ((SpriteRenderer*)player->GetGameObject()->GetComponent("SpriteRenderer"))->Size;
	Vector2 aoe = Vector2();

	float a = player->GetDirection()->X;
	float b = player->GetDirection()->Y;

	float nSizeX = a * AOE.Width;
	float nSizeY = b * AOE.Height;

	spriter->MirrorX = false;
	spriter->FlipY = false;

	// Set collidersize based on player width/height and length of 'beam'
	aoe = nSizeX != 0 ? 
		Vector2(nSizeX, ((Collider *)player->GetGameObject()->GetComponent("Collider"))->Size.Y) :
		Vector2(((Collider *)player->GetGameObject()->GetComponent("Collider"))->Size.X, nSizeY);

	// Gun Positioning
	transform->X = playerTransform->X;
	transform->Y = playerTransform->Y;
	spriter->Angle = 0;
	spriter->offset = Vector2();

	if (aoe.X < 0)
	{
		transform->X = playerTransform->X;
		spriter->MirrorX = true;
	}
	else if(aoe.X > playerSize.X)
	{
		transform->X = playerTransform->X + playerSize.X;
	}

	if (aoe.Y < 0)
	{
		transform->Y = playerTransform->Y;
		spriter->Angle = -90;
	}
	else if(aoe.Y > playerSize.Y)
	{
		transform->Y = playerTransform->Y + playerSize.Y/2;
		spriter->offset = Vector2(playerSize.X, 0);
		spriter->Angle = 90;
	}

	collider->Size = aoe;
}

void Gun::Shoot()
{
	PositionCollider();

	spriter->Enabled = true;

	collider->Enabled = true;

	if (*getTheMessageThrough > 10.0f) 
	{
		gameObject->GetGameWorld()->PlaySound("onlyyou.mp3", 0.25f);
		*getTheMessageThrough -= 10.0f;
	}
	else 
	{
		*getTheMessageThrough += 1.0f * gameObject->GetGameWorld()->GetDeltaTime();
	}
}

void Gun::Update()
{
	spriter->Enabled = false;
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

		Vector2 otherPosition = *((Transform *)other->GetComponent("Transform"))->GetPosition() + ((SpriteRenderer *)other->GetComponent("SpriteRenderer"))->Size / 2;
		Vector2 playerPosition = *((Transform *)player->GetGameObject()->GetComponent("Transform"))->GetPosition() + ((SpriteRenderer *)player->GetGameObject()->GetComponent("SpriteRenderer"))->Size / 2;

		// Vector diving enemy and player
		Vector2 dividingVector = otherPosition - playerPosition;

		// Percentage of max range
		float factor = 1 - abs(dividingVector.Length() / AOE.Size.Length());

		Vector2 v1 = dividingVector.Normalize();

		Vector2 v = v1 * MaxVelocityTransfered * factor;

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
Gun::Gun(GameObject * g, Player * player, SpriteRenderer * spriter) : Component(g)
{
	this->player = player;
	this->spriter = spriter;

	MaxVelocityTransfered = 30.0f;

	collider = new Collider(this->gameObject, (Transform*)this->gameObject->GetComponent("Transform"), AOE);

	collider->Enabled = false;

	this->gameObject->AddComponent(collider);

	getTheMessageThrough = new float(0);
}

Gun::~Gun()
{
	delete getTheMessageThrough;
}
#pragma endregion

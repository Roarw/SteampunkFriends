#pragma once
#include "Component.h"
#include "Collider.h"
#include "IUpdate.h"
#include "GameObject.h"
#include "Player.h"
#include "IOnCollisionStay.h"

class SpriteRenderer;

class Gun :
	public Component, public IUpdate, public IOnCollisionStay
{
private:
	int Cooldown;
	float MaxVelocityTransfered;
	RectangleF AOE = RectangleF(0, 0, 400, 400);
	Collider * collider;
	Player * player;
	SpriteRenderer * spriter;
	float * getTheMessageThrough;

	void PositionCollider();
public:
	void Shoot();
	void Update();
	void OnCollisionStay(GameObject * other);

	std::string GetName();

	Gun(GameObject * g, Player * player, SpriteRenderer * spriter);
	~Gun();
};


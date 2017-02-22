#pragma once
#include "Component.h"
#include "Collider.h"
#include "IUpdate.h"
#include "GameObject.h"
#include "Player.h"
#include "IOnCollisionStay.h"

class Gun :
	public Component, public IUpdate, public IOnCollisionStay
{
private:
	int Cooldown;
	Vector2 MaxVelocityTransfered = Vector2(200, 200);
	void PositionCollider();
	RectangleF AOE = RectangleF(0, 0, 400, 400);
	Collider * collider;
	Player * player;
public:
	std::string GetName();
	void OnCollisionStay(GameObject * other);
	Gun(GameObject * g, Player * player);
	void Update();
	void Shoot();
	~Gun();
};


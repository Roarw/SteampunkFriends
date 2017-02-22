#pragma once
#include "Component.h"
#include "Collider.h"
#include "IUpdate.h"
#include "GameObject.h"
#include "Player.h"
#include "IOnCollisionEnter.h"

class Gun :
	public Component, public IUpdate, public IOnCollisionEnter
{
private:
	int Cooldown;
	Vector2 MaxVelocityTransfered = Vector2(2000, 2000);
	void PositionCollider();
	RectangleF AOE = RectangleF(0, 0, 400, 100);
	Collider * collider;
	Player * player;
public:
	std::string GetName();
	void OnCollisionEnter(GameObject * other);
	Gun(GameObject * g, Player * player);
	void Update();
	void Shoot();
	~Gun();
};


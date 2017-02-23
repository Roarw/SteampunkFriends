#ifndef GUN_H
#define GUN_H

#include "Component.h"

#include "IUpdate.h"
#include "IOnCollisionStay.h"
#include "Vector2.h"
#include "RectangleF.h"

class Collider;
class Player;
class SpriteRenderer;

class Gun :
	public Component, public IUpdate, public IOnCollisionStay
{
private:
	int Cooldown;
	float MaxVelocityTransfered;
	RectangleF AOE = RectangleF(0, 0, 170, 170);
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
#endif // !GUN_H

#ifndef PLAYER_H
#define PLAYER_H

#include "Component.h"

#include "IUpdate.h"
#include "Vector2.h"

class Transform;
class Physics;

class Player :
	public Component, public IUpdate
{
private:
	Vector2 * direction;
	Transform * transform;
	Physics * physics;
	float speed;
	bool facingLeft = true;
public:
	void Update();
	void MirrorX(bool mirror);

	std::string GetName();
	Vector2 * GetDirection();

	Player(GameObject * gameObject, Transform * transform, Physics * physics);
	~Player();
};
#endif // !PLAYER_H

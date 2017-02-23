#ifndef ENEMY_H
#define ENEMY_H

#include "Component.h"

#include "IUpdate.h"
#include "Vector2.h"

class Transform;
class SpriteRenderer;

class Enemy :
	public Component, public IUpdate
{
private:
	Transform * transform;
	SpriteRenderer * spriter;
	Vector2 * target;
	Vector2 deathDirection;
	bool dying;
	float speed;
public:
	void PlayDead(Vector2 direction);
	void Update();

	std::string GetName();

	Enemy(GameObject * gameObject, Transform * transform, SpriteRenderer * spriter, Vector2 * target);
	~Enemy();
};
#endif // !ENEMY_H


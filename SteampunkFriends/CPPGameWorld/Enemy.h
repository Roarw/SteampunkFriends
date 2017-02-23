#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Component.h"
#include "IUpdate.h"
#include "Vector2.h"
#include "Transform.h"

class Enemy :
	public Component, public IUpdate
{
private:
	Transform * transform;
	SpriteRenderer * spriter;
	Vector2 * target;
	bool dying;
	float speed;
public:
	void PlayDead();
	void Update();

	std::string GetName();

	Enemy(GameObject * gameObject, Transform * transform, SpriteRenderer * spriter, Vector2 * target);
	~Enemy();
};
#endif // !ENEMY_H


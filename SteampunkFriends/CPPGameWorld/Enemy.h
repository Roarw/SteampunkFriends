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
	Vector2 * target;
	float speed;
public:
	std::string GetName();
	void Update();

	Enemy(GameObject * gameObject, Transform * transform, Vector2 * target);
	~Enemy();
};
#endif // !ENEMY_H


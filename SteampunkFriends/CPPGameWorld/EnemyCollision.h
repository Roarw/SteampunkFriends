#ifndef ENEMYCOLLISION_H
#define ENEMYCOLLISION_H

#include "Component.h"

#include "IUpdate.h"
#include "Vector2.h"

class EnemyCollision :
	public Component, public IUpdate
{
private:
	GameObject * rightWall;
public:
	void Update();

	std::string GetName();

	EnemyCollision(GameObject * gameObject, GameObject * rightWall);
	~EnemyCollision();
};
#endif // !ENEMYCOLLISION_H


#ifndef SPAWNER_H
#define SPAWNER_H

//#include "GameObject.h"
//#include "EnemyBuilder.h"

class GameWorld;
class EnemyBuilder;

class Spawner
{
private:
	GameWorld * gameWorld;
	float timer;
	void Spawn();
public:
	Spawner(GameWorld * aGameWorld);
	~Spawner();
	void Update();
};

#endif
#include "Spawner.h"
#include "GameWorld.h"
#include "EnemyBuilder.h"

void Spawner::Spawn()
{
	EnemyBuilder enemyBuilder;
	gameWorld->AddGameObjectNext(enemyBuilder.Build(gameWorld, gameWorld->GetRightAirShipCol(), new Vector2(900, 250), new Vector2(200 + std::rand() % 600, 200 + std::rand() % 200)));
}

Spawner::Spawner(GameWorld * aGameWorld)
{
	gameWorld = aGameWorld;
}

Spawner::~Spawner()
{
}

void Spawner::Update()
{
	float timeElapsed = gameWorld->GetDeltaTime();

	if (timer > 0)
	{
		timer -= timeElapsed;
	}
	else
	{
		if (gameWorld->GetGameObjects().size() < 20)
		{
			Spawn();
			timer = 2;
		}
	}
}

#include "GameWorld.h"
#include "DrawHandler.h"
#include <iostream>
#include <vector> 
#include "GameObject.h"
#include "Vector2.h"
#include <irrKlang.h>
#include <algorithm>

using namespace irrklang;

#include "AirShipBuilder.h"
#include "AirShipColBuilder.h"
#include "PlayerBuilder.h"
#include "EnemyBuilder.h"
#include "GunBuilder.h"

//Temp:
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Player.h"
#include "Gun.h"
#include "Wall.h"
#include "Enemy.h"

void GameWorld::Update()
{
	//Calculate delta time.
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float gammaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	deltaTime = gammaTime / 1000;

	//Updates:
	for (int i = 0; i < colliders.size(); i++) 
	{
		colliders[i]->Update();
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}

	//Deleting objects:
	for (int i = 0; i < objectsToDelete.size(); i++)
	{
		DeleteObject(objectsToDelete[i]);
	}
	objectsToDelete.clear();
}

void GameWorld::Draw()
{
	//Starting draw.
	drawHandler->BeginDraw();

	for (GameObject *go : gameObjects)
	{
		go->Draw(drawHandler);
	}

	//Ending draw.
	drawHandler->EndDraw();
}

///Creating all objects.
void GameWorld::CreateWorld()
{
	//Airship
	AirShipBuilder airShipBuilder;

	Vector2 * airShipPos = new Vector2(100, -50);
	GameObject * airShip = airShipBuilder.Build(this, airShipPos);
	AddGameObjectNext(airShip);

	//Airship Colliders
	AirShipColBuilder airShipColBuilder;

	GameObject * airShipCol;
	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X, airShipPos->Y + 200), new Vector2(50, 350));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 50, airShipPos->Y + 550), new Vector2(800, 50));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 850, airShipPos->Y + 200), new Vector2(50, 350));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 50, airShipPos->Y + 150), new Vector2(800, 50));
	AddGameObjectNext(airShipCol);

	//Player
	PlayerBuilder playerBuilder;
	GameObject * player = playerBuilder.Build(this, new Vector2());
	AddGameObjectNext(player);

	//Gun
	GunBuilder gunbuilder;
	GameObject * gun = gunbuilder.Build(this, (Player *)(player->GetComponent("Player")));
	AddGameObjectNext(gun);

	//Enemies
	EnemyBuilder enemyBuilder;
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(250, 200), new Vector2(0, 0)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(300, 200), new Vector2(0, 0)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(400, 200), new Vector2(0, 0)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(600, 200), new Vector2(0, 0)));
}

void GameWorld::DeleteObjectNext(GameObject* aObject)
{
	objectsToDelete.push_back(aObject);
}

void GameWorld::DeleteObject(GameObject* aObject)
{
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), aObject), gameObjects.end());

	if ((Collider*)aObject->GetComponent("Collider") != NULL)
	{
		Collider * aCollider = (Collider*)aObject->GetComponent("Collider");

		DeleteCollider(aCollider);
	}

	delete aObject;
}

void GameWorld::DeleteCollider(Collider * c)
{
	for (Collider * co : colliders)
	{
		co->collisions.erase(std::remove(co->collisions.begin(), co->collisions.end(), c), co->collisions.end());
	}

	colliders.erase(std::remove(colliders.begin(), colliders.end(), c), colliders.end());
}

//Doesn't work as intended yet. Make it like Delete.
void GameWorld::AddGameObjectNext(GameObject * gameObject)
{
	gameObjects.push_back(gameObject);

	if ((Collider*)gameObject->GetComponent("Collider") != NULL) 
	{
		colliders.push_back((Collider*)gameObject->GetComponent("Collider"));
	}
}

DrawHandler GameWorld::GetDrawHandler()
{
	return *drawHandler;
}

float GameWorld::GetDeltaTime()
{
	return deltaTime;
}

set<int> GameWorld::GetKeys()
{
	return keys;
}

void GameWorld::AddKey(int i)
{
	keys.insert(i);
}

void GameWorld::DeleteKey(int i)
{
	keys.erase(i);
}

vector<Collider*> GameWorld::GetColliders()
{
	return colliders;
}

GameWorld::GameWorld(int argc, char** argv)
{
	oldTimeSinceStart = 0;

	drawHandler = new DrawHandler(this, argc, argv);

	ISoundEngine * engine = createIrrKlangDevice(); //Creates engine
    //engine->play2D("death.mp3"); //Play sound

	CreateWorld();
	drawHandler->StartLoop();
}

GameWorld::~GameWorld()
{
	delete drawHandler;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

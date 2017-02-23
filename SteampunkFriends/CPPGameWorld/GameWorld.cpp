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
	//#pragma region HELLO IM AN AIRSHUP, DANK DANK

	//GameObject * airShip = new GameObject(this);

	//Transform * airShipTransform = new Transform(airShip, new Vector2(256, 128));
	//SpriteRenderer * airShipSpriteRenderer = new SpriteRenderer(airShip, airShipTransform, ".\\Pokeball.png");

	//airShip->AddComponent(airShipTransform);
	//airShip->AddComponent(airShipSpriteRenderer);
	//AddGameObjectNext(airShip);

	//Transform * airShipColTransform;
	//Collider * airShipColCollider;
	//Wall * airShipColWall;

	//GameObject * airShipColLeft = new GameObject(this);
	//airShipColTransform = new Transform(airShipColLeft, new Vector2(256-32, 128));
	//airShipColCollider =
	//	new Collider
	//	(
	//		airShipColLeft,
	//		airShipColTransform,
	//		RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 32, 256)
	//	);
	//airShipColWall = new Wall(airShipColLeft);

	//airShipColLeft->AddComponent(airShipColTransform);
	//airShipColLeft->AddComponent(airShipColCollider);
	//airShipColLeft->AddComponent(airShipColWall);
	//AddGameObjectNext(airShipColLeft);

	//GameObject * airShipColTop = new GameObject(this);
	//airShipColTransform = new Transform(airShipColTop, new Vector2(256, 128+256+80));
	//airShipColCollider =
	//	new Collider
	//	(
	//		airShipColTop,
	//		airShipColTransform,
	//		RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 728, 32)
	//	);
	//airShipColTop->AddComponent(airShipColTransform);
	//airShipColTop->AddComponent(airShipColCollider);
	//AddGameObjectNext(airShipColTop);

	//GameObject * airShipColRight = new GameObject(this);
	//airShipColTransform = new Transform(airShipColRight, new Vector2(256+728, 128));
	//airShipColCollider =
	//	new Collider
	//	(
	//		airShipColRight,
	//		airShipColTransform,
	//		RectangleF(airShipColTransform->GetPosition()->X + 728, airShipColTransform->GetPosition()->Y, 32, 256)
	//	);
	//airShipColRight->AddComponent(airShipColTransform);
	//airShipColRight->AddComponent(airShipColCollider);
	//AddGameObjectNext(airShipColRight);

	//GameObject * airShipColBottom = new GameObject(this);
	//airShipColTransform = new Transform(airShipColBottom, new Vector2(256, 128-32));
	//airShipColCollider =
	//	new Collider
	//	(
	//		airShipColBottom,
	//		airShipColTransform,
	//		RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 728, 32)
	//	);
	//airShipColBottom->AddComponent(airShipColTransform);
	//airShipColBottom->AddComponent(airShipColCollider);
	//AddGameObjectNext(airShipColBottom);

	//#pragma endregion

	//Airship
	AirShipBuilder airShipBuilder;

	Vector2 * airShipPos = new Vector2(256, 128);
	GameObject * airShip = airShipBuilder.Build(this, airShipPos);
	AddGameObjectNext(airShip);

	//Airship Colliders
	AirShipColBuilder airShipColBuilder;

	GameObject * airShipCol;
	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X - 32, airShipPos->Y), new Vector2(32, 256));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X, airShipPos->Y + 256 + 80), new Vector2(728, 32));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 728, airShipPos->Y), new Vector2(32, 256));
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X, airShipPos->Y - 32), new Vector2(728, 32));
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
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(100, 100), new Vector2(0, 0)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(200, 200), new Vector2(0, 0)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(400, 300), new Vector2(100, 100)));
	AddGameObjectNext(enemyBuilder.Build(this, new Vector2(600, 300), new Vector2(100, 100)));
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

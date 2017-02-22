#include "GameWorld.h"
#include "DrawHandler.h"
#include <iostream>
#include <vector> 
#include "GameObject.h"
#include "Vector2.h"

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

	for (GameObject *go : gameObjects)
	{
		go->Update();
	}
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
	#pragma region HELLO IM AN AIRSHUP, DANK DANK

	GameObject * airShip = new GameObject(this);

	Transform * airShipTransform = new Transform(airShip, new Vector2(256, 128));
	SpriteRenderer * airShipSpriteRenderer = new SpriteRenderer(airShip, airShipTransform, ".\\Pokeball.png");

	airShip->AddComponent(airShipTransform);
	airShip->AddComponent(airShipSpriteRenderer);
	AddGameObject(airShip);

	Transform * airShipColTransform;
	Collider * airShipColCollider;
	Wall * airShipColWall;

	GameObject * airShipColLeft = new GameObject(this);
	airShipColTransform = new Transform(airShipColLeft, new Vector2(256-32, 128));
	airShipColCollider =
		new Collider
		(
			airShipColLeft,
			airShipColTransform,
			RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 32, 256)
		);
	airShipColWall = new Wall(airShipColLeft);

	airShipColLeft->AddComponent(airShipColTransform);
	airShipColLeft->AddComponent(airShipColCollider);
	airShipColLeft->AddComponent(airShipColWall);
	AddGameObject(airShipColLeft);

	GameObject * airShipColTop = new GameObject(this);
	airShipColTransform = new Transform(airShipColTop, new Vector2(256, 128+256+80));
	airShipColCollider =
		new Collider
		(
			airShipColTop,
			airShipColTransform,
			RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 728, 32)
		);
	airShipColTop->AddComponent(airShipColTransform);
	airShipColTop->AddComponent(airShipColCollider);
	AddGameObject(airShipColTop);

	GameObject * airShipColRight = new GameObject(this);
	airShipColTransform = new Transform(airShipColRight, new Vector2(256+728, 128));
	airShipColCollider =
		new Collider
		(
			airShipColRight,
			airShipColTransform,
			RectangleF(airShipColTransform->GetPosition()->X + 728, airShipColTransform->GetPosition()->Y, 32, 256)
		);
	airShipColRight->AddComponent(airShipColTransform);
	airShipColRight->AddComponent(airShipColCollider);
	AddGameObject(airShipColRight);

	GameObject * airShipColBottom = new GameObject(this);
	airShipColTransform = new Transform(airShipColBottom, new Vector2(256, 128-32));
	airShipColCollider =
		new Collider
		(
			airShipColBottom,
			airShipColTransform,
			RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 728, 32)
		);
	airShipColBottom->AddComponent(airShipColTransform);
	airShipColBottom->AddComponent(airShipColCollider);
	AddGameObject(airShipColBottom);

	#pragma endregion

	//Player
	PlayerBuilder playerBuilder;
	GameObject * player = playerBuilder.Build(this, new Vector2());
	AddGameObject(player);

	//Gun
	GunBuilder gunbuilder;
	GameObject * gun = gunbuilder.Build(this, (Player *)(player->GetComponent("Player")));
	AddGameObject(gun);

	//Enemies
	EnemyBuilder enemyBuilder;
	AddGameObject(enemyBuilder.Build(this, new Vector2(100, 100), new Vector2(0, 0)));
	AddGameObject(enemyBuilder.Build(this, new Vector2(200, 200), new Vector2(0, 0)));
	AddGameObject(enemyBuilder.Build(this, new Vector2(400, 300), new Vector2(0, 0)));
	AddGameObject(enemyBuilder.Build(this, new Vector2(600, 300), new Vector2(0, 0)));
}

void GameWorld::DeleteObject(GameObject* aObject)
{
	//GameObject* tmp = *(find(gameObjects.begin(), gameObjects.end(), aObject));

	auto it = find(gameObjects.begin(), gameObjects.end(), aObject);
	if (it != gameObjects.end())
	{
		//gameObjects.erase(it);

		std::swap(*it, gameObjects.back());
		gameObjects.pop_back();

		delete aObject;
	}

	//std::vector<GameObject*>::iterator itr = 
	//gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), aObject), gameObjects.end());
}

void GameWorld::AddGameObject(GameObject * gameObject)
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

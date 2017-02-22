#include "GameWorld.h"
#include "DrawHandler.h"
#include <iostream>
#include <vector> 
#include "GameObject.h"
#include "Vector2.h"

#include "PlayerBuilder.h"
#include "EnemyBuilder.h"

//Temp:
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Collider.h"
#include "Player.h"

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
	Collider * airShipCollider = 
		new Collider
		(
		airShip,
		airShipTransform,
		RectangleF(airShipTransform->GetPosition()->X, airShipTransform->GetPosition()->Y, 768, 256)
		);

	airShip->AddComponent(airShipTransform);
	airShip->AddComponent(airShipSpriteRenderer);
	airShip->AddComponent(airShipCollider);
	gameObjects.push_back(airShip);

	#pragma endregion

	PlayerBuilder playerBuilder;
	gameObjects.push_back(playerBuilder.Build(this, new Vector2()));

	EnemyBuilder enemyBuilder;
	gameObjects.push_back(enemyBuilder.Build(this, new Vector2(100, 100)));
	gameObjects.push_back(enemyBuilder.Build(this, new Vector2(200, 200)));
	gameObjects.push_back(enemyBuilder.Build(this, new Vector2(400, 300)));
	gameObjects.push_back(enemyBuilder.Build(this, new Vector2(600, 300)));
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

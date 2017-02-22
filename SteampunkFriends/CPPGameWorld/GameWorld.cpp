#include "GameWorld.h"
#include "DrawHandler.h"
#include <iostream>
#include <vector> 
#include "GameObject.h"
#include "Vector2.h"

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

	airShip->AddComponent(airShipTransform);
	airShip->AddComponent(airShipSpriteRenderer);
	gameObjects.push_back(airShip);

	Transform * airShipColTransform;
	Collider * airShipColCollider;

	GameObject * airShipColLeft = new GameObject(this);
	airShipColTransform = new Transform(airShipColLeft, new Vector2(256-32, 128));
	airShipColCollider =
		new Collider
		(
			airShipColLeft,
			airShipColTransform,
			RectangleF(airShipColTransform->GetPosition()->X, airShipColTransform->GetPosition()->Y, 32, 256)
		);
	airShipColLeft->AddComponent(airShipColTransform);
	airShipColLeft->AddComponent(airShipColCollider);
	gameObjects.push_back(airShipColLeft);

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
	gameObjects.push_back(airShipColTop);

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
	gameObjects.push_back(airShipColRight);

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
	gameObjects.push_back(airShipColBottom);

	#pragma endregion

	GameObject * go = new GameObject(this);
	Transform * transform = new Transform(go, new Vector2());
	SpriteRenderer * spriteRenderer = new SpriteRenderer(go, transform, ".\\Player.png");
	Collider * collider = new Collider(go, transform, spriteRenderer);
	Player * player = new Player(go, this, transform);
	go->AddComponent(transform);
	go->AddComponent(spriteRenderer);
	go->AddComponent(collider);
	go->AddComponent(player);
	gameObjects.push_back(go);

	std::cout << go->GetComponent("Transform")->GetName() << " has been added.\n";
	std::cout << go->GetComponent("SpriteRenderer")->GetName() << " has been added.\n";

	//delete go;
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

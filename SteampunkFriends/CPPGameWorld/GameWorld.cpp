#include "GameWorld.h"
#include "DrawHandler.h"
#include "GameObject.h"
#include "Collider.h"

#include "AirShipBuilder.h"
#include "AirShipColBuilder.h"
#include "PlayerBuilder.h"
#include "EnemyBuilder.h"
#include "GunBuilder.h"

#include "SpriteRenderer.h"
#include "Transform.h"
#include "Player.h"

//Method for sorting GameObjects:
bool sortByY(GameObject * go, GameObject * other) 
{ 
	int goY = ((Transform*)go->GetComponent("Transform"))->GetPosition()->Y;
	int otherY = ((Transform*)other->GetComponent("Transform"))->GetPosition()->Y;
	return goY > otherY;	
}

#pragma region METHODS:
void GameWorld::PlaySound(char* soundPath, float volume)
{
	sfxEngine->setSoundVolume(volume);
	sfxEngine->play2D(soundPath, false);
}

void GameWorld::PlayMusic(char* musicPath, float volume)
{
	musicEngine->setSoundVolume(volume);
	musicEngine->play2D(musicPath, true);
}

void GameWorld::Update()
{
	//Calculate delta time.
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float gammaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	deltaTime = gammaTime / 1000;

	spawner->Update();

	//Updates:
	for (int i = 0; i < colliders.size(); i++) 
	{
		colliders[i]->Update();
	}

	sort(gameObjects.begin(), gameObjects.end(), sortByY);
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

	sky->Draw(drawHandler);
	airship->Draw(drawHandler);

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
	//Sky
	sky = new GameObject(this);
	Transform * skyTransform = new Transform(sky, new Vector2(0, 0));
	SpriteRenderer * skySpriteRenderer = new SpriteRenderer(sky, skyTransform, ".\\sky.png");
	sky->AddComponent(skyTransform);
	sky->AddComponent(skySpriteRenderer);

	//Airship
	AirShipBuilder airShipBuilder;
	Vector2 * airShipPos = new Vector2(100, -50);
	airship = airShipBuilder.Build(this, airShipPos);

	//Airship Colliders
	AirShipColBuilder airShipColBuilder;

	GameObject * airShipCol;
	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X - 25, airShipPos->Y + 225), new Vector2(50, 300), LEFT_WALL);
	AddGameObjectNext(airShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 25, airShipPos->Y + 545), new Vector2(825, 50), TOP_WALL);
	AddGameObjectNext(airShipCol);

	/*GameObject * */rightAirShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 850, airShipPos->Y + 225), new Vector2(50, 300), RIGHT_WALL);
	AddGameObjectNext(rightAirShipCol);

	airShipCol = airShipColBuilder.Build(this, new Vector2(airShipPos->X + 25, airShipPos->Y + 175), new Vector2(825, 50), BOTTOM_WALL);
	AddGameObjectNext(airShipCol);

	//Player
	PlayerBuilder playerBuilder;
	GameObject * player = playerBuilder.Build(this, new Vector2(300, 200));
	AddGameObjectNext(player);

	//Gun
	GunBuilder gunbuilder;
	GameObject * gun = gunbuilder.Build(this, (Player *)(player->GetComponent("Player")));
	AddGameObjectNext(gun);

	//Spawner
	spawner = new Spawner(this);
}
#pragma endregion

#pragma region GET/SET:
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

void GameWorld::DeleteObjectNext(GameObject* aObject)
{
	objectsToDelete.push_back(aObject);
}

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

GameObject * GameWorld::GetRightAirShipCol()
{
	return rightAirShipCol;
}

vector<GameObject*> GameWorld::GetGameObjects()
{
	return gameObjects;
}
#pragma endregion

#pragma region CONSTRUCTORS:
GameWorld::GameWorld(int argc, char** argv)
{
	oldTimeSinceStart = 0;

	drawHandler = new DrawHandler(this, argc, argv);

	sfxEngine = createIrrKlangDevice(); //Creates engine
	musicEngine = createIrrKlangDevice();

	CreateWorld();
	PlayMusic("yeemee.mp3", 0.15f);
	PlayMusic("fuckme.mp3", 0.15f);
	
	drawHandler->StartLoop();
}

GameWorld::~GameWorld()
{
	delete drawHandler;

	delete sky;
	delete airship;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}
#pragma endregion

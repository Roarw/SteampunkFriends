#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GL\glut.h"
#include "soil.h"

#include <iostream>
#include <vector> 
#include <set>
#include <irrKlang.h>
#include <algorithm>

#include "Vector2.h"
#include "Spawner.h"

class DrawHandler;
class GameObject;
class Collider;

using namespace std;
using namespace irrklang;

class GameWorld
{
private:
	DrawHandler * drawHandler;
	Spawner * spawner;
	GameObject * rightAirShipCol;
	vector<GameObject*> gameObjects;
	vector<Collider *> colliders;
	vector<GameObject*> objectsToDelete;
	int oldTimeSinceStart;
	float deltaTime;
	set<int> keys;
	ISoundEngine * sfxEngine;
	ISoundEngine * musicEngine;
	GameObject * sky;
	GameObject * airship;

	void DeleteObject(GameObject* aObject);
	void DeleteCollider(Collider* aCollider);
public:
	void PlaySound(char* soundPath, float volume);
	void PlayMusic(char* musicPath, float volume);
	void Update();
	void Draw();
	void CreateWorld();

	void DeleteObjectNext(GameObject* aObject);
	void AddGameObjectNext(GameObject * gameObject);
	DrawHandler GetDrawHandler();
	float GetDeltaTime();
	set<int> GetKeys();
	void AddKey(int i);
	void DeleteKey(int i);
	vector<Collider*> GetColliders();
	GameObject * GetRightAirShipCol();
	vector<GameObject*> GetGameObjects();

	GameWorld(int argc, char** argv);
	~GameWorld();
};
#endif // !GAMEWORLD_H

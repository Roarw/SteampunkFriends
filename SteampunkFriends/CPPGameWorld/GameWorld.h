#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GL\glut.h"
#include "soil.h"
#include "GameObject.h"
#include "Collider.h"
#include <vector>
#include <set>
#include "Vector2.h"
#include <mutex> 
#include <irrKlang.h>
#include "Spawner.h"

class DrawHandler;

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

	void DeleteObject(GameObject* aObject);
	void DeleteCollider(Collider* aCollider);
public:
	void PlaySound(string soundPath);
	void PlayMusic(string musicPath);
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

	GameWorld(int argc, char** argv);
	~GameWorld();
};
#endif // !GAMEWORLD_H

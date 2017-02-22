#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GL\glut.h"
#include "soil.h"
#include "GameObject.h"
#include <vector>
#include <set>
#include "Vector2.h"
#include <mutex> 

class DrawHandler;

using namespace std;

class GameWorld
{
private:
	DrawHandler * drawHandler;
	vector<GameObject*> gameObjects;
	int oldTimeSinceStart;
	float deltaTime;
	set<int> keys;
public:
	void Update();
	void Draw();
	void CreateWorld();
	void DeleteObject(GameObject* aObject);

	DrawHandler GetDrawHandler();
	float GetDeltaTime();
	set<int> GetKeys();
	void AddKey(int i);
	void DeleteKey(int i);

	GameWorld(int argc, char** argv);
	~GameWorld();
};
#endif // !GAMEWORLD_H

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GL\glut.h"
#include "soil.h"
#include "GameObject.h"
#include <vector>
#include "Vector2.h"

class DrawHandler;

using namespace std;

class GameWorld
{
private:
	DrawHandler * drawHandler;
	vector<GameObject*> gameObjects;
	int oldTimeSinceStart;
	float deltaTime;
public:
	void Update();
	void Draw();
	void CreateWorld();
	void DeleteObject(GameObject* aObject);

	DrawHandler GetDrawHandler();
	float GetDeltaTime();

	GameWorld(int argc, char** argv);
	~GameWorld();
};
#endif // !GAMEWORLD_H

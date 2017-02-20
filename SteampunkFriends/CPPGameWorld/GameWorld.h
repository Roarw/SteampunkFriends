#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GL\glut.h"
#include "soil.h"
#include "GameObject.h"
#include <vector>

class DrawHandler;
class GameObject;

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

	DrawHandler GetDrawHandler();
	float GetDeltaTime();

	GameWorld(int argc, char** argv);
	~GameWorld();
};
#endif // !GAMEWORLD_H

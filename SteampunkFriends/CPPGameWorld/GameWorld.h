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

	GameWorld();
public:
	void Update();
	void Draw();
	void CreateWorld();

	DrawHandler GetDrawHandler();
	float GetDeltaTime();

	static GameWorld& GetInstance();
	GameWorld(GameWorld const&) = delete;
	void operator=(GameWorld const&) = delete;
	~GameWorld();
};
#endif // !GAMEWORLD_H

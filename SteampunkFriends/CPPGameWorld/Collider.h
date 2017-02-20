#pragma once
#include "Component.h"
#include "IDraw.h"
#include "RectangleF.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include <vector>

using namespace std;

class Collider :
	public Component, public IDraw
{
private:
	void CheckCollision();
	SpriteRenderer * s;
	Transform * t;
	vector<Collider*> * collisions;
public:
	Collider(GameObject * g);
	void Update();
	void Draw();
	RectangleF * CollisionBox();
	~Collider();
};


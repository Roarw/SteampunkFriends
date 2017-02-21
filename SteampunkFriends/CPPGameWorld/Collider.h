#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"
#include "IDraw.h"
#include "RectangleF.h"
#include <vector>

class SpriteRenderer;
class Transform;

using namespace std;

class Collider :
	public Component, public IDraw
{
private:
	void CheckCollision();
	SpriteRenderer * spriter;
	Transform * transform;
	vector<Collider*> collisions;
public:
	Vector2 Size;
	bool Enabled = true;
	std::string GetName();
	Collider(GameObject * g, Transform * transform, RectangleF sizeRect);
	Collider(GameObject * g, Transform * transform, SpriteRenderer * spriteRenderer);
	void Update();
	void Draw();
	RectangleF CollisionBox();
	~Collider();
};
#endif // !COLLIDER_H

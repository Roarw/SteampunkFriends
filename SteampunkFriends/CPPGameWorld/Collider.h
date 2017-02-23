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
	SpriteRenderer * spriter;
	Transform * transform;

	void CheckCollision();
public:
	vector<Collider*> collisions;
	Vector2 Size;
	bool Enabled = true;

	void Update();
	void Draw(DrawHandler* drawHandler);

	std::string GetName();
	RectangleF CollisionBox();

	Collider(GameObject * g, Transform * transform, RectangleF sizeRect);
	Collider(GameObject * g, Transform * transform, SpriteRenderer * spriteRenderer);
	~Collider();
};
#endif // !COLLIDER_H

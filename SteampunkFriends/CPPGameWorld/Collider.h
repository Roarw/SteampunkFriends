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
	Collider(GameObject * g, Transform * transform, SpriteRenderer * spriteRenderer);
	void Update();
	void Draw();
	//Return new? Hvor bliver den her nogensinde deleted?
	RectangleF * CollisionBox();
	~Collider();
};
#endif // !COLLIDER_H

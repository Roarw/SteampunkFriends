#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

#include "Vector2.h"

class Transform :
	public Component
{
private:
	Vector2 * position;
public:
	void Translate(Vector2 translation);

	Vector2 * GetPosition();
	std::string GetName();

	Transform(GameObject * gameObject, Vector2 * position);
	~Transform();
};
#endif // !TRANSFORM_H
